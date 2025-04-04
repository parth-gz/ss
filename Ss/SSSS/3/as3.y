%{
#include<stdio.h>
#include<stdlib.h>
int yylex();
void  yyerror(char *str);
%}

%token datatype Identifier semicolon comma
%start s


%%
s:datatype var_list semicolon {printf("Valid Declaration \n");}
;
var_list : Identifier | var_list comma Identifier 
;
%%

void yyerror(char *str){
printf("Invalid string");
}

int main(){
printf("Enter input string");
yyparse();
return 0;
}

