#include <string>
#include "pypar.hpp"
#include "keyword.hpp"
using namespace std;

yytokentype getTokenFromKeyword(string keyword){
    if (keyword.compare("print") == 0) return PRINT;
    if (keyword.compare("is") == 0) return IS;
    if (keyword.compare("return") == 0) return RETURN;
    if (keyword.compare("continue") == 0) return CONTINUE;
    if (keyword.compare("for") == 0) return FOR;
    if (keyword.compare("lambda") == 0) return LAMBDA;
    if (keyword.compare("def") == 0) return DEF;
    if (keyword.compare("from") == 0) return FROM;
    if (keyword.compare("while") == 0) return WHILE;
    if (keyword.compare("and") == 0) return AND;
    if (keyword.compare("del") == 0) return DEL;
    if (keyword.compare("global") == 0) return GLOBAL;
    if (keyword.compare("not") == 0) return NOT;
    if (keyword.compare("with") == 0) return WITH;
    if (keyword.compare("as") == 0) return AS;
    if (keyword.compare("elif") == 0) return ELIF;
    if (keyword.compare("if") == 0) return IF;
    if (keyword.compare("or") == 0) return OR;
    if (keyword.compare("yield") == 0) return YIELD;
    if (keyword.compare("else") == 0) return ELSE;
    if (keyword.compare("import") == 0) return IMPORT;
    if (keyword.compare("pass") == 0) return PASS;
    if (keyword.compare("break") == 0) return BREAK;
    if (keyword.compare("except") == 0) return EXCEPT;
    if (keyword.compare("in") == 0) return IN;
    if (keyword.compare("raise") == 0) return RAISE;
}

yytokentype getTokenFromOperation(string operation){
    if(operation.compare(":") == 0) return PUNTOS;
    if(operation.compare("(") == 0) return PARIZQ;
    if(operation.compare(")") == 0) return PARDER;
    if(operation.compare(",") == 0) return COMA;
    if(operation.compare(";") == 0) return PUNTOCOMA;
    if(operation.compare("=") == 0) return IGUAL;
    if(operation.compare("**") == 0) return PORPOR;
    if(operation.compare("*") == 0) return POR;
    if(operation.compare("+=") == 0) return MASIGUAL;
    if(operation.compare("-=") == 0) return MENOSIGUAL;
    if(operation.compare("*=") == 0) return PORIGUAL;
    if(operation.compare("/=") == 0) return ENTREIGUAL;
    if(operation.compare("\%=") == 0) return MODULOIGUAL;
    if(operation.compare("&=") == 0) return AMPERIGUAL;
    if(operation.compare("|=") == 0) return ORIGUAL;
    if(operation.compare("^=") == 0) return NEGIGUAL;
    if(operation.compare("<<=") == 0) return MENORMENORIGUAL;
    if(operation.compare(">>=") == 0) return MAYORMAYORIGUAL;
    if(operation.compare("**=") == 0) return PORPORIGUAL;
    if(operation.compare("//=") == 0) return DIVDIVIGUAL;
    if(operation.compare(">>") == 0) return CORRIMIENTODER;
    if(operation.compare("<<") == 0) return CORRIMIENTOIZQ;
    if(operation.compare(".") == 0) return PUNTO;
    if(operation.compare("exec") == 0) return EXEC;
    if(operation.compare(">") == 0) return MAYOR;
    if(operation.compare("<") == 0) return MENOR;
    if(operation.compare("==") == 0) return IGUALIGUAL;
    if(operation.compare(">=") == 0) return MAYORIGUAL;
    if(operation.compare("<=") == 0) return MENORIGUAL;
    if(operation.compare("<>") == 0) return MAYORMENOR;
    if(operation.compare("!=") == 0) return DIFERENTE;
    if(operation.compare("|") == 0) return ORR;
    if(operation.compare("&") == 0) return ANDD;
    if(operation.compare("^") == 0) return NOTX;
    if(operation.compare("+") == 0) return MAS;
    if(operation.compare("-") == 0) return MENOS;
    if(operation.compare("\%") == 0) return MOD;
    if(operation.compare("/") == 0) return DIV;
    if(operation.compare("//") == 0) return DIVDIV;
    if(operation.compare("~") == 0) return NEG;
    if(operation.compare("]") == 0) return CORDER;
    if(operation.compare("[") == 0) return CORIZQ;
    if(operation.compare("`") == 0) return TILDE;
    if(operation.compare("{") == 0) return LLAVEIZQ;
    if(operation.compare("}") == 0) return LLAVEDER;
}