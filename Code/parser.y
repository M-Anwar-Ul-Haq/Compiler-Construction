%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
%}

%union {
    int int_val;
    char* str_val;
    float float_val;
}

%token START_DIRECTIVE PRINT_DIRECTIVE WHILE_DIRECTIVE IF_DIRECTIVE ELSE_DIRECTIVE <float_val> VARIABLE EQUALS LESS_THAN LESS_THAN_EQUAL GREATER_THAN GREATER_THAN_EQUAL NOT_EQUAL AND OR ASSIGN PLUS MINUS MULTIPLY DIVIDE MODULO <int_val> NUMBER <str_val> STRING SPACE NEWLINE OPEN_PAREN CLOSE_PAREN NOT FUNCTION_DEF CALL_FUNC

%left OR
%left AND
%left EQUALS NOT_EQUAL LESS_THAN LESS_THAN_EQUAL GREATER_THAN GREATER_THAN_EQUAL
%left PLUS MINUS
%left MULTIPLY DIVIDE MODULO
%right NOT
%nonassoc UNARY_MINUS compariosn_operator

%%

program: functions NEWLINE directive
       | directive
       ;


functions: one_function
         | functions NEWLINE one_function
         ;

one_function: FUNCTION_DEF NEWLINE statement_list
            ;

directive: START_DIRECTIVE NEWLINE statement_list
         ;

statement_list: statement 
              | statement_list statement 
              ;

statement: assignment NEWLINE
         | while_statement NEWLINE
         | if_statement NEWLINE
         | print NEWLINE
         | CALL_FUNC FUNCTION_DEF NEWLINE
         ;

assignment: VARIABLE ASSIGN expression
          ;

expression: term
          | expression PLUS term
          | expression MINUS term
          ;

term: factor
    | term MULTIPLY factor
    | term DIVIDE factor
    | term MODULO factor
    ;

factor: NUMBER
      | VARIABLE
      | MINUS factor
      | OPEN_PAREN expression CLOSE_PAREN
      ;

print: PRINT_DIRECTIVE print_expressions
     ;
     
print_expressions: VARIABLE
                 | STRING
                 ;

condition: expression comparison_operator expression
         | condition AND condition
         | condition OR condition
         | NOT condition
         | OPEN_PAREN condition CLOSE_PAREN
         ;

comparison_operator: EQUALS
                   | LESS_THAN
                   | LESS_THAN_EQUAL
                   | GREATER_THAN
                   | GREATER_THAN_EQUAL
                   | NOT_EQUAL
                   ;
      
in_statements: print
             | assignment
             | CALL_FUNC FUNCTION_DEF
             ;
            
w_statements: in_statements
            | w_statements SPACE in_statements
            ;
            
                      
while_statement: WHILE_DIRECTIVE condition SPACE while_statements
               ;

while_statements: w_statements SPACE if_statement SPACE w_statements
                | w_statements SPACE if_statement
                | if_statement SPACE w_statements
                | w_statements
                ;

if_statement: IF_DIRECTIVE condition SPACE if_statements
            ;
            
if_statements: conditional_statements else_condition
             ;

else_condition: /* Null */
              | ELSE_DIRECTIVE conditional_statements
              ;

conditional_statements: in_statements
                      | conditional_statements in_statements
                      ;


%%


int main() {
    yyparse();
    return 0;
}

