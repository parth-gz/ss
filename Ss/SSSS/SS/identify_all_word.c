%{
#include<stdio.h>
#include<string.h>
%}

header_file    ["#".*]
single_comment ["//".*]
operator       [/*+-]
number         [0-9]+
keyword        int|char|float|double|if|else|then|do|while
Identifier_a   [a-zA-Z][a-zA-Z0-9]* 
multiline_comment    "/*".*(".*\n")*"*/"
Floating_no    [0-9]+\.[0-9]+
signed_num     -?[0-9]+
delimeter      [();,]
literal_str    ["].*["]

%%

{header_file}      {printf("Header files are: %s\n", yytext);}
{single_comment}   {printf("Single line comments are: %s\n", yytext);}
{operator}         {printf("Operators are: %s\n", yytext);}
{number}          {printf("Number: %s\n", yytext);}
{keyword}         {printf("Keyword found: %s\n", yytext);}
{Identifier_a}    {printf("Identifier a: %s\n", yytext);}
{multiline_comment} {printf("Multiline comment are: %s\n", yytext);}
{Floating_no}     {printf("Floating number are: %s\n", yytext);}
{signed_num}      {printf("Signed numbers: %s\n", yytext);}
{delimeter}       {printf("Delimiter is: %s\n", yytext);}
{literal_str}     {printf("Literal string are: %s\n", yytext);}

%%

int main()
{
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}

//-?[0-9]+ ---> here this ? means sign either - or + and 0 occurrences of numbers or more
