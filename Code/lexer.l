%{
#include "ast.h"
#include "parser.tab.h"
#include "stdio.h"
#include "stdlib.h"
%}

%option noyywrap

%%

":0"                        { return START_DIRECTIVE; }
":1"                        { return PRINT_DIRECTIVE; }
":2"                        { return WHILE_DIRECTIVE; }
":3"                        { return IF_DIRECTIVE; }
":4"                        { return ELSE_DIRECTIVE; }
":5"                        { return CALL_FUNC; }
"$"[0-9]                    { yylval.str_val = strdup(yytext); return FUNCTION_DEF; }
"@"[0-9]                    { yylval.str_val = strdup(yytext); return VARIABLE; }
"@@"[0-9][0-9]              { yylval.str_val = strdup(yytext); return VARIABLE; }
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
[0-9]+                      { yylval.float_val = atof(yytext); return NUMBER; }
\"[^"]*\"                   { yytext[strlen(yytext)-1] = 0; yylval.str_val = strdup(yytext + 1); return STRING; }
[ ]                         { return SPACE; }
[  ][ ]*                    { fprintf(stderr, "Invalid spaces: %s at line %d\n", yytext,yylineno); exit(1); }
\n                          { yylineno++; return NEWLINE; }
\r			    { }
.                           { fprintf(stderr, "Invalid character: %s at line %d\n", yytext,yylineno); exit(1); }

%%


void yyerror(const char *s) {
    fprintf(stderr, "Error at line %d: %s\n", yylineno, s);
    fprintf(stderr, "Expected a valid expression.\n");
}
