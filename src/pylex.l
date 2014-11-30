%{

#include <iostream>
#include <string>
#include <locale>
#include <stdlib.h>
#include "pila.hpp"
#include "pypar.hpp"
#include "keyword.hpp"

int num_dedents = 0, num_indents = 0;
Pila pilaIndent;

std::locale loc;
std::string toUpper(std::string);
void getIndents(std::string);
void pseudo_main();

%}
%option debug
%option noyywrap
%option outfile="pylex.cpp"
%x String
%x Iniciado
%x Dedent
%x Indent


COMMENT (#.*)
NEWLINE "\n"
SPACE "\ "
TAB ("\t"|"\ "+)

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

KEYWORD (and|del|from|not|while|as|elif|global|or|with|assert|else|if|pass|yield|break|except|import|print|class|exec|in|raise|continue|finally|is|return|def|for|lambda|try)
IDENTIFIER [a-zA-Z|_][a-zA-Z0-9_]*

OPERATION (":"|"("|")"|","|";"|"="|"**"|"*"|"+="|"-="|"*="|"/="|"\%="|"&="|"|="|"^="|"<<="|">>="|"**="|"//="|">>"|"<<"|"."|"exec"|">"|"<"|"=="|">="|"<="|"<>"|"!="|"|"|"&"|"^"|"+"|"-"|"\%"|"/"|"//"|"~"|"]"|"["|"`"|"{"|"}")
STRING (\\.|[^"])*\"
%%

{COMMENT}
{NEWLINE}
. 										{
											yyless(0);
											pseudo_main();
											BEGIN(Iniciado);
										}
<Iniciado><<EOF>>   					{
											getIndents(yytext);
											if(num_dedents > 0) {
												BEGIN(Dedent);
											}
											static int once = 0; return once++ ?0:NEWLINE;
										}
<Iniciado>{SPACE}
<Iniciado>{COMMENT}
<Iniciado>{NEWLINE}+({SPACE}|{TAB})+ 	{
											getIndents(yytext);
											if(num_dedents > 0) {
												BEGIN(Dedent);
											} else if(num_indents > 0) {
												BEGIN(Indent);
											}
											std::cout <<"NEWLINE";
											return NEWLINE;
										}
<Iniciado>{NEWLINE}+ 					{
											getIndents(yytext);
											if(num_dedents > 0) {
												BEGIN(Dedent);
											} else if(num_indents > 0) {
												BEGIN(Indent);
											}
											std::cout << "NEWLINE";
											return NEWLINE;
										}
<Iniciado>{NUMBER}						{
										yylval.num=atoi(yytext);
										std::cout <<"NUMBER";
										return NUMBER;
										}
<Iniciado>{KEYWORD}						std::cout << "KEYWORD"; return getTokenFromKeyword(yytext);
<Iniciado>{IDENTIFIER}					std::cout << "IDENTIFIER"; return IDENTIFIER;
<Iniciado>\"							BEGIN(String);
<Iniciado>{OPERATION} 					std::cout <<"OPERATION";return getTokenFromOperation(yytext);
<String>(\\.|[^"])*\" 					{
											yylval.str = strdup(yytext);
											std::cout << "CADENA";
											BEGIN(Iniciado);
											return STRING;
										}
<String>{NEWLINE}						std::cout <<"\n\n ERROR CADENA NO TERMINADA\n"; exit(EXIT_FAILURE);
<String>.								std::cout << "\n\n ERROR CADENA NO TERMINADA\n";exit(EXIT_FAILURE);
<Dedent>. 								{
											yyless(0);
											num_dedents--;
											if(num_dedents == 0) {
												BEGIN(Iniciado);
											}
											std::cout <<"DEDENT";
											return DEDENT;
										}
<Dedent><<EOF>>							{

										num_dedents--;
										if(num_dedents==0){
											BEGIN(Iniciado);
										}
										std::cout <<"DEDENT";
											return DEDENT;
										}

<Indent>. 								{
											yyless(0);
											num_indents--;
											BEGIN(Iniciado);
											std::cout << "INDENT";
											return INDENT;
										}
%%
void pseudo_main() {
	pilaIndent.push(0);
}
void getIndents(std::string espacios) {
	int numEspacios = 0;
	for (std::string::size_type i=0; i<espacios.length(); ++i) {
		if(espacios[i] == ' ') {
			numEspacios++;
		} else if (espacios[i] == '\t') {
			numEspacios += 4;
		}
	}
	if(pilaIndent.top() == numEspacios) {
		return;
	}
	if(pilaIndent.top() < numEspacios) {
		pilaIndent.push(numEspacios);
		num_indents++;
		return;
	}
	std::string dedents = "";
	while(pilaIndent.length() != 0) {
		if(pilaIndent.top() > numEspacios) {
			pilaIndent.pop();
			num_dedents++;
		} else if (pilaIndent.top() < numEspacios) {
			std::cout << "\nFalla en la indentación\n";
			exit(EXIT_FAILURE);
		} else if (pilaIndent.top() == numEspacios) {
			return;
		}
	}
	return;
}