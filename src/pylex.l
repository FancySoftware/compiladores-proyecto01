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
IDENTIFIER [a-zA-Z0-9]*
%%
{COMMENT}
{NEWLINE}{SPACE}	std::cout << "FAKEINDENT"; 
{SPACE} 			yyless(1);
{NEWLINE} 			std::cout << "NEWLINE";
{STRING}			std::cout << "STRING";
{KEYWORD}			std::cout << toUpper(yytext);
{NUMBER} 			std::cout << "NUMBER";
{IDENTIFIER} 		std::cout << "IDENTIFIER";
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
