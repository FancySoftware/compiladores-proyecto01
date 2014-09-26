#include <string>
#include "pylex_parser.hpp"
#include "keyword.h"
using namespace std;

yytokentype getTokenFromKeyword(string keyword){
    if (keyword.compare("print")) return PRINT;
    if (keyword.compare("False")) return FALSE;
    if (keyword.compare("class")) return CLASS;
    if (keyword.compare("finally")) return FINALLY;
    if (keyword.compare("is")) return IS;
    if (keyword.compare("return")) return RETURN;
    if (keyword.compare("None")) return NONE;
    if (keyword.compare("continue")) return CONTINUE;
    if (keyword.compare("for")) return FOR;
    if (keyword.compare("lambda")) return LAMBDA;
    if (keyword.compare("try")) return TRY;
    if (keyword.compare("True")) return TRUE;
    if (keyword.compare("def")) return DEF;
    if (keyword.compare("from")) return FROM;
    if (keyword.compare("nonlocal")) return NONLOCAL;
    if (keyword.compare("while")) return WHILE;
    if (keyword.compare("and")) return AND;
    if (keyword.compare("del")) return DEL;
    if (keyword.compare("global")) return GLOBAL;
    if (keyword.compare("not")) return NOT;
    if (keyword.compare("with")) return WITH;
    if (keyword.compare("as")) return AS;
    if (keyword.compare("elif")) return ELIF;
    if (keyword.compare("if")) return IF;
    if (keyword.compare("or")) return OR;
    if (keyword.compare("yield")) return YIELD;
    if (keyword.compare("assert")) return ASSERT;
    if (keyword.compare("else")) return ELSE;
    if (keyword.compare("import")) return IMPORT;
    if (keyword.compare("pass")) return PASS;
    if (keyword.compare("break")) return BREAK;
    if (keyword.compare("except")) return EXCEPT;
    if (keyword.compare("in")) return IN;
    if (keyword.compare("raise")) return RAISE;
}