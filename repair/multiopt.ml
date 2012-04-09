(** Multiopt provides multi-objective search strategies.  Currently implements
    NSGA-II, based on:
    http://www.mathworks.com/matlabcentral/fileexchange/10429-nsga-ii-a-multi-objective-optimization-algorithm*)

(* Note: CLG did not write this and has made minimal effort to understand it.  I
   did, however, reformat a lot to get everything closer to 80 characters per
   line; the use of the imperative style in this module combined with OCaml's
   standard indentation practices meant that basically everything was shifted
   really far to the right by the time we got to step 3.3 of the algorithm.  I
   thus do a lot of let _ = imperative computation in, trying to break up the
   computation into the steps suggested by the algorithm.  This is only in the
   interest of readability *)

open Printf
open Global
open Fitness
open Rep
open Population

let minimize = ref false 
let no_inf = ref false 
let num_objectives = ref 2  (* number of objectives *) 
let _ = 
  options := !options @ [
  "--multiopt-minimize", Arg.Set minimize, " minimize multiopt objective";

  "--multiopt-no-inf", Arg.Set no_inf, " avoid infinite values";

  "--num-objectives", Arg.Set_int num_objectives, "X expect X objective values";
] 

let evaluate (rep : ('a,'b) representation) = 
  let _, values = rep#test_case (Single_Fitness) in 
    if Array.length values < !num_objectives then begin
      if !minimize then 
        Array.make !num_objectives infinity 
      else 
        Array.make !num_objectives neg_infinity 
    end else values 

let is_pessimal arr = 
  if !minimize then 
    arr = Array.make !num_objectives infinity 
  else 
    arr = Array.make !num_objectives neg_infinity 

(*************************************************************************
 *************************************************************************
                                  NGSA-II
 *************************************************************************
 *************************************************************************)


let dominates (p: ('a, 'b) Rep.representation) 
    (q: ('a, 'b) Rep.representation) : bool =
  let p_values = evaluate p in 
  let q_values = evaluate q in 
    assert(Array.length p_values = Array.length q_values) ; 
    let better = ref 0 in
    let same = ref 0 in
    let worse = ref 0 in 
      for i = 0 to pred (Array.length p_values) do
        if p_values.(i) > q_values.(i) then 
          (if !minimize then incr worse else incr better)
        else if p_values.(i) = q_values.(i) then
          incr same
        else
          (if !minimize then incr better else incr worse)
      done ;
      if !worse > 0 then false
      else if !better >0 then true
      else false 

let rephash_replace h x y = Hashtbl.replace h (x#name ()) (y) 
let rephash_add h x y = Hashtbl.add h (x#name ()) (y) 
let rephash_find h x = Hashtbl.find h (x#name ())  
let rephash_find_all h x = Hashtbl.find_all h (x#name ())  
let rephash_mem h x = Hashtbl.mem h (x#name ())  

let rec ngsa_ii (original : ('a,'b) Rep.representation) (incoming_pop) 
    : ('a,'b) GPPopulation.t =

  debug "multiopt: ngsa_ii begins (%d generations left)\n" !Search.generations;

  let current = ref incoming_pop in 
    for gen = 1 to !Search.generations do
      let _ = 
        debug "multiopt: ngsa_ii generation %d begins\n" gen 
      in
      let is_last_generation = gen = !Search.generations in 
      let next_generation = 
        ngsa_ii_internal original !current ~is_last_generation in 
      let filename = Printf.sprintf "generation-%04d.list" gen in 
      let _ = 
        debug "multiopt: printing %s\n" filename 
      in
      let fout = open_out filename in 
        List.iter (fun var ->
          let names = var#source_name in
          let rec handle names = 
            match names with
            | [] -> ()
            | [one] -> Printf.fprintf fout "%s\n" one
            | first :: rest -> 
              Printf.fprintf fout "%s," first ;
              handle rest
          in
            handle names ; 
        ) next_generation ;
        close_out fout ; 
        current := next_generation 
    done ;
    debug "multiopt: ngsa_ii end\n" ;
    !current

and ngsa_ii_internal 
    ?(is_last_generation=false) (original) incoming_pop =

  (* Step numbers follow Seshadri's paper *)

  (****** 3.1. Population Initialization ******)
  let pop = 
    match incoming_pop with
      [] -> begin
        debug "multiopt: generating initial population\n" ; 
        let pop = ref [original#copy ()] in (* our GP population *) 
          for i = 1 to pred !Population.popsize do
          (* initialize the population to a bunch of random mutants *) 
            pop := (Search.mutate original) :: !pop 
          done ;
          !pop
      end
    | _ -> 
      (debug "multiopt: using previous population\n" ; incoming_pop)
  in 

  let ngsa_ii_sort pop = begin
    let _ = 
      debug "multiopt: beginning sort\n" ; 
      Gc.compact()
    in

    let f_max = Hashtbl.create 255 in
    let f_min = Hashtbl.create 255 in 
    let adjust_f_max m v =
      let sofar = try Hashtbl.find f_max m with _ -> neg_infinity in
        Hashtbl.replace f_max m (max sofar v)
    in
    let adjust_f_min m v = 
      let sofar = try Hashtbl.find f_min m with _ -> infinity in
        Hashtbl.replace f_min m (min sofar v)
    in

    let _ =
      debug "multiopt: computing f_max and f_min %d \n"  (List.length pop)
    in

    let _ =
      List.iter (fun p ->
        let p_values = evaluate p in 
          Array.iteri (fun m fval ->
            adjust_f_max m fval ; 
            adjust_f_min m fval ; 
          ) p_values ;
      ) pop ; 
      for m = 0 to pred !num_objectives do
        debug "multiopt: %g <= objective %d <= %g\n" 
          (Hashtbl.find f_min m) m (Hashtbl.find f_max m)
      done 
    in

    (****** 3.2. Non-Dominated Sort ******)
    let _ =
      debug "multiopt: first non-dominated sort begins\n" 
    in
    let dominated_by = hcreate 255 in 
    let dominated_by_count = hcreate 255 in 
    let rank = hcreate 255 in 
    let delta_dominated_by_count (p:('a,'b) Rep.representation) dx =
      let sofar = rephash_find dominated_by_count p in
        rephash_replace dominated_by_count p (sofar + dx)
    in 
    let f = Hashtbl.create 255 in 

    let _ =
      List.iter (fun (p : ('a,'b) Rep.representation) ->
        rephash_replace dominated_by_count p 0;
        List.iter (fun (q : ('a,'b) Rep.representation)->
          let str = 
            if dominates p q then begin 
              rephash_add dominated_by p q ;
              ">" 
            end else if dominates q p then begin 
              delta_dominated_by_count p 1 ;
              "<" 
            end else "=" 
          in 
            ignore str
        ) pop ; 
        if rephash_find dominated_by_count p = 0 then begin
          Hashtbl.add f 1 p ;
          rephash_replace rank p 1 ; 
        end 
      ) pop 
    in
      
    let i = ref 1 in 
    let _ = 
      while Hashtbl.mem f !i do
        let set_q_names = Hashtbl.create 255 in 
        let set_q_reps = ref [] in 
        let f_i = Hashtbl.find_all f !i in 
          
        let _ = 
          debug "multiopt: front i=%d (%d members)\n" !i (List.length f_i)
        in
          List.iter (fun p -> 
            let s_p = rephash_find_all dominated_by p in 
              List.iter (fun q ->
                delta_dominated_by_count q (-1) ; 
                let n_q = rephash_find dominated_by_count q in 
                  if n_q = 0 then begin
                    rephash_replace rank q (!i + 1) ;
                    if not (Hashtbl.mem set_q_names (q#name ())) then 
                      begin
                        Hashtbl.add set_q_names (q#name ()) true ;
                        set_q_reps := q :: !set_q_reps 
                      end
                  end 
              ) s_p 
          ) f_i ;
          incr i ; 
          List.iter (fun q ->
            Hashtbl.add f !i q
          ) !set_q_reps
      done 
    in

    let i_max = !i in 
    let _ = 
      List.iter (fun p ->
        if not (rephash_mem rank p) then begin
          rephash_replace rank p i_max ;
          let p_values = evaluate p in 
            if not (is_pessimal p_values) then begin 
              let n_p = rephash_find dominated_by_count p in 
                debug "multiopt: NO RANK for %s %s n_p=%d: setting to %d\n" 
                  (p#name ()) (float_array_to_str p_values) n_p i_max
            end 
        end
      ) pop
    in

    (****** 3.3. Crowding Distance ******)
    let distance = hcreate 255 in 
    let add_distance p delta = 
      let sofar = rephash_find distance p in
        rephash_replace distance p (sofar +. delta)
    in 
    let _ = 
      debug "multiopt: crowding distance calculation\n" 
    in
    let _ =
      for i = 1 to pred i_max do
        let n = Hashtbl.find_all f i in
          List.iter (fun p ->
            rephash_replace distance p 0.0 ;
          ) n ;
          for m = 0 to pred !num_objectives do
            let i_set = List.sort (fun a b -> 
              let a_values = evaluate a in 
              let b_values = evaluate b in 
                compare a_values.(m) b_values.(m) 
            ) n in 
            let i_array = Array.of_list i_set in 
            let i_size = Array.length i_array in
              assert(i_size > 0); 
              rephash_replace distance i_array.(0) infinity ; 
              rephash_replace distance i_array.(pred i_size) infinity ; 
              for k = 1 to pred (pred i_size) do
                let k_plus_1 = i_array.(k+1) in 
                let k_minus_1 = i_array.(k-1) in 
                let k_plus_1_values = evaluate k_plus_1 in 
                let k_minus_1_values = evaluate k_minus_1 in 
                let f_max_m = Hashtbl.find f_max m in 
                let f_min_m = Hashtbl.find f_min m in 
                  add_distance i_array.(k) 
                    ( 
                      (abs_float (k_plus_1_values.(m) -. k_minus_1_values.(m)))
                      /.
                        (f_max_m -. f_min_m)
                    )
              done 
          done 
      done 
    in
      
    (****** 3.4. Selection ******)
    let _ =
        debug "multiopt: computing selection operator\n" 
    in
    let crowded_lessthan p q = 
      (* "An individual is selected if the rank is lesser than the other or
         if crowding distance is greater than the other" *)
      let p_rank = rephash_find rank p in 
      let q_rank = rephash_find rank q in 
        if p_rank < q_rank then
          true
        else if p_rank = q_rank then begin
          let p_dist = rephash_find distance p in 
          let q_dist = rephash_find distance q in 
            compare p_dist q_dist = 1 
        end else false 
    in 
      crowded_lessthan, f, distance
  end (* end ngsa_ii_sort *)
  in

  let crowded_lessthan, f, distance = ngsa_ii_sort pop in 

  let _ = 
    debug "multiopt: crossover and mutation\n" 
  in

  (* crossover, mutate *) 
  let children = ref [] in 
  let _ = 
    for j = 1 to !Population.popsize do
      let parents = GPPopulation.tournament_selection pop 
        ~compare_func:(fun a b -> 
          if crowded_lessthan a b then -1 
          else if crowded_lessthan b a then 1 else 0) 2
      in
        match parents with
        | [ one ; two ] ->
          let kids =  GPPopulation.do_cross original one two in 
          let kids = List.map (fun kid -> 
            Search.mutate kid 
          ) kids in 
            children := kids @ !children 
        | _ -> debug "multiopt: wrong number of parents (fatal)\n" 
    done 
  in

  let _ = 
    debug "multiopt: adding children, sorting\n" 
  in

  let many = pop @ !children in 
  let crowded_lessthan, f, distance = ngsa_ii_sort many in 

    if is_last_generation then begin 
      let f_1 = Hashtbl.find_all f 1 in
      let i = ref 0 in 
      let _ = 
        debug "\nmultiopt: %d in final generation pareto front:\n(does not include all variants considered)\n\n" 
          (List.length f_1) 
      in
      let f_1 = List.sort (fun p q ->
        let p_values = evaluate p in 
        let q_values = evaluate q in 
          compare p_values q_values
      ) f_1 in 
      let _ = 
        List.iter (fun p ->
          let p_values = evaluate p in 
          let name = Printf.sprintf "pareto-%06d.%s" !i 
            (!Global.extension) in 
          let fname = Printf.sprintf "pareto-%06d.fitness" !i in 
            incr i; 
            p#output_source name ; 
            let fout = open_out fname in 
              output_string fout (float_array_to_str p_values) ;
              output_string fout "\n" ; 
              close_out fout ; 
              debug "%s %s\n %s\n\n" name 
                (float_array_to_str p_values) 
                (p#name ()) 
        ) f_1 
      in 
        f_1 
    end else begin 
      let next_generation = ref [] in 
      let finished = ref false in 
      let front_idx = ref 1 in 

      let _ = 
        while not !finished do
          let indivs_in_front = Hashtbl.find_all f !front_idx in 
          let indivs_in_front =
            let do_not_want = if !minimize then infinity else 0.  in 
              if !no_inf then 
                List.filter (fun p ->
                  let p_values = evaluate p in 
                    List.for_all (fun v ->
                      v <> do_not_want 
                    ) (Array.to_list p_values) 
                ) indivs_in_front
              else 
                indivs_in_front
          in 
          let num_indivs = List.length indivs_in_front in 
          let _ = 
            debug "multiopt: %d individuals in front %d\n" num_indivs !front_idx 
          in
          let have_sofar = List.length !next_generation in 
          let _ = 
            finished := have_sofar + num_indivs >= !Population.popsize 
          in
          let to_add = 
            if have_sofar + num_indivs <= !Population.popsize then
              (* we can just take them all! *) 
              indivs_in_front 
            else begin
              (* sort by crowding distance *) 
              let sorted = List.sort (fun a b -> 
                compare (rephash_find distance a) (rephash_find distance b)
              ) indivs_in_front in 
              let num_wanted = !Population.popsize - have_sofar in 
              let selected = first_nth sorted num_wanted in 
                selected 
            end 
          in
          let _ = incr front_idx in
            if not !finished && num_indivs = 0 then begin
              let wanted = !Population.popsize - have_sofar in 
              let _ =
                debug "multiopt: including %d copies of original\n" wanted 
              in
                for i = 1 to wanted do
                  next_generation := (original#copy ()) :: !next_generation 
                done ;
                finished := true 
            end ; 
            next_generation := to_add @ !next_generation 
        done 
      in
      let _ = 
        debug "multiopt: next generation has size %d\n" (llen !next_generation)
      in
        !next_generation 
    end 


