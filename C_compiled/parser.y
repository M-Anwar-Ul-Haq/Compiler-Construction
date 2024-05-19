%{
#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ASTNode* root;
extern FILE* yyin;
int yylex(void);
%}

%union {
    int int_val;
    char* str_val;
    float float_val;
    ASTNode* node;
    ASTNode** node_list;
}

%token <float_val> NUMBER
%token <str_val> VARIABLE STRING FUNCTION_DEF
%token START_DIRECTIVE PRINT_DIRECTIVE WHILE_DIRECTIVE IF_DIRECTIVE ELSE_DIRECTIVE EQUALS LESS_THAN LESS_THAN_EQUAL GREATER_THAN GREATER_THAN_EQUAL NOT_EQUAL AND OR ASSIGN PLUS MINUS MULTIPLY DIVIDE MODULO CALL_FUNC NEWLINE SPACE OPEN_PAREN CLOSE_PAREN NOT

%type <node> expression term factor assignment print_statement while_statement if_statement statement condition comparison_operator directive functions one_function print_expressions in_statements
%type <node_list> statement_list w_statements while_statements conditional_statements

%left OR
%left AND
%left EQUALS NOT_EQUAL LESS_THAN LESS_THAN_EQUAL GREATER_THAN GREATER_THAN_EQUAL
%left PLUS MINUS
%left MULTIPLY DIVIDE MODULO
%right NOT
%nonassoc UNARY_MINUS

%%

program: functions NEWLINE directive { root = $3; }
       | directive { root = $1; }
       ;

functions: one_function { $$ = $1; }
         | functions NEWLINE one_function { /* handle multiple functions if needed */ }
         ;

one_function: FUNCTION_DEF NEWLINE statement_list { $$ = create_function_def_node($1, $3, $3 == NULL ? 0 : (*$3)->num_children); }
            ;

directive: START_DIRECTIVE NEWLINE statement_list {
                    int count = 0;
                    while ($3[count] != NULL) count++;
                    $$ = create_statement_list_node($3, count);
                }
         ;

statement_list: statement { 
                    $$ = malloc(sizeof(ASTNode*));
                    $$[0] = $1; 
                }
              | statement_list statement { 
                    int count = 0;
                    while ($1[count] != NULL) count++;
                    $$ = realloc($1, (count + 2) * sizeof(ASTNode*));
                    $$[count] = $2;
                    $$[count + 1] = NULL;
                }
              ;

statement: assignment NEWLINE { $$ = $1; }
         | while_statement NEWLINE { $$ = $1; }
         | if_statement NEWLINE { $$ = $1; }
         | print_statement NEWLINE { $$ = $1; }
         | CALL_FUNC FUNCTION_DEF NEWLINE { $$ = create_call_node($2); }
         ;

assignment: VARIABLE ASSIGN expression { $$ = create_assignment_node($1, $3); }
          ;

expression: term { $$ = $1; }
          | expression PLUS term { $$ = create_binary_op_node($1, "+", $3); }
          | expression MINUS term { $$ = create_binary_op_node($1, "-", $3); }
          ;

term: factor { $$ = $1; }
    | term MULTIPLY factor { $$ = create_binary_op_node($1, "*", $3); }
    | term DIVIDE factor { $$ = create_binary_op_node($1, "/", $3); }
    | term MODULO factor { $$ = create_binary_op_node($1, "%", $3); }
    ;

factor: NUMBER { $$ = create_number_node($1); }
      | VARIABLE { $$ = create_variable_node($1); }
      | MINUS factor { $$ = create_unary_op_node("-", $2); }
      | OPEN_PAREN expression CLOSE_PAREN { $$ = $2; }
      ;

print_statement: PRINT_DIRECTIVE print_expressions { $$ = create_print_node($2); }
               ;
     
print_expressions: VARIABLE { $$ = create_variable_node($1); }
                 | STRING { $$ = create_string_node($1); }
                 ;

condition: expression comparison_operator expression { $$ = create_binary_op_node($1, $2->value.op, $3); }
         | condition AND condition { $$ = create_binary_op_node($1, "&&", $3); }
         | condition OR condition { $$ = create_binary_op_node($1, "||", $3); }
         | NOT condition { $$ = create_unary_op_node("!", $2); }
         | OPEN_PAREN condition CLOSE_PAREN { $$ = $2; }
         ;

comparison_operator: EQUALS { $$ = create_comparison_op_node("="); }
                   | LESS_THAN { $$ = create_comparison_op_node("<"); }
                   | LESS_THAN_EQUAL { $$ = create_comparison_op_node("<="); }
                   | GREATER_THAN { $$ = create_comparison_op_node(">"); }
                   | GREATER_THAN_EQUAL { $$ = create_comparison_op_node(">="); }
                   | NOT_EQUAL { $$ = create_comparison_op_node("!="); }
                   ;
      
in_statements: print_statement { $$ = $1; }
             | assignment { $$ = $1; }
             | CALL_FUNC FUNCTION_DEF { $$ = create_call_node($2); }
             ;
            
w_statements: in_statements { 
                $$ = malloc(sizeof(ASTNode*));
                $$[0] = $1; 
              }
            | w_statements SPACE in_statements { 
                int count = 0;
                while ($1[count] != NULL) count++;
                $$ = realloc($1, (count + 2) * sizeof(ASTNode*));
                $$[count] = $3;
                $$[count + 1] = NULL;
              }
            ;
            
while_statement: WHILE_DIRECTIVE condition SPACE while_statements { 
                    int count = 0;
                    while ($4[count] != NULL) count++;
                    $$ = create_while_node($2, $4, count); 
               }
               ;

while_statements: w_statements SPACE if_statement SPACE w_statements { 
                    int count1 = 0;
                    while ($1[count1] != NULL) count1++;
                    int count2 = 0;
                    while ($5[count2] != NULL) count2++;
                    $$ = realloc($1, (count1 + 1 + count2 + 1) * sizeof(ASTNode*));
                    $$[count1] = $3;
                    for (int i = 0; i < count2; i++) {
                        $$[count1 + 1 + i] = $5[i];
                    }
                    $$[count1 + 1 + count2] = NULL;
                  }
                | w_statements SPACE if_statement { 
                    int count = 0;
                    while ($1[count] != NULL) count++;
                    $$ = realloc($1, (count + 2) * sizeof(ASTNode*));
                    $$[count] = $3;
                    $$[count + 1] = NULL;
                  }
                | if_statement SPACE w_statements { 
                    int count = 0;
                    while ($3[count] != NULL) count++;
                    $$ = malloc((1 + count + 1) * sizeof(ASTNode*));
                    $$[0] = $1;
                    for (int i = 0; i < count; i++) {
                        $$[1 + i] = $3[i];
                    }
                    $$[1 + count] = NULL;
                  }
                | w_statements { $$ = $1; }
                ;

if_statement: IF_DIRECTIVE condition SPACE conditional_statements { 
                    int count = 0;
                    while ($4[count] != NULL) count++;
                    $$ = create_if_node($2, $4, count); 
            }
            | IF_DIRECTIVE condition SPACE conditional_statements ELSE_DIRECTIVE conditional_statements { 
                    int count = 0;
                    while ($4[count] != NULL) count++;
                    int count2 = 0;
                    while ($6[count2] != NULL) count2++;
                    $$ = create_if_else_node($2, $4, count, $6, count2); 
            }
            ;
            

conditional_statements: in_statements { 
                          $$ = malloc(sizeof(ASTNode*));
                          $$[0] = $1; 
                      }
                      | conditional_statements in_statements { 
                          int count = 0;
                          while ($1[count] != NULL) count++;
                          $$ = realloc($1, (count + 2) * sizeof(ASTNode*));
                          $$[count] = $2;
                          $$[count + 1] = NULL;
                      }
                      ;
                      
                      
%%



int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            fprintf(stderr, "Could not open file: %s\n", argv[1]);
            return 1;
        }
        yyin = file;
    }
    yyparse();
    printf("Parse done!\n");
    print_ast(root);
    return 0;
}

