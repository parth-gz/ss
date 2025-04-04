%{
#include <stdio.h>
#include <string.h>

char input_str[100]; // To store input string
%}

%%

[a-zA-Z]+ { 
    strcpy(input_str, yytext); // Store input string
}

.|\n  { /* Ignore other characters */ }

%%

int is_palindrome(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Palindrome
}

int main() {
    printf("Enter a string: ");
    yylex(); // Perform lexical analysis

    if (strlen(input_str) == 0) {
        printf("No valid input detected.\n");
        return 1;
    }

    if (is_palindrome(input_str)) {
        printf("The string \"%s\" is a palindrome.\n", input_str);
    } else {
        printf("The string \"%s\" is NOT a palindrome.\n", input_str);
    }

    return 0;
}

int yywrap() {
    return 1; // End of input
}
