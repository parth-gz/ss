assignFour.l 
%{ 
#include "y.tab.h" 
%} 
%% 
[0-9]
             { yylval = atoi(yytext); return N; } 
[ \t ]            
"\n"   
.                 
%% 
int yywrap() { 
return 1; 
} 


assignFour.y 
%{ 
{ return 0;} 
  {return yytext[0]; } 
#include <stdio.h> 
#include <stdlib.h> 
int yyerror(char *str); 
int yywrap(); 
%} 
%token N  
%left '+' '-' 
%left '*' '/' '%' 
%left '(' ')' 
%% 
A: E { printf("Result is = %d\n", $$); }; 
E: E '+' E   { $$ = $1 + $3; } 
| E '-' E   { $$ = $1 - $3; } 
| E '*' E   { $$ = $1 * $3; } 
| E '/' E   { $$ = $1 / $3; } 
| E '%' E   { $$ = $1 % $3; } 
| '(' E ')' { $$ = $2; } 
| N
 %% 
         { $$ = $1; } 
int yyerror(char *str) { 
printf("Invalid Expression\n"); 
return 0; 
} 
int main() { 
printf("Enter Arithmetic Expression: "); 
yyparse(); 
return 0; 
} 
Commands to Run Program 
1. lex assignFour.l 
2. yacc –d assignFour.y 
3. gcc lex.yy.c y.tab.c 
4. ./a.out