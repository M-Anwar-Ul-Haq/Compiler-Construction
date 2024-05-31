%{
#include "ast.h"
#include "codegen.h"
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

%type <node> expression term factor assignment print_statement while_statement w_statements if_statement statement condition comparison_operator directive one_function print_expressions in_statements main
%type <node_list> statement_list while_statements conditional_statements functions

%left OR
%left AND
%left EQUALS NOT_EQUAL LESS_THAN LESS_THAN_EQUAL GREATER_THAN GREATER_THAN_EQUAL
%left PLUS MINUS
%left MULTIPLY DIVIDE MODULO
%right NOT
%nonassoc UNARY_MINUS

%%

program: functions NEWLINE main { 
	     int count = 0;
             while ($1[count] != NULL) count++;
	     root = create_root_node ($1, count, $3); 
	  }
       | main { root = $1; }
       ;

functions: one_function { 
                $$ = malloc(2 * sizeof(ASTNode*));
                $$[0] = $1;
                $$[1] = NULL;
            }
         | functions NEWLINE one_function { 
                int count = 0;
                while ($1[count] != NULL) count++;
                $$ = realloc($1, (count + 2) * sizeof(ASTNode*));
                $$[count] = $3;
                $$[count + 1] = NULL;
            }
         ;

one_function: FUNCTION_DEF NEWLINE statement_list {
 
	     		int count = 0;
             		while ($3[count] != NULL) count++;
                        $$ = create_function_def_node($1, $3, count); }
            ;
            
main: directive {
	   $$ = $1;
	}
    ;

directive: START_DIRECTIVE NEWLINE statement_list {
                    int count = 0;
                    while ($3[count] != NULL) count++;
                    $$ = create_main_function_node($3, count);
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

comparison_operator: EQUALS { $$ = create_comparison_op_node("=="); }
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
            
while_statement: WHILE_DIRECTIVE condition SPACE while_statements { 
                    int count = 0;
                    while ($4[count] != NULL) count++;
                    $$ = create_while_node($2, $4, count); 
               } ;

while_statements: w_statements { 
                    $$ = malloc(sizeof(ASTNode*));
                    $$[0] = $1; 
                  }
                | while_statements SPACE w_statements { 
                    int count = 0;
                    while ($1[count] != NULL) count++;
                    $$ = realloc($1, (count + 2) * sizeof(ASTNode*));
                    $$[count] = $3;
                    $$[count + 1] = NULL;
                }
              ;
              
w_statements: print_statement { $$ = $1; }
            | assignment { $$ = $1; }
            | if_statement { $$ = $1; }
            | CALL_FUNC FUNCTION_DEF { $$ = create_call_node($2); }
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

    initialize_llvm();
    
    yyparse();
    
    // Redirect stdout to the parse_tree file
    FILE *parse_tree_file = freopen("parse_tree", "w", stdout);
    if (!parse_tree_file) {
        fprintf(stderr, "Could not open parse_tree file for writing\n");
        return 1;
    }
    
    print_ast(root);
    
    // Restore stdout to its original state
    fflush(stdout);
    freopen("/dev/tty", "w", stdout); // This works for Unix-like systems; use "CON" on Windows
    
    gencode(root);
    
    finalize_llvm("output.ll");
    
    return 0;
}


