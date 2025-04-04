assignThree.l 
%{ 
#include "y.tab.h" 
%} 
%% 
"int"    { return INT; } 
"float"  { return FLOAT; } 
"char"   { return CHAR; } 
[a-zA-Z_][a-zA-Z0-9_]*  { return ID; } 
","   
";"
   { return COMMA; } 
      { 
return SEMICOLON; } 
[ \t\n]  { /* Ignore whitespace */ } 
.        { return yytext[0]; } 
%% 
int yywrap() { 
return 1; 
} 
assignThree.y 
%{ 
#include <stdio.h> 
#include <stdlib.h> 
int yyerror(char *str); 
int yywrap(); 
%} 
%token INT FLOAT CHAR ID COMMA SEMICOLON 
%% 
Stmt: Type VarList SEMICOLON     { printf("Valid Declaration\n"); } 
| error SEMICOLON       { printf("Invalid Declaration\n"); } 
 ;  
Type: INT | FLOAT | CHAR; 
VarList: ID 
| ID COMMA VarList; 
%% 
int yyerror(char *str) { 
printf("Syntax Error: %s\n", str); 
return 0; 
} 
int main() { 
printf("Enter a variable declaration:\n"); 
yyparse(); 
return 0; 
}Commands to Run Program 
1. lex assignThree.l 
2. yacc –d assignThree.y 
3. gcc lex.yy.c y.tab.c 
4. ./a.out 
