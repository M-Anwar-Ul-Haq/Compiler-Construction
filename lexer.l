%{
#include "parser.tab.h"
%}

%option noyywrap

%%

":0"                        { return START_DIRECTIVE; }
":1"                        { return PRINT_DIRECTIVE; }
":2"                        { return WHILE_DIRECTIVE; }
":3"                        { return IF_DIRECTIVE; }
":4"                        { return ELSE_DIRECTIVE; }
"@"[0-9]                    { yylval.str_val = strdup(yytext + 1); return VARIABLE; }
"@@"[0-9][0-9]              { yylval.str_val = strdup(yytext + 1); return VARIABLE; }
";"                         { return SEMICOLON; }
"<"                         { return LESS_THAN; }
"<="                        { return LESS_THAN_EQUAL; }
">"                         { return GREATER_THAN; }
">="                        { return GREATER_THAN_EQUAL; }
"=="                        { return EQUALS; }
"!="                        { return NOT_EQUAL; }
"!"                         { return NOT; }
"&&"                        { return AND; }
"||"                        { return OR; }
"("                         { return OPEN_PAREN; }
")"                         { return CLOSE_PAREN; }
"="                         { return ASSIGN; }
"+"                         { return PLUS; }
"-"                         { return MINUS; }
"*"                         { return MULTIPLY; }
"/"                         { return DIVIDE; }
"%"                         { return MODULO; }
[0-9]+                      { yylval.int_val = atoi(yytext); return NUMBER; }
\"[^"]*\"                   { yylval.str_val = strdup(yytext + 1, yyleng - 2); return STRING; }
[ ]+                        { return SPACE; }
\n                          { return NEWLINE; }
.                           { return *yytext; } /* Any other character is a token itself */

%%

int yywrap() {
    return 1;
}
void yyerror(const char *s) {
    fprintf(stderr, "Parse error: %s\n", s);
    // You can add error handling here, like exiting the program
}

