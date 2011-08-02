(*
 * Program Repair Prototype (v2)
 *
 * Program Representation -- binary elf executables
 *
 *)

open Elf
open Printf
open Global
open Gaussian
open Rep

(*************************************************************************
 *************************************************************************
         ELF Executables - Compiled and Linked Executable Programs
 *************************************************************************
 *************************************************************************)

let elf_sample_runs = ref 100
let elf_risc = ref false
let _ =
  options := !options @
  [
    "--elf-sample-runs",
    Arg.Set_int elf_sample_runs,
    "X Execute X runs of the test suite while sampling with oprofile.";
    "--elf-risc",
    Arg.Set elf_risc,
    " Specify that a RISC instruction set is used with fixed-width instructions."
  ]

let elfRep_version = "1"

class elfRep = object (self : 'self_type)

  inherit [string list] faultlocRepresentation as super

  val path = ref ""
  val bytes = ref [| (* array of integer bytes *) |]
  val elf = ref "" (* String to hold binary elf lisp object *)
  val offset = ref 0
  val size = ref 0

  method atom_to_str slist =
    let b = Buffer.create 255 in
    List.iter (fun s -> Printf.bprintf b "%S" s) slist ;
    Buffer.contents b

  (* make a fresh copy of this variant *)
  method copy () : 'self_type =
    let super_copy : 'self_type = super#copy () in
    super_copy#internal_copy ()

  (* being sure to update our local instance variables *)
  method internal_copy () : 'self_type =
    {<
      path = ref (Global.copy !path) ;
      offset = ref (Global.copy !offset) ;
      size = ref (Global.copy !size) ;
      bytes  = begin
        let temp = Array.make (Array.length !bytes) (Array.get !bytes 0) in
          Array.iteri (fun i el -> Array.set temp i el) !bytes;
          ref temp
      end;
      elf = elf;
    >}

  (* use objdump to find the instruction borders in this elf file *)
  method disasm (filename : string ) = begin
    let tmp = Filename.temp_file "disasm" ".objdump-output" in
    let trim str =
      if Str.string_match (Str.regexp "^[ \t]*\\([^ \t].+\\)$") str 0 then
        Str.matched_group 1 str
      else
        str in
    let read_file filename =
      let lst = ref [] in
      let fin = open_in filename in
        (try while true do
           let line = input_line fin in
             lst := line :: !lst
         done with _ -> close_in fin) ;
        List.rev !lst in
    let parse_address line =
      let bytes = ref [] in
        List.iter
          (fun str ->
             try
               bytes := (int_of_string ("0x"^str)) :: !bytes
             with Failure "int_of_string" -> ())
          (Str.split (Str.regexp "[ \t]")
             (String.sub line 10
                (if ((String.length line) > 32) then 21 else (String.length line - 10)))) ;
        ((int_of_string ("0x"^(trim (String.sub line 1 7)))), !bytes) in
    let parse_addresses lines = 
      let results = ref [] in
      let header_re = Str.regexp "^\\([0-9a-fA-F]+\\) <\\(.+\\)>:$" in
        List.iter (fun line ->
                     if (not (Str.string_match header_re line 0) &&
                           ((String.length line) > 10) &&
                           (try
                              ignore (int_of_string ("0x"^(trim (String.sub line 1 7)))) ; true
                            with Failure "int_of_string" -> false)) then
                       results := (parse_address line) :: !results) lines ;
        List.sort (fun (a,_) (b,_) -> a-b) !results in

      ignore (Unix.system ("objdump -j .text -d "^filename^">"^tmp)) ;
      let parsed = (parse_addresses (read_file tmp)) in
        (* for debugging: list the memory address of instructions with their sizes *)
        (* List.iter (fun (addr,bytes) -> debug "\t%d:%d\n" addr (List.length bytes)) parsed ; *)
        List.map (fun (_,bytes) -> List.length bytes) parsed
  end

  method bytes_of filename = begin
    let raw_bytes = ref (Array.to_list (get_text !elf)) in
      debug "raw_bytes:%d\n" (List.length !raw_bytes) ;
    let tmp_bytes = ref [] in
      if !elf_risc then
        let holder = ref [] in
          List.iter (fun a ->
                       holder := a :: !holder ;
                       if List.length !holder == 4 then begin
                         tmp_bytes := (List.rev !holder) :: !tmp_bytes ;
                           holder := []
                       end) !raw_bytes ;
          Array.of_list (List.rev !tmp_bytes)
      else
        let ins_sizes = ref (self#disasm filename) in
          Array.of_list
            (List.map
               (fun size ->
                  let tmp = ref [] in
                    for i = 1 to size do
                      tmp := (List.hd !raw_bytes) :: !tmp;
                      raw_bytes := List.tl !raw_bytes
                    done;
                    List.rev !tmp)
               !ins_sizes)
  end

  method from_source (filename : string) = begin
    path := filename;
    elf := read_elf filename;
    offset := get_text_offset !elf;
    bytes := self#bytes_of filename;
    size := List.length (List.flatten (Array.to_list !bytes));
  end

  method output_source source_name = begin
    write_w_text !elf source_name
      (Array.of_list (List.flatten (Array.to_list !bytes)));
  end

  method internal_compute_source_buffers () =
    let tmp_file =
      Filename.temp_file "internal_compute_source_buffers" ".source-hash" in
    let buffer = Buffer.create 10240 in
      self#output_source tmp_file ;
      List.iter (fun line -> Buffer.add_string buffer line)
        (get_lines tmp_file);
      (try Unix.unlink tmp_file with _ -> ());
      [ None, Buffer.contents buffer ]

  method save_binary ?out_channel (filename : string) = begin
    let fout =
      match out_channel with
      | Some(v) -> v
      | None -> open_out_bin filename
    in
    Marshal.to_channel fout (elfRep_version) [] ;
      Marshal.to_channel fout path [] ;
    super#save_binary ~out_channel:fout filename ;
    debug "elf: %s: saved\n" filename ;
    if out_channel = None then close_out fout
  end

  (* load in serialized state *)
  method load_binary ?in_channel (filename : string) = begin
    let fin =
      match in_channel with
      | Some(v) -> v
      | None -> open_in_bin filename
    in
    let version = Marshal.from_channel fin in
    if version <> elfRep_version then begin
      debug "elf: %s has old version\n" filename ;
      failwith "version mismatch"
    end ;
    debug "ERROR: can not load serialize lisp object\n" ;
    elf := exit 1;
    path := Marshal.from_channel fin ;
    elf := read_elf !path;
    offset := get_text_offset !elf;
    bytes := self#bytes_of !path;
    size := List.length (List.flatten (Array.to_list !bytes));
    super#load_binary ~in_channel:fin filename ;
    debug "elf: %s: loaded\n" filename ;
    if in_channel = None then close_in fin
  end

  method max_atom () = (Array.length !bytes) - 1

  (* convert a memory address into a genome index *)
  method atom_id_of_source_line source_file source_line =
    (* TODO: address is raw byte index, transform this into instruction index *)
    let line = source_line - !offset in
      if line < 0 || line > self#max_atom () then begin
        debug "elfrep: bad line access %d:%d\n" source_line line;
        0
      end
      else
        line

  (* convert a genome index into a memory address *)
  method source_line_of_atom_id (atom_id : int) =
    (* TODO: reverse instruction <-> byte index transformation *)
    atom_id + !offset

  method load_oracle oracle_file = 
	failwith "elf: no oracle fix localization"

  method structural_signature =
    failwith "elf: no structural differencing"

  method get_compiler_command () =
    "__COMPILER_NAME__ __SOURCE_NAME__ __EXE_NAME__ 2>/dev/null >/dev/null"


  method get_coverage coverage_sourcename coverage_exename coverage_outname =
    (* the use of two executable allows oprofile to sample the pos
     * and neg test executions separately.  *)
    let pos_exe = coverage_exename^".pos" in
      let neg_exe = coverage_exename^".neg" in
		ignore(Unix.system ("cp "^coverage_exename^" "^coverage_exename^".pos"));
		ignore(Unix.system ("cp "^coverage_exename^" "^coverage_exename^".neg"));
        for i = 1 to !elf_sample_runs do (* run the positive tests *)
          for i = 1 to !pos_tests do
            let res, _ = (self#internal_test_case pos_exe
                            coverage_sourcename (Positive i)) in
              if not res then begin
                debug "ERROR: coverage FAILS test Positive %d\n" i ;
              end ;
          done ;
          for i = 1 to !neg_tests do
            let res, _ = (self#internal_test_case neg_exe 
                            coverage_sourcename (Negative i)) in 
              if res then begin 
                (* debug "ERROR: coverage PASSES test Negative %d\n" i ; *)
              end ;
          done ;
        done ;
        (* collect the sampled results *)
        let from_opannotate sample_path =
          let regex = Str.regexp "^[ \t]*\\([0-9]\\).*:[ \t]*\\([0-9a-zA-Z]*\\):.*" in
          let res = ref [] in
          let lst = ref [] in
          let fin = open_in sample_path in
            (try while true do
               let line = input_line fin in
                 lst := line :: !lst
             done with _ -> close_in fin) ;
            List.iter
              (fun line ->
                 if (Str.string_match regex line 0) then
                   let count = int_of_string (Str.matched_group 1 line) in
                   let addr = int_of_string ("0x"^(Str.matched_group 2 line)) in
                     res := (addr, count) :: !res) !lst ;
            List.sort (fun (a,_) (b,_) -> a - b) !res in
        let filter_by_bounds (samples : (int * float) list) =
          let results = ref [] in
          let size = Array.length !bytes in
            List.iter
              (fun (addr, count) ->
                 let index = addr - !offset in
                   if (0 <= index) && (index <= size) then
                     results := (index,count) :: !results ;) samples ;
            List.sort (fun (a,_) (b,_) -> a - b) !results in
        (* let drop_to counts file path = *)
        (*   let fout = open_out path in *)
        (*     List.iter (fun (line,weight) -> *)
        (*                  Printf.fprintf fout "%s,%d,%f\n" file line weight) *)
        (*       counts ; *)
        (*     close_out fout in *)
        let drop_ids_only_to counts file path =
          let fout = open_out path in
            List.iter (fun (line,_) -> Printf.fprintf fout "%d\n" line) counts ;
            close_out fout in
        let pos_samp = pos_exe^".samp" in
        let neg_samp = neg_exe^".samp" in
          (* collect the samples *)
          if not (Sys.file_exists pos_samp) then
            ignore (Unix.system ("opannotate -a "^pos_exe^">"^pos_samp)) ;
          if not (Sys.file_exists neg_samp) then
            ignore (Unix.system ("opannotate -a "^neg_exe^">"^neg_samp)) ;
          (* get the addresses and samples, filter down to addresses in
           * the text section, and write them to the output file as
           * integers
           *)
          drop_ids_only_to (filter_by_bounds
                              (Gaussian.blur Gaussian.kernel (from_opannotate pos_samp)))
            pos_exe !fix_path ;
          drop_ids_only_to (filter_by_bounds
                              (Gaussian.blur Gaussian.kernel (from_opannotate neg_samp)))
            neg_exe !fault_path

  method instrument_fault_localization
    coverage_sourcename
    coverage_exename
    coverage_outname
    = begin
      debug "elfRep: computing fault localization information\n" ;
      debug "elfRep: ensure oprofile is running\n" ;
      debug "elfRep: this may take some time...\n" ;
      (* save the source to coverage_sourcename *)
      self#output_source coverage_sourcename ;
    end

  method debug_info () = begin
    debug "elf: lines = %d\n" (self#max_atom ());
  end

  method atom_to_byte atom = List.map int_of_string atom

  method byte_to_atom byte = List.map string_of_int byte

  method atom_length atom = List.length atom

  method get_genome () =
    List.map self#byte_to_atom (Array.to_list !bytes)

 method set_genome new_g =
    bytes := Array.of_list (List.map self#atom_to_byte new_g)

  method get ind =
    if (ind <= self#max_atom ()) then
      self#byte_to_atom (Array.get !bytes ind)
    else
      []
      
  method put ind newv =
    if (ind <= self#max_atom ()) then
      Array.set !bytes ind (self#atom_to_byte newv)

  method swap i j =
    let max = Array.length !bytes in
      if (i < max) && (j < max) then begin
        super#swap i j;
        let temp = Array.get !bytes i in
          Array.set !bytes i (Array.get !bytes j) ;
          Array.set !bytes j temp ;
      end

  method delete i =
    let max = Array.length !bytes in
      if (i < max) then begin
        super#delete i ;
        let num = List.length (Array.get !bytes i) in
        let len = Array.length !bytes in
        let rep = Array.make num (if !elf_risc then [0; 0; 160; 225] else [144]) in
          if (i == 0) then
            bytes := Array.append rep (Array.sub !bytes 1 (len - 1))
          else if (i == (len - 1)) then
            bytes := Array.append (Array.sub !bytes 0 (len - 1)) rep
          else
            bytes := Array.append
              (Array.append (Array.sub !bytes 0 i) rep)
              (Array.sub !bytes (i + 1) ((len - i) - 1)) ;
      end

  method append i j =
    let max = Array.length !bytes in
      if (i < max) && (j < max) then begin
        super#append i j ;
        let inst = ref (Array.get !bytes j) in
        let reps = ref (List.length !inst) in
          (* append new instruction into the array *)
          bytes := Array.concat [
            (Array.sub !bytes 0 i);
            [|!inst|];
            (Array.sub !bytes i ((Array.length !bytes) - i));
          ] ;
          (* delete an appropriate amount of nop's *)
          let max x y = if x > y then x else y in
            for p = 0 to max i ((Array.length !bytes) - i) do
              if (!reps > 0) then begin
                try
                  match Array.get !bytes (i+p) with
                    | [0; 0; 160; 225] when !elf_risc -> begin
                        reps := !reps - 4 ;
                        Array.set !bytes (i+p) []
                      end
                    | [144] when (not !elf_risc) -> begin
                        reps := !reps - 1 ;
                        Array.set !bytes (i+p) []
                      end
                    | _     -> begin
                        match Array.get !bytes (i-p) with
                          | [0; 0; 160; 225] when !elf_risc -> begin
                              reps := !reps - 4 ;
                              Array.set !bytes (i-p) []
                            end
                          | [144] when (not !elf_risc) -> begin
                              reps := !reps - 1 ;
                              Array.set !bytes (i-p) []
                            end
                          | _ -> ()
                      end
                with
                  | Invalid_argument  "index out of bounds" -> ()
                  | Invalid_argument  "Array.sub" -> ()
              end
            done ;
            (* if still too long, then truncate *)
            if (!reps > 0) then
              bytes := Array.sub !bytes 0 ((Array.length !bytes) - !reps) ;
            (* remove empty instruction strings *)
            bytes := Array.of_list
              (List.rev (Array.fold_left
                           (fun a e -> match e with
                              | [] -> a
                              | _  -> e :: a)
                           [] !bytes)) ;
      end

end
