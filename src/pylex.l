%{
#include <iostream>
#include <string>
#include <locale>
#include "pila.h"

std::locale loc;
std::string toUpper(std::string);

Pila pilaIndent;
std::string toUpper(std::string);
std::string getIndents(std::string);

%}

%option noyywrap
%option outfile="pylex.cpp"
%x String
%x INICIADO

COMMENT (#.*)
NEWLINE [\n]
SPACE [\ ]
TAB (\t|\ +)

DIGIT [0-9]
NONZERODIGIT [1-9]
NUMBER ({INTEGER}|{FLOAT})

INTEGER ({DECIMAL}|{BINARY}|{OCTAL}|{HEXADECIMAL})
DECIMAL (({NONZERODIGIT}{DIGIT}*)|(0+))
OCTAL (0(o|O){OCTDIGIT}+)|(0{OCTDIGIT}+)
HEXADECIMAL(0(x|X){HEXDIGIT}+)
BINARY (0(b|B){BINDIGIT}+)
BINDIGIT (0|1)
OCTDIGIT ([0-7])
HEXDIGIT ({DIGIT}|[a-f]|[A-F])

FLOAT ({POINTFLOAT}|{EXPONENTFLOAT})
POINTFLOAT ({INTPART}{FRACTION}|{INTPART}".")
AUX ({INTPART}|{POINTFLOAT})
EXPONENTFLOAT  ({AUX}{EXPONENT})
INTPART ({DIGIT}+)
FRACTION ("."{DIGIT}+)
EXPONENT ([E|e][+|-]?{DIGIT}+)

KEYWORD (print|False|class|finally|is|return|None|continue|for|lambda|try|True|def|from|nonlocal|while|and|del|global|not|with|as|elif|if|or|yield|assert|else|import|pass|break|except|in|raise)
IDENTIFIER [a-zA-Z|_][a-zA-Z0-9_]*

SPECIALSTRING [\"\t\\\r\ ]
STRINGITEM ([a-zA-Z0-9]|{SPECIALSTRING})
STRING {STRINGITEM}*\"
%%

{COMMENT}
{NEWLINE}
. 										{yyless(0);BEGIN(INICIADO);}

<INICIADO>{COMMENT}
<INICIADO>{NEWLINE}({SPACE}|{TAB})*{NEWLINE}
<INICIADO>{NEWLINE}({SPACE}|{TAB})+		std::cout << getIndents(yytext);
<INICIADO>{NEWLINE} 					std::cout << getIndents("") << "NEWLINE \n";
<INICIADO>{NUMBER}						std::cout << "NUMBER ";
<INICIADO>{KEYWORD}						std::cout << toUpper(yytext);
<INICIADO>{IDENTIFIER}					std::cout << "IDENTIFIER ";
<INICIADO>\"							BEGIN(String);

<String>{STRING}						std::cout << "STRING ";BEGIN(INITIAL);
<String>\n 								std::cout << "\n\n ERROR LA CADENA NO ESTA TERMINADA\n "; return 0;
%%

std::string toUpper(std::string original) {
	for (std::string::size_type i=0; i<original.length(); ++i)
    	original[i] = std::toupper(original[i],loc);
    return original;
}

std::string getIndents(std::string espacios) {
	int numEspacios = 0;
	for (std::string::size_type i=0; i<espacios.length(); ++i) {
		if(espacios[i] == ' ') {
			numEspacios++;
		} else if (espacios[i] == '\t') {
			numEspacios += 4;
		}
	}
	std::cout << "\nHay " << numEspacios << " espacios";
	return "";
}

int main(int argc, char *argv[]){
    extern FILE* yyin;
    yyin=fopen(argv[1],"r");
    yylex();
}