assignmentTwo.l 
%{ 
#include <stdio.h> 
int wc = 0, lc = 0, cc = 0, dc = 0, vc = 0; 
%} 
%% 
[aeiouAEIOU]
 [0-9]
      { vc++; cc++; wc++;}  
             { dc++; cc++; }   
\n                 { lc++; cc++; }   
[ \t]+ 
            {
 cc += yyleng; }  
[^ \t\n]+     
%% 
int yywrap() 
{ 
} 
return 1; 
int main() 
{ 
     { wc++; cc += yyleng; }  
yyin = fopen("atwo.txt", "r"); 
yylex(); // Perform lexical analysis 
printf("Number of Lines : %d\n", lc); 
printf("Number of Words : %d\n", wc); 
printf("Number of Characters : %d\n", cc); 
printf("Number of Digits : %d\n", dc); 
printf("Number of Vowels : %d\n", vc); 
return 0; 
} 
atwo.txt 
This is 2 nd assignment a e i o u 
Commands to Run Program 
1. lex assignmentTwo.l 
2. gcc lex.yy.c 
3. ./a.out 
Assignment No 03