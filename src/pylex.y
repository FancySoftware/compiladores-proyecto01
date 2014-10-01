%{
#include <stdio.h>
int yylex();
int yyerror(const char*s){printf("Error: %s\n",s);}	

%}

%token ENDMARKER NEWLINE DEF IDENTIFIER DEL PASS BREAK CONTINUE RETURN RAISE IMPORT FROM AS
%token GLOBAL FOR IN WITH EXCEPT INDENT DEDENT LAMBDA OR AND NOT IS ELIF ELSE IF NUMBER PRINT
%token STRING WHILE YIELD
%token PUNTOS ":"
%token PARIZQ '(' 
%token PARDER ")"
%token COMA "," 
%token PUNTOCOMA ";"
%token IGUAL "="
%token PORPOR "**"
%token POR "*"
%token MASIGUAL "+="
%token MENOSIGUAL "-="
%token PORIGUAL "*="
%token ENTREIGUAL "/="
%token MODULOIGUAL "%="
%token AMPERIGUAL "&="
%token ORIGUAL "|="
%token NEGIGUAL "^="
%token MENORMENORIGUAL "<<="
%token MAYORMAYORIGUAL ">>="
%token PORPORIGUAL "**="
%token DIVDIVIGUAL "//="
%token CORRIMIENTODER ">>"
%token CORRIMIENTOIZQ "<<"
%token PUNTO "."
%token EXEC "exec"
%token MAYOR '>'
%token MENOR "<"
%token IGUALIGUAL "=="
%token MAYORIGUAL ">="
%token MENORIGUAL "<="
%token MAYORMENOR "<>"
%token DIFERENTE "!="
%token ORR "|"
%token ANDD "&"
%token NOTX "^"
%token MAS "+"
%token MENOS "-"
%token MOD "%"
%token DIV '/'
%token DIVDIV "//"
%token NEG "~"
%token CORDER "]"
%token CORIZQ "["
%token TILDE "`"
%token LLAVEIZQ "{"
%token LLAVEDER "}"

%%

file_input: aux
			
aux:
	|aux NEWLINE 
	|aux stmt

funcdef: DEF IDENTIFIER parameters PUNTOS suite
parameters: PARIZQ PARDER
		|PARIZQ varargslist PARDER

varargslist: aux3 PORPOR IDENTIFIER 
			| aux3 POR IDENTIFIER COMA PORPOR IDENTIFIER
			| aux3 POR IDENTIFIER
			| fpdef IGUAL test aux4 COMA
			| fpdef IGUAL test aux4 
			| fpdef aux4 COMA
			| fpdef aux4 
aux3:
	|fpdef IGUAL test COMA
	|fpdef COMA

aux4:
	| COMA fpdef IGUAL test
	| COMA fpdef 

fpdef: IDENTIFIER
	| PARIZQ fplist PARDER

fplist: fpdef aux5 COMA
		|fpdef aux5

aux5:
	| aux5 COMA fpdef

stmt: simple_stmt 
	| compound_stmt

simple_stmt: small_stmt aux6 PUNTOCOMA NEWLINE
			|small_stmt aux6 NEWLINE

aux6: 
	|aux6 PUNTOCOMA small_stmt

small_stmt: expr_stmt
		  | print_stmt
		  | del_stmt
		  | pass_stmt
		  | flow_stmt
		  | global_stmt
		  | exec_stmt

expr_stmt: testlist augassign testlist
		| testlist aux7
aux7:
	|aux7 IGUAL testlist

augassign: MASIGUAL
		| MENOSIGUAL
		| PORIGUAL
		| ENTREIGUAL
		| MODULOIGUAL
		| AMPERIGUAL
		| ORIGUAL
		| NEGIGUAL
		| MENORMENORIGUAL
		| MAYORMAYORIGUAL
		| PORPORIGUAL
		| DIVDIVIGUAL

print_stmt: | PRINT 
			| PRINT test aux26 COMA
			| PRINT test aux26 
			| PRINT CORRIMIENTODER test
		   	| PRINT CORRIMIENTODER test aux8 COMA
		   	| PRINT CORRIMIENTODER test aux8 

aux8: COMA test
	| aux8 COMA test

del_stmt: DEL exprlist
pass_stmt: PASS
flow_stmt: break_stmt 
		|continue_stmt
		|return_stmt
		|raise_stmt

break_stmt: BREAK
continue_stmt: CONTINUE
return_stmt: RETURN testlist
			|RETURN 

raise_stmt: RAISE test COMA test COMA test
			|RAISE test
			|RAISE test COMA test
		 	|RAISE 

global_stmt: GLOBAL IDENTIFIER temp2
temp2:
	|temp2 COMA IDENTIFIER

exec_stmt: EXEC expr IN test COMA test
		| EXEC expr 
		| EXEC expr IN test

compound_stmt: if_stmt
			| while_stmt
			| for_stmt
			| funcdef

if_stmt: IF test PUNTOS suite aux9 ELSE PUNTOS suite
		|IF test PUNTOS suite aux9 
aux9:
	|aux9 ELIF test PUNTOS suite


while_stmt: WHILE test PUNTOS suite ELSE PUNTOS suite
			|WHILE test PUNTOS suite

for_stmt: FOR exprlist IN testlist PUNTOS suite ELSE PUNTOS suite
		| FOR exprlist IN testlist PUNTOS suite

suite: simple_stmt
	| NEWLINE INDENT aux11 DEDENT

aux11: stmt
	|aux11 stmt

test: and_test aux13 

aux13: 
	|aux13 OR and_test

and_test: not_test aux14

aux14:
	|aux14 AND not_test 

not_test: NOT not_test 
	|comparison

comparison: expr aux15
aux15:
	|aux15 comp_op expr

comp_op: MAYOR
	| MENOR
	| IGUALIGUAL
	| MAYORIGUAL
	| MENORIGUAL
	| MAYORMENOR
	| DIFERENTE
	| IN 
	| NOT IN
	| IS
	| IS NOT

expr: xor_expr aux18
aux18:
	| aux18 ORR xor_expr

xor_expr: and_expr aux19
aux19:
	|aux19 NOTX and_expr

and_expr: shift_expr aux20
aux20:
	|aux20 ANDD shift_expr

shift_expr: arith_expr aux21
aux21:
	|aux21 CORRIMIENTOIZQ arith_expr
	|aux21 CORRIMIENTODER arith_expr

arith_expr: term aux22
aux22:
	|aux22 MAS term
	|aux22 MENOS term

term: factor aux23
aux23:
	| aux23 POR factor
	| aux23 DIV factor
	| aux23 MOD factor
	| aux23 DIVDIV factor

factor: MAS factor
	| MENOS factor
	| NEG factor
	| power

power: atom aux24 PORPOR factor
	| atom aux24 
aux24:
	|trailer

atom: PARIZQ testlist_comp PARDER
	| PARIZQ PARDER
	| CORIZQ listmaker CORDER
	| CORIZQ CORDER
	| LLAVEIZQ dictorsetmaker LLAVEDER
	| LLAVEIZQ LLAVEDER
	| TILDE testlist1 TILDE
	| IDENTIFIER
	| NUMBER
	| aux25

aux25: STRING
	|aux25 STRING

listmaker: test list_for
		| test aux26 COMA
		| test aux26
aux26:
	| aux26 COMA test

testlist_comp: test comp_for
			| test aux26 COMA
			| test aux26 

trailer: PARIZQ arglist PARDER
		| PARIZQ PARDER
		| CORIZQ subscriptlist CORDER
		| PUNTO IDENTIFIER

subscriptlist: subscript aux27 COMA
			| subscript aux27
aux27:
	| aux27 COMA subscript

subscript: PUNTO PUNTO PUNTO 
		| test
		| PUNTOS 
		| test PUNTOS
		| test PUNTOS test sliceop
		| PUNTOS test
		| test PUNTOS test
		| PUNTOS test sliceop
		| PUNTOS sliceop
		| test PUNTOS sliceop

sliceop:PUNTOS test
		|PUNTOS

exprlist: expr aux28 COMA
		| expr aux28
aux28: 
	| aux28 COMA expr

testlist: test aux26 COMA
		| test aux26

testlist_safe: test aux12 COMA
			| test aux12 
			| test

aux12: COMA test
	|aux12 COMA test

dictorsetmaker: test PUNTOS test aux29 COMA
			| test PUNTOS test aux29

aux29: 
	| aux29 COMA test PUNTOS test


arglist: aux30 argument COMA 
		|aux30 argument
		|aux30 POR test 
		|aux30 POR test COMA PORPOR test
		|aux30 PORPOR test

aux30:
	|aux30 argument COMA

argument: test 
		| test comp_for
		| test IGUAL test
		| test IGUAL test PARIZQ comp_for PARDER

list_iter: list_for 
		| list_if

list_for: FOR exprlist IN testlist_safe list_iter
		| FOR exprlist IN testlist_safe

list_if: IF test list_iter
		|IF test

comp_iter: comp_for 
		| comp_if

comp_for: FOR exprlist IN test comp_iter
		| FOR exprlist IN test

comp_if: IF test comp_iter
		|IF test 

testlist1: test aux26



%%
int main(int argc, char *argv[]){
    extern FILE* yyin;
    yyin=fopen(argv[1],"r");
 	yyparse();
}

