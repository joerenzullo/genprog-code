open Batteries
open Set
open Utils
open Map
open Cabsvisit
open Cabswalker
open Diffs
open Difftypes
open Treediff
open Cfg
open Pdg
open Datapoint
module C=Cabs

let vector_hash = hcreate 10

let hfind ht key msg = ht_find ht key (fun _ -> failwith msg)

(* OK, what are the interesting nodes for cabs? *)
(* everything rooted at statement, including expressions?  I think so. *)

type tIndex = { 
	  typedef : int;
      cv_const : int;
	  cv_volatile : int;
	  cv_restrict : int;
	  attribute : int;
      no_storage : int;
	  auto : int;
	  static : int;
	  extern : int;
	  register : int;
	  inline : int;
	  pattern : int;
      tvoid : int;
	  tchar : int;
	  tshort : int;
	  tint : int;
	  tlong : int;
	  tint64 : int;
	  tfloat : int;
	  tdouble : int;
	  tsigned : int;
	  tunsigned : int;
	  tnamed : int;
	  tsum : int;
	  tstruct : int;
	  tunion : int;
	  tenum : int;
	  ttypeof : int;
	  exprop : int;
	  typeop : int;

(* decl_type type information *)
	  parentype : int;
	  arraytype : int;
	  ptr : int;
	  proto : int;

	  (* general node type; primarily for changes *)
	  expression : int;
	  statement : int;
	  definition : int;

	  (* change vector info *)
	  insertion : int;
	  reorder : int;
	  move : int;
	  deletion : int;
	  def_parent : int;
	  stmt_parent : int;
	  exp_parent : int;
	  loop_guard : int;
	  cond_guard : int;
	  catch_guard : int;
	  case_guard : int;

	  (* statement vector info *)
	  if_ind : int;
	  loop : int;
	  while_ind : int;
	  dowhile_ind : int;
	  for_ind : int;
	  loop_mod : int;
	  break : int;
	  continue : int;
	  return : int;
	  switch : int;
	  case : int;
	  default : int;
	  label : int;
	  goto : int;
	  asm : int;
	  trystmt : int;
	  except : int;
	  finally : int;

	  (* expression vector info *)
	  unary : int;
	  binary : int;
	  bitwise : int;
	  plus : int;
	  minus : int;
	  multiply : int;
	  divide : int;
	  modop : int;
	  andop : int;
	  orop : int;
	  xorop : int;
	  shift : int;
	  left : int;
	  right : int;
	  assign : int;
	  equal : int;
	  notop : int;
	  less_than : int;
	  greater_than : int;
	  addr : int;
	  post : int;
	  pre : int;
	  incr : int;
	  decr : int;
	  question : int;
	  cast : int;
	  call : int;
	  comma : int;
	  constant : int;
	  paren : int;
	  variable : int;
	  sizeof : int;
	  alignof : int;
	  index : int;
	  memberof : int;
	}

let i = 
  {
	  typedef=0;
      cv_const=1;
	  cv_volatile=2;
	  cv_restrict=3;
	  attribute=4;
      no_storage=5;
	  auto=6;
	  static=7;
	  extern=8;
	  register=9;
	  inline=10;
	  pattern=11;
      tvoid=12;
	  tchar=13;
	  tshort=14;
	  tint=15;
	  tlong=16;
	  tint64=17;
	  tfloat=18;
	  tdouble=19;
	  tsigned=20;
	  tunsigned=21;
	  tnamed=22;
	  tsum=23;
	  tstruct=24;
	  tunion=25;
	  tenum=26;
	  ttypeof=27;
	  exprop=28;
	  typeop=29;

(* decl_type type information *)
	  parentype=30;
	  arraytype=31;
	  ptr=32;
	  proto=33;

	  (* general node type; primarily for changes *)
	  expression=34;
	  statement=35;
	  definition=36;

	  (* change vector info *)
	  insertion=37;
	  reorder=38;
	  move=39;
	  deletion=40;
	  def_parent=41;
	  stmt_parent=42;
	  exp_parent=43;
	  loop_guard=44;
	  cond_guard=45;
	  case_guard=46;
	  catch_guard=47;

	  (* statement vector info *)
	  if_ind=48;
	  loop=49; (* FIXME NUMBERS *)
	  while_ind=48;
	  dowhile_ind=49;
	  for_ind=50;
	  loop_mod=51;
	  break=52;
	  continue=53;
	  return=54;
	  switch=55;
	  case=56;
	  default=57;
	  label=58;
	  goto=59;
	  asm=60;
	  trystmt=61;
	  except=62;
	  finally=63;

	  (* expression vector info *)
	  unary=64;
	  binary=65;
	  bitwise=66;
	  plus=67;
	  minus=68;
	  multiply=69;
	  divide=70;
	  modop=71;
	  andop=72;
	  orop=73;
	  xorop=74;
	  shift=75;
	  left=76;
	  right=77;
	  assign=78;
	  equal=79;
	  notop=80;
	  less_than=81;
	  greater_than=82;
	  addr=83;
	  post=84;
	  pre=85;
	  incr=86;
	  decr=87;
	  question=88;
	  cast=89;
	  call=90;
	  comma=91;
	  constant=92;
	  paren=93;
	  variable=94;
	  sizeof=95;
	  alignof=96;
	  index=97;
	  memberof=98;
}

let max_size = 99

(* we need to do everything in postorder *)
let array_incr array index =
  let currval = array.(index) in
	Array.set array index (currval + 1)
	     
let array_sum array1 array2 = (* for each i in array1, array1.(i) = array1.(i) + array2.(i) *)
  Array.iteri
	(fun index ->
	  fun val1 -> 
		Array.set array1 index (array1.(index) + array2.(index))) array1; array1
  
class vectorGenWalker = object(self)
  inherit [int Array.t ] singleCabsWalker

  method default_res () = Array.make max_size 0
  method combine array1 array2 = array_sum array1 array2
  method wDeclType dt = 
	let dt_array = Array.make max_size 0 in
	let incr = array_incr dt_array in 
	  (match dt with
	  | C.PARENTYPE _ -> incr i.parentype
	  | C.ARRAY _ -> incr i.arraytype
	  | C.PTR _ -> incr i.ptr
	  | C.PROTO _ -> incr i.proto
	  | _ -> ()); CombineChildren(dt_array)
  (* Prints "decl (args[, ...])".
   * decl is never a PTR.*)

  method wExpression exp =
	if not (hmem vector_hash (IntSet.singleton(exp.C.id))) then begin
	  let exp_array = Array.make max_size 0 in
	  let incr = array_incr exp_array in
		incr i.expression;
		(match C.dn exp with
		| C.UNARY(uop,exp1) -> 
		  incr i.unary;
		  (match uop with
		  | C.MINUS -> incr i.minus
		  | C.PLUS -> incr i.plus 
		  | C.NOT -> incr i.notop
		  | C.BNOT -> incr i.notop; incr i.bitwise
		  | C.MEMOF -> incr i.ptr 
		  | C.ADDROF -> incr i.addr
		  | C.PREINCR -> incr i.assign; incr i.pre; incr i.incr ; incr i.plus
		  | C.PREDECR -> incr i.assign; incr i.pre; incr i.decr ; incr i.minus
		  | C.POSINCR -> incr i.assign; incr i.post; incr i.incr; incr i.plus
		  | C.POSDECR -> incr i.assign; incr i.post; incr i.decr ; incr i.minus)
		| C.BINARY(bop,exp1,exp2) ->
		  incr i.binary;
		  (match bop with 
		  | C.ADD -> incr i.plus
		  | C.SUB -> incr i.minus
		  | C.MUL -> incr i.multiply
		  | C.DIV -> incr i.divide
		  | C.MOD -> incr i.modop
		  | C.AND -> incr i.andop
		  | C.OR -> incr i.orop
		  | C.BAND -> incr i.bitwise; incr i.andop
		  | C.BOR -> incr i.bitwise; incr i.orop
		  | C.XOR -> incr i.xorop
		  | C.SHL -> incr i.bitwise; incr i.shift; incr i.left
		  | C.SHR -> incr i.bitwise; incr i.shift; incr i.right
		  | C.EQ -> incr i.equal
		  | C.NE -> incr i.notop; incr i.equal
		  | C.LT -> incr i.less_than
		  | C.GT -> incr i.greater_than
		  | C.LE -> incr i.less_than; incr i.equal
		  | C.GE -> incr i.greater_than; incr i.equal
		  | C.ASSIGN -> incr i.assign 
		  | C.ADD_ASSIGN -> incr i.assign; incr i.plus
		  | C.SUB_ASSIGN -> incr i.assign; incr i.minus
		  | C.MUL_ASSIGN -> incr i.assign; incr i.multiply 
		  | C.DIV_ASSIGN -> incr i.assign; incr i.divide 
		  | C.MOD_ASSIGN -> incr i.assign; incr i.modop 
		  | C.BAND_ASSIGN -> incr i.bitwise; incr i.assign; incr i.andop
		  | C.BOR_ASSIGN -> incr i.bitwise; incr i.assign; incr i.orop
		  | C.XOR_ASSIGN -> incr i.bitwise; incr i.assign; incr i.xorop
		  | C.SHL_ASSIGN -> incr i.bitwise; incr i.assign; incr i.shift; incr i.left
		  | C.SHR_ASSIGN -> incr i.bitwise; incr i.assign; incr i.shift; incr i.right)
		| C.LABELADDR(str) -> incr i.addr; incr i.label
		| C.QUESTION(exp1,exp2,exp3) -> incr i.question
		| C.CAST((spec,dt),ie) -> incr i.cast
		| C.CALL(exp,elist) -> incr i.call
		| C.CONSTANT(const) -> incr i.constant
		| C.VARIABLE(str) -> incr i.variable
		| C.EXPR_SIZEOF(exp) -> incr i.sizeof; incr i.exprop
		| C.TYPE_SIZEOF(spec,dt) -> incr i.sizeof; incr i.typeop
		| C.EXPR_ALIGNOF(exp) -> incr i.alignof; incr i.exprop
		| C.TYPE_ALIGNOF(spec,dt) -> incr i.alignof; incr i.typeop
		| C.INDEX(e1,e2) -> incr i.index
		| C.MEMBEROF(exp,str) -> incr i.memberof
		| C.MEMBEROFPTR(exp,str) -> incr i.memberof; incr i.ptr
		| C.EXPR_PATTERN(str) -> incr i.variable; incr i.exprop; incr i.pattern;
		| _ -> ());
		ChildrenPost(fun child_arrays -> 
					   let exp_array = array_sum exp_array child_arrays in
						 hadd vector_hash (IntSet.singleton(exp.C.id)) exp_array;
						 pprintf "vector for exp: %d --> %s: \n" exp.C.id (Cfg.exp_str exp);
						 pprintf "%s\n" ("[" ^ (Array.fold_lefti (fun str -> fun index -> fun ele -> str ^ (Printf.sprintf "(%d:%d) " index ele)) "" exp_array) ^ "]");
						 pprintf "\n";
						 exp_array)
	end else Result(hfind vector_hash (IntSet.singleton(exp.C.id)) "one")

  method wStatement stmt =
	if not (hmem vector_hash (IntSet.singleton (stmt.C.id))) then begin
	  let stmt_array = Array.make max_size 0 in 
	  let incr = array_incr stmt_array in
		incr i.statement;
		(match C.dn stmt with 
		| C.IF _ -> incr i.if_ind
		| C.WHILE _ -> incr i.loop; incr i.while_ind
		| C.DOWHILE _ -> incr i.loop; incr i.dowhile_ind
		| C.FOR _ -> incr i.loop; incr i.for_ind
		| C.BREAK _ -> incr i.break; incr i.loop_mod
		| C.CONTINUE _ -> incr i.continue; incr i.loop_mod
		| C.RETURN _ -> incr i.return
		| C.SWITCH _ -> incr i.switch
		| C.CASE _ -> incr i.case; incr i.label
		| C.CASERANGE _ -> incr i.case; incr i.label
		| C.DEFAULT _ -> incr i.default; incr i.label
		| C.LABEL _ -> incr i.label
		| C.GOTO _ -> incr i.goto
		| C.COMPGOTO _ -> incr i.goto; incr i.exprop
		| C.ASM _ ->  incr i.asm
		| C.TRY_EXCEPT _ -> incr i.trystmt; incr i.except
		| C.TRY_FINALLY _ -> incr i.trystmt; incr i.except
		| _ -> ()
		);
		ChildrenPost(fun child_arrays -> 
					   let stmt_array = array_sum stmt_array child_arrays in
						 hadd vector_hash (IntSet.singleton(stmt.C.id)) stmt_array;
						 pprintf "vector for stmt: %d --> %s: \n" stmt.C.id (Cfg.stmt_str stmt);
						 pprintf "%s\n" ("[" ^ (Array.fold_lefti (fun str -> fun index -> fun ele -> str ^ (Printf.sprintf "(%d:%d) " index ele)) "" stmt_array) ^ "]");
						 pprintf "\n";
						 stmt_array)
	end else Result(hfind vector_hash (IntSet.singleton(stmt.C.id)) "two")

  method wDefinition def = 
	if not (hmem vector_hash (IntSet.singleton (def.C.id))) then begin
	  let def_array = Array.make max_size 0 in
	  let incr = array_incr def_array in 
		incr i.definition; 
		ChildrenPost((fun array -> 
		  pprintf "vector for def: %d --> %s: \n" def.C.id (Cfg.def_str def);
		  pprintf "%s\n" ("[" ^ (Array.fold_lefti (fun str -> fun index -> fun ele -> str ^ (Printf.sprintf "(%d:%d) " index ele)) "" array) ^ "]");
		  hadd vector_hash (IntSet.singleton(def.C.id)) array; array))
	end else Result(hfind vector_hash (IntSet.singleton(def.C.id)) "three" )

  method wTypeSpecifier ts = 
	let ts_array = Array.make max_size 0 in
	let incr = array_incr ts_array in
	  (match ts with 
		C.Tvoid -> incr i.tvoid
	  | C.Tchar -> incr i.tchar
	  | C.Tshort -> incr i.tshort
	  | C.Tint -> incr i.tint
	  | C.Tlong -> incr i.tlong
	  | C.Tint64 -> incr i.tint64
	  | C.Tfloat -> incr i.tfloat 
	  | C.Tdouble -> incr i.tdouble 
	  | C.Tsigned -> incr i.tsigned
	  | C.Tunsigned -> incr i.tunsigned
	  | C.Tnamed _ -> incr i.tnamed 
	  | C.Tstruct _ -> incr i.tsum; incr i.tstruct
	  | C.Tunion _ -> incr i.tsum; incr i.tunion
	  | C.Tenum _ -> incr i.tsum ; incr i.tenum
	  | C.TtypeofE _ -> incr i.ttypeof; incr i.exprop
	  | C.TtypeofT _ -> incr i.ttypeof; incr i.typeop); CombineChildren(ts_array)

  method wSpecElem se = 
	let se_array = Array.make max_size 0 in
	let incr = array_incr se_array in
	  (match se with
		C.SpecTypedef -> incr i.typedef
	  | C.SpecCV(C.CV_CONST) -> incr i.cv_const
	  | C.SpecCV(C.CV_VOLATILE) -> incr i.cv_volatile
	  | C.SpecCV(C.CV_RESTRICT) -> incr i.cv_restrict
	  | C.SpecStorage(C.NO_STORAGE) -> incr i.no_storage
	  | C.SpecStorage(C.AUTO) -> incr i.auto
	  | C.SpecStorage(C.STATIC) -> incr i.static
	  | C.SpecStorage(C.EXTERN) -> incr i.extern
	  | C.SpecStorage(C.REGISTER) -> incr i.register
	  | C.SpecInline -> incr i.inline
	  | C.SpecPattern _ -> incr i.pattern
	  | _ -> ()
	  ); CombineChildren(se_array)

  method wAttribute attr = 
	let attr_array = Array.make max_size 0 in
	  array_incr attr_array i.attribute;
	  CombineChildren(attr_array)
end


let rec process_nodes sets window emitted =
  let emit () = 
	let set,array =
	  lfoldl
		(fun (sets,arrays) ->
		  fun (set,array) ->
			IntSet.union sets set,array_sum arrays array) (IntSet.empty,Array.make max_size 0) window in
	  hadd vector_hash set array; set,array
  in
  match sets with
	set :: sets ->
	  let setstr = IntSet.fold ( fun d -> fun str -> str^(Printf.sprintf "%d," d)) set "" in
	  let array = hfind vector_hash set ("set:"^setstr) in
	  let emitted,window = 
		if (llen window) == 3 then (emit()::emitted, List.tl window)
		else emitted,window
	  in
		process_nodes sets ((set,array) :: window) emitted
  | _ -> if (llen window) == 3 then emit() :: emitted else emitted 

let rec full_merge sets =
  let processed = process_nodes sets [] [] in
  let sets,arrays = List.split processed in 
	if (llen processed) >= 3 then arrays @ (full_merge sets)
	else arrays

class mergeWalker = object(self)
  inherit [int Array.t list] singleCabsWalker

  method default_res () = []
  method combine one two = one @ two

  method wExpression exp = 
	match exp.C.node with
	  C.MODSITE _ -> Result([])
	| C.NODE(node) -> begin
	  match node with
	  | C.CALL(exp,elist) ->
		let exps = lmap (fun exp -> IntSet.singleton exp.C.id) (exp::elist) in (* FIXME: do I really intend that cons? *)
		  CombineChildren(full_merge exps)
	  | C.COMMA(elist) ->
		let exps = lmap (fun exp -> IntSet.singleton exp.C.id) elist in
		  CombineChildren(full_merge exps)
	  | _ -> Children
	end

  method wBlock block = 
	let stmts = lmap (fun stmt -> IntSet.singleton stmt.C.id) block.C.bstmts in
	  CombineChildren(full_merge stmts)

  method wDefinition def =
	match def.C.node with
	  C.MODSITE _ -> Result([])
	| C.NODE(node) -> begin
	  match node with
	  | C.LINKAGE(_,_,dlist) -> (* FIXME: do we care about specifiers and such?  How is "adjacent" defined? *)
		let sets = lmap (fun def -> IntSet.singleton def.C.id) dlist in
		  CombineChildren(full_merge sets)
	  | _ -> Children
	end 

end

let vector_gen = new vectorGenWalker
let merge_gen = new mergeWalker

let guard_array (guard,exp) = 
  let guard_array = Array.make max_size 0 in
  let incr = array_incr guard_array in
	(match guard with
	| LOOP -> incr i.loop_guard
	| EXPG -> incr i.cond_guard
	| CATCH -> incr i.catch_guard
	| CASEG -> incr i.case_guard
	| _ -> failwith "Unhandled lifted guard in guard_array");
	let exp_array = array_sum (Array.copy (vector_gen#walkExpression exp)) guard_array in
	let arrays = lmap (fun array -> array_sum (Array.copy array) guard_array) (merge_gen#walkExpression exp) in
	  exp_array :: arrays

let change_array (id,change) =
  let change_array = Array.make max_size 0 in
  let incr = array_incr change_array in
  let parent_type = function 
	| PDEF -> i.def_parent
	| PSTMT -> i.stmt_parent | PEXP -> i.exp_parent
	| LOOPGUARD -> i.loop_guard
	| CONDGUARD -> i.cond_guard 
	| _ -> failwith "Unhandled parent type in change_vectors"
  in
  let get_arrays func1 func2 ele =
	let ast_array = array_sum (Array.copy (func1 ele)) change_array in
	let arrays = 
	  lmap (fun array -> array_sum (Array.copy array) change_array) (func2 ele)
	in
	  ast_array :: arrays
  in
  let def_arrays def = 
	get_arrays vector_gen#walkDefinition merge_gen#walkDefinition def
  in
  let stmt_arrays stmt =
	get_arrays vector_gen#walkStatement merge_gen#walkStatement stmt
  in
  let exp_arrays exp = 
	get_arrays vector_gen#walkExpression merge_gen#walkExpression exp

  in
	(* FIXME: maybe eliminate reorder in favor of Move? Or move with some
	   signifier of the level/how far to move? *)
	match change with 
	| InsertDefinition(def,_,_,par) ->
	  incr i.insertion; incr (parent_type par); incr i.definition;
	  def_arrays def
	| MoveDefinition(def,_,_,_,par1,par2) ->
	  incr i.move; incr (parent_type par1); incr (parent_type par2); incr i.definition;
	  def_arrays def
	| ReorderDefinition(def,_,_,_,par) ->
	  def_arrays def
	| DeleteDef(def,_,ptyp) -> 
	  incr i.deletion; incr i.definition; incr (parent_type ptyp); 
	  def_arrays def
	| InsertStatement(stmt,_,_,par) ->
	  incr i.insertion; incr (parent_type par); incr i.statement;
	  stmt_arrays stmt
	| MoveStatement(stmt,_,_,_,par1,par2) ->
	  incr i.move; incr (parent_type par1); incr (parent_type par2); incr i.statement;
	  stmt_arrays stmt
	| ReorderStatement(stmt,_,_,_,par) ->
	  incr i.reorder; incr (parent_type par); incr i.statement;
	  stmt_arrays stmt
	| DeleteStmt(stmt,_,ptyp) -> 
	  incr i.deletion; incr i.statement; incr (parent_type ptyp); 
	  stmt_arrays stmt
	| InsertExpression(exp,_,_,par) ->
	  incr i.insertion; incr (parent_type par); incr i.expression;
	  exp_arrays exp
	| MoveExpression(exp,_,_,_,par1,par2) ->
	  incr i.move; incr (parent_type par1); incr (parent_type par2); incr i.expression;
	  exp_arrays exp
	| ReorderExpression(exp,_,_,_,par) ->
	  incr i.reorder; incr (parent_type par); incr i.expression;
	  exp_arrays exp
	| DeleteExp(exp,_,ptyp) -> 
	  incr i.deletion; incr i.expression; incr (parent_type ptyp); 
	  exp_arrays exp
	| _ -> failwith "Unhandled edit type in change_vectors"


let mu (subgraph : Pdg.subgraph) = 
  (* this does both imaging and collection of vectors *)
  let cfg = lmap (fun p -> p.Pdg.cfg_node) subgraph in 
  let filtered = 
	lfilt
	  (fun cfg_node ->
		match cfg_node.cnode with
		  START | STOP | ENTRY -> false
		| _ -> true
	  ) cfg 
  in
  let rec get_stmts = function 
	| BASIC_BLOCK (slist) -> slist
	| CONTROL_FLOW(s,_) -> [s]
	| REGION_NODE (cns) -> 
	  lflat (lmap (fun (cn,_) -> get_stmts cn.cnode) cns)
	| _ -> []
  in
  let stmts = lflat (lmap (fun cn -> get_stmts cn.cnode) filtered) in
  let as_nums = 
	lmap (fun stmt -> IntSet.singleton stmt.C.id) stmts
  in
	full_merge as_nums

(* a vector describing context can refer to:
   the entire AST of surrounding context.
   the characteristic vectors of the PDG of the entire AST of surrounding context
   the vectors of the syntax of the modification site
   the characteristic vectors of a subgraph in which a modification site is contained *)
(* what do the vectors match? From the paper, it's either (1) a complete AST
   subtree, (2) a sequence of contiguous statements, or (3) another semantic
   vector: a slice of another procedure *)

(* FIXME: we may need some inter-procedural analysis for when entire definitions are inserted *)
let guard_array_merge arrays = failwith "Not implemented"
let subgraph_array arrays = failwith "Not implemented"
let merge_subgraph_arrays arrays = failwith "Not implemented"

let template_to_vectors template = 
  (* one vector describes the parent, which is a mergeable node by definition *)
  let parent_vector = vector_gen#walkStatement template.parent in
  let merged_parent_vectors = merge_gen#walkStatement template.parent in
  (* one array describes the change operations, one array for node involved in
	 operation, list of merged nodes provides further description of the AST
	 involved in the operation *)
  let change_arrays = lmap change_array template.edits in
  (* one array for the guard, one top-level for the ast, and merged for the
	 ast *)
  let guard_arrays = lmap guard_array (List.of_enum (Set.enum template.guards)) in
  let merged_guard_arrays = guard_array_merge guard_arrays in
  let pdg_subgraph_array = lmap subgraph_array template.subgraphs in
  let pdg_subgraph_arrays = lmap merge_subgraph_arrays template.subgraphs in
	{ VectPoint.vid = -1; VectPoint.context = []; VectPoint.change = [] }
	
	
