%{
    int char_count = 0, small_count = 0, cap_count = 0, line_count = 0, d_count = 0;
%}

small_word    [a-z]+
cap_word      [A-Z]+
end_of_line   \n
digit         [0-9]

%%

{small_word}      { small_count++; char_count += yyleng; }
{cap_word}        { cap_count++; char_count += yyleng; }
{end_of_line}     { char_count++; line_count++; }
{digit}           { d_count++; }
                  { char_count++; }

%%

int main() {
    yylex();

    printf("No. of chars are: %d\n", char_count);
    printf("Total lines: %d\n", line_count);
    printf("Total small words: %d\n", small_count);
    printf("Total capital words: %d\n", cap_count);
    printf("Total digits: %d\n", d_count);

    return 0;
}

int yywrap() {
    return 1;
}
