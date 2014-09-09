%{
#include <iostream>
#include <string>
#include <locale>

std::locale loc;
std::string toUpper(std::string);

%}

%option noyywrap
%option outfile="pylex.cpp"

COMMENT #(.)*\n

NEWLINE \n

SPACE \ .

DIGIT [0-9]
NONZERODIGIT [1-9]
NUMBER \-?{NONZERODIGIT}{DIGIT}*

SPECIALSTRING [\"\n\t\\\r\ ]
STRINGITEM ([a-zA-Z0-9]|{SPECIALSTRING})
STRING \"{STRINGITEM}*\"

KEYWORD (print|False|class|finally|is|return|None|continue|for|lambda|try|True|def|from|nonlocal|while|and|del|global|not|with|as|elif|if|or|yield|assert|else|import|pass|break|except|in|raise)
IDENTIFIER [a-zA-Z|_][a-z|A-Z|0-9|_]*

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
EXPONENT ([E|e][+|-]*{DIGIT}+)

%%
{COMMENT}
{NEWLINE}{SPACE}		std::cout << "FAKEINDENT "; 
{SPACE} 			yyless(1);
{NEWLINE} 			std::cout << "NEWLINE \n";
{STRING}			std::cout << "STRING ";
{KEYWORD}			std::cout << toUpper(yytext) +" ";
{INTEGER}			std::cout << "INTEGER ";
{NUMBER}			std::cout << "NUMBER ";
{FLOAT}				std::cout << "FLOAT ";
{IDENTIFIER} 			std::cout << "IDENTIFIER ";
%%

std::string toUpper(std::string original) {
	for (std::string::size_type i=0; i<original.length(); ++i)
    	original[i] = std::toupper(original[i],loc);
    return original;
}

int main(int argc, char *argv[]){
    extern FILE* yyin;
    yyin=fopen(argv[1],"r");
    yylex();
}
