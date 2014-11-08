%error-verbose

%code requires{
#include "patrones.hpp"
}
%{
#define YYDEBUG 1
#include <stdio.h>
extern int yylex();
void yyerror(const char *s) { printf("error: %s\n", s); }
%}
%code{
	ASTBuilder *builder = new ASTBuilder();
}
%union{
	int valorint;
	Node* nodo;
	NodeList* lista;
	BlockNode* bloque;
}
%debug
%token NEWLINE DEF IDENTIFIER DEL PASS BREAK CONTINUE RETURN RAISE IMPORT FROM AS
%token GLOBAL FOR IN WITH EXCEPT INDENT DEDENT LAMBDA OR AND NOT IS ELIF ELSE IF PRINT
%token STRING WHILE YIELD
%token PUNTOS PARIZQ PARDER COMA PUNTOCOMA IGUAL PORPOR POR MASIGUAL MENOSIGUAL
%token PORIGUAL ENTREIGUAL MODULOIGUAL AMPERIGUAL ORIGUAL NEGIGUAL MENORMENORIGUAL MAYORMAYORIGUAL
%token PORPORIGUAL DIVDIVIGUAL CORRIMIENTODER CORRIMIENTOIZQ PUNTO EXEC MAYOR MENOR IGUALIGUAL
%token MAYORIGUAL MENORIGUAL MAYORMENOR DIFERENTE ORR ANDD NOTX MAS MENOS MOD DIV DIVDIV NEG CORDER
%token CORIZQ TILDE LLAVEIZQ LLAVEDER
%token NUMBER
%type<lista> file_input varargslist aux3 aux4 fpdef fplist aux5 simple_stmt aux6 small_stmt expr_stmt aux7 augassign print_stmt aux8 del_stmt pass_stmt flow_stmt break_stmt continue_stmt return_stmt raise_stmt global_stmt temp2 exec_stmt compound_stmt if_stmt aux9 while_stmt for_stmt aux11 test aux13 and_test aux14 not_test comparison aux15 comp_op expr aux18 xor_expr aux19 and_expr aux20 shift_expr aux21 arith_expr aux22 term aux23 factor power aux24 atom aux25 listmaker aux26 testlist_comp trailer subscriptlist aux27 subscript sliceop exprlist aux28 testlist testlist_safe aux12 dictorsetmaker aux29 arglist aux30 argument list_iter list_for list_if comp_iter comp_for comp_if testlist1
%type<nodo> stmt funcdef parameters suite

%%

file_input: {$$=0;}
	|file_input NEWLINE {$$=$1;}
	|file_input stmt {$$=$1;}

funcdef: DEF IDENTIFIER parameters PUNTOS suite {$$=builder->bFuncDefNode(*$3,*$5);}
parameters: PARIZQ PARDER {$$=0;}
		|PARIZQ varargslist PARDER {$$=builder->bToNode($2);}

varargslist: aux3 PORPOR IDENTIFIER {$$ = $1;}
			| aux3 POR IDENTIFIER COMA PORPOR IDENTIFIER {$$ = $1;}
			| aux3 POR IDENTIFIER {$$ = $1;}
			| fpdef IGUAL test aux4 COMA {$$=builder->bVarargslistNode($1,$3,$4);}
			| fpdef IGUAL test aux4 {$$=builder->bVarargslistNode($1,$3,$4);}
			| fpdef aux4 COMA {$$=builder->bVarargslistNode($1,$2);}
			| fpdef aux4 {$$=builder->bVarargslistNode($1,$2);}
aux3:	{$$=0;}
	|fpdef IGUAL test COMA {$$=0;}
	|fpdef COMA {$$=0;}

aux4: {$$=0;}
	| COMA fpdef IGUAL test {$$=0;}
	| COMA fpdef {$$=0;}

fpdef: IDENTIFIER {$$=0;}
	| PARIZQ fplist PARDER {$$=0;}

fplist: fpdef aux5 COMA {$$=0;}
		|fpdef aux5 {$$=0;}

aux5: {$$=0;}
	| aux5 COMA fpdef {$$=0;}

stmt: simple_stmt {$$=0;}
	| compound_stmt {$$=0;}

simple_stmt: small_stmt aux6 PUNTOCOMA NEWLINE {$$=0;}
			|small_stmt aux6 NEWLINE {$$=0;}

aux6: {$$=0;}
	|aux6 PUNTOCOMA small_stmt {$$=0;}

small_stmt: expr_stmt {$$=$1;}
		  | print_stmt {$$=$1;}
		  | del_stmt {$$=$1;}
		  | pass_stmt {$$=$1;}
		  | flow_stmt {$$=$1;}
		  | global_stmt {$$=$1;}
		  | exec_stmt {$$=$1;}

expr_stmt: testlist augassign testlist {$$=0;}
		| testlist aux7 {$$=0;}
aux7: {$$=0;}
	|aux7 IGUAL testlist {$$=0;}

augassign: MASIGUAL {$$=0;}
		| MENOSIGUAL {$$=0;}
		| PORIGUAL {$$=0;}
		| ENTREIGUAL {$$=0;}
		| MODULOIGUAL {$$=0;}
		| AMPERIGUAL {$$=0;}
		| ORIGUAL {$$=0;}
		| NEGIGUAL {$$=0;}
		| MENORMENORIGUAL {$$=0;}
		| MAYORMAYORIGUAL {$$=0;}
		| PORPORIGUAL {$$=0;}
		| DIVDIVIGUAL {$$=0;}

print_stmt: PRINT {$$=0;}
			| PRINT test aux26 COMA {$$=0;}
			| PRINT test aux26 {$$=0;}
			| PRINT CORRIMIENTODER test {$$=0;}
		   	| PRINT CORRIMIENTODER test aux8 COMA {$$=0;}
		   	| PRINT CORRIMIENTODER test aux8 {$$=0;}

aux8: COMA test {$$=0;}
	| aux8 COMA test {$$=0;}

del_stmt: DEL exprlist {$$=0;}
pass_stmt: PASS {$$=0;}
flow_stmt: break_stmt {$$=0;}
		|continue_stmt {$$=0;}
		|return_stmt {$$=0;}
		|raise_stmt {$$=0;}

break_stmt: BREAK {$$=0;}
continue_stmt: CONTINUE {$$=0;}
return_stmt: RETURN testlist {$$=0;}
			|RETURN {$$=0;}

raise_stmt: RAISE test COMA test COMA test {$$=0;}
			|RAISE test {$$=0;}
			|RAISE test COMA test {$$=0;}
		 	|RAISE {$$=0;}

global_stmt: GLOBAL IDENTIFIER temp2 {$$=0;}
temp2: {$$=0;}
	|temp2 COMA IDENTIFIER {$$=0;}

exec_stmt: EXEC expr IN test COMA test {$$=0;}
		| EXEC expr {$$=0;}
		| EXEC expr IN test {$$=0;}

compound_stmt: if_stmt {$$=0;}
			| while_stmt {$$=0;}
			| for_stmt {$$=0;}
			| funcdef {$$=0;}

if_stmt: IF test PUNTOS suite aux9 ELSE PUNTOS suite {$$=0;}
		|IF test PUNTOS suite aux9 {$$=0;}
aux9: {$$=0;}
	|aux9 ELIF test PUNTOS suite {$$=0;}


while_stmt: WHILE test PUNTOS suite ELSE PUNTOS suite {$$=0;}
			|WHILE test PUNTOS suite {$$=0;}

for_stmt: FOR exprlist IN testlist PUNTOS suite ELSE PUNTOS suite {$$=0;}
		| FOR exprlist IN testlist PUNTOS suite {$$=0;}

suite: simple_stmt {$$=0;}
	| NEWLINE INDENT aux11 DEDENT {$$=0;}

aux11: stmt {$$=0;}
	|aux11 stmt {$$=0;}

test: and_test aux13 {$$=0;}

aux13: {$$=0;}
	|aux13 OR and_test {$$=0;}

and_test: not_test aux14 {$$=0;}

aux14: {$$=0;}
	|aux14 AND not_test {$$=0;}

not_test: NOT not_test {$$=0;}
	|comparison {$$=0;}

comparison: expr aux15 {$$=0;}
aux15: {$$=0;}
	|aux15 comp_op expr {$$=0;}

comp_op: MAYOR {$$=0;}
	| MENOR {$$=0;}
	| IGUALIGUAL {$$=0;}
	| MAYORIGUAL {$$=0;}
	| MENORIGUAL {$$=0;}
	| MAYORMENOR {$$=0;}
	| DIFERENTE {$$=0;}
	| IN {$$=0;}
	| NOT IN {$$=0;}
	| IS {$$=0;}
	| IS NOT {$$=0;}

expr: xor_expr aux18 {$$=0;}
aux18: {$$=0;}
	| aux18 ORR xor_expr {$$=0;}

xor_expr: and_expr aux19 {$$=0;}
aux19: {$$=0;}
	|aux19 NOTX and_expr {$$=0;}

and_expr: shift_expr aux20 {$$=0;}
aux20: {$$=0;}
	|aux20 ANDD shift_expr {$$=0;}

shift_expr: arith_expr aux21 {$$=0;}
aux21: {$$=0;}
	|aux21 CORRIMIENTOIZQ arith_expr {$$=0;}
	|aux21 CORRIMIENTODER arith_expr {$$=0;}

arith_expr: term aux22 {$$=0;}
aux22: {$$=0;}
	|aux22 MAS term {$$=0;}
	|aux22 MENOS term {$$=0;}

term: factor aux23 {$$=0;}
aux23: {$$=0;}
	| aux23 POR factor {$$=0;}
	| aux23 DIV factor {$$=0;}
	| aux23 MOD factor {$$=0;}
	| aux23 DIVDIV factor {$$=0;}

factor: MAS factor {$$=0;}
	| MENOS factor {$$=0;}
	| NEG factor {$$=0;}
	| power {$$=0;}

power: atom aux24 PORPOR factor {$$=0;}
	| atom aux24 {$$=0;}
aux24: {$$=0;}
	|trailer {$$=0;}

atom: PARIZQ testlist_comp PARDER {$$=0;}
	| PARIZQ PARDER {$$=0;}
	| CORIZQ listmaker CORDER {$$=0;}
	| CORIZQ CORDER {$$=0;}
	| LLAVEIZQ dictorsetmaker LLAVEDER {$$=0;}
	| LLAVEIZQ LLAVEDER {$$=0;}
	| TILDE testlist1 TILDE {$$=0;}
	| IDENTIFIER {$$=0;}
	| NUMBER {$$=0;}
	| aux25 {$$=0;}

aux25: STRING {$$=0;}
	|aux25 STRING {$$=0;}

listmaker: test list_for {$$=0;}
		| test aux26 COMA {$$=0;}
		| test aux26 {$$=0;}
aux26: {$$=0;}
	| aux26 COMA test {$$=0;}

testlist_comp: test comp_for {$$=0;}
			| test aux26 COMA {$$=0;}
			| test aux26 {$$=0;}

trailer: PARIZQ arglist PARDER {$$=0;}
		| PARIZQ PARDER {$$=0;}
		| CORIZQ subscriptlist CORDER {$$=0;}
		| PUNTO IDENTIFIER {$$=0;}

subscriptlist: subscript aux27 COMA {$$=0;}
			| subscript aux27 {$$=0;}
aux27: {$$=0;}
	| aux27 COMA subscript {$$=0;}

subscript: PUNTO PUNTO PUNTO {$$=0;}
		| test {$$=0;}
		| PUNTOS {$$=0;}
		| test PUNTOS {$$=0;}
		| test PUNTOS test sliceop {$$=0;}
		| PUNTOS test {$$=0;}
		| test PUNTOS test {$$=0;}
		| PUNTOS test sliceop {$$=0;}
		| PUNTOS sliceop {$$=0;}
		| test PUNTOS sliceop {$$=0;}

sliceop:PUNTOS test {$$=0;}
		|PUNTOS {$$=0;}

exprlist: expr aux28 COMA {$$=0;}
		| expr aux28 {$$=0;}
aux28: {$$=0;}
	| aux28 COMA expr {$$=0;}

testlist: test aux26 COMA {$$=0;}
		| test aux26 {$$=0;}

testlist_safe: test aux12 COMA {$$=0;}
			| test aux12 {$$=0;}
			| test {$$=0;}

aux12: COMA test {$$=0;}
	|aux12 COMA test {$$=0;}

dictorsetmaker: test PUNTOS test aux29 COMA {$$=0;}
			| test PUNTOS test aux29 {$$=0;}

aux29: {$$=0;}
	| aux29 COMA test PUNTOS test {$$=0;}


arglist: aux30 argument COMA {$$=0;}
		|aux30 argument {$$=0;}
		|aux30 POR test {$$=0;}
		|aux30 POR test COMA PORPOR test {$$=0;}
		|aux30 PORPOR test {$$=0;}

aux30: {$$=0;}
	|aux30 argument COMA {$$=0;}

argument: test {$$=0;}
		| test comp_for {$$=0;}
		| test IGUAL test {$$=0;}
		| test IGUAL test PARIZQ comp_for PARDER {$$=0;}

list_iter: list_for {$$=0;}
		| list_if {$$=0;}

list_for: FOR exprlist IN testlist_safe list_iter {$$=0;}
		| FOR exprlist IN testlist_safe {$$=0;}

list_if: IF test list_iter {$$=0;}
		|IF test {$$=0;}

comp_iter: comp_for {$$=0;}
		| comp_if {$$=0;}

comp_for: FOR exprlist IN test comp_iter {$$=0;}
		| FOR exprlist IN test {$$=0;}

comp_if: IF test comp_iter {$$=0;}
		|IF test {$$=0;}

testlist1: test aux26 {$$=0;}



%%
int main(int argc, char *argv[]){

    extern FILE* yyin;
    yyin=fopen(argv[1],"r");
    int exito = yyparse();
    if(exito == 0) {
    	printf("Archivo correcto\n");
    	exit(EXIT_SUCCESS);
    }
    exit(EXIT_FAILURE);
}