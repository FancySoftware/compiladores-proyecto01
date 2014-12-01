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
	float num;
	char* str;
}

%debug
%token NEWLINE DEL PASS BREAK CONTINUE RETURN RAISE IMPORT FROM AS
%token GLOBAL FOR IN WITH EXCEPT INDENT DEDENT LAMBDA OR AND NOT IS ELIF ELSE IF PRINT
%token WHILE YIELD
%token PUNTOS PARIZQ PARDER COMA PUNTOCOMA IGUAL PORPOR POR MASIGUAL MENOSIGUAL
%token PORIGUAL ENTREIGUAL MODULOIGUAL AMPERIGUAL ORIGUAL NEGIGUAL MENORMENORIGUAL MAYORMAYORIGUAL
%token PORPORIGUAL DIVDIVIGUAL CORRIMIENTODER CORRIMIENTOIZQ PUNTO EXEC MAYOR MENOR IGUALIGUAL
%token MAYORIGUAL MENORIGUAL MAYORMENOR DIFERENTE ORR ANDD NOTX MAS MENOS MOD DIV DIVDIV NEG CORDER
%token CORIZQ TILDE LLAVEIZQ LLAVEDER
%token <num> NUMBER
%token <str> STRING IDENTIFIER
%type <num,str> atom
%%

file_input:
	|file_input NEWLINE
	|file_input stmt

stmt: simple_stmt
	|compound_stmt


simple_stmt: small_stmt aux6 PUNTOCOMA NEWLINE
			|small_stmt aux6 NEWLINE

small_stmt: expr_stmt
		| print_stmt
		| flow_stmt

compound_stmt:   if_stmt
			| WHILE test PUNTOS suite
			| FOR expr IN test PUNTOS suite

expr_stmt: test augassign test
		| test aux7

aux7:
	|aux7 IGUAL test
flow_stmt: BREAK
	|CONTINUE
	|return_stmt

return_stmt: RETURN test
			|RETURN
if_stmt: IF test PUNTOS suite aux9 ELSE PUNTOS suite
		|IF test PUNTOS suite aux9
aux9:
	|aux9 ELIF test PUNTOS suite

suite: simple_stmt
	| NEWLINE INDENT aux11 DEDENT

aux11: stmt
	|aux11 stmt

print_stmt:	PRINT
			| PRINT test

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

aux6:
	|aux6 PUNTOCOMA small_stmt

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

power: atom PORPOR factor
	| atom

atom:PARIZQ testlist_comp PARDER
    |PARIZQ PARDER
	| IDENTIFIER
	| NUMBER
	| STRING

testlist_comp: test comp_for
			| test aux26 COMA
			| test aux26
aux26:
	| aux26 COMA test

comp_iter: comp_for
		| comp_if

comp_for: FOR expr IN test comp_iter
		| FOR expr IN test

comp_if: IF test comp_iter
		|IF test

%%
int main(int argc, char *argv[]){

    extern FILE* yyin;
    yyin=fopen(argv[1],"r");
    int exito = yyparse();
    if(exito == 0) {
    	printf("\nArchivo correcto\n");
    	exit(EXIT_SUCCESS);
    }
    exit(EXIT_FAILURE);
}