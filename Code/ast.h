#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <llvm-c/Core.h>
#include <llvm-c/Analysis.h>
#include <llvm-c/ExecutionEngine.h>
#include <llvm-c/Target.h>
#include <llvm-c/TargetMachine.h>
#include <llvm-c/Transforms/PassManagerBuilder.h>

typedef enum {
    NODE_TYPE_ROOT,	
    NODE_TYPE_NUMBER,
    NODE_TYPE_VARIABLE,
    NODE_TYPE_STRING,
    NODE_TYPE_BINARY_OP,
    NODE_TYPE_UNARY_OP,
    NODE_TYPE_ASSIGNMENT,
    NODE_TYPE_PRINT,
    NODE_TYPE_FUNCTION_DEF,
    NODE_TYPE_MAIN_FUNC,
    NODE_TYPE_CALL,
    NODE_TYPE_IF,
    NODE_TYPE_WHILE,
    NODE_TYPE_STATEMENT_LIST,
    NODE_TYPE_COMPARISON_OP,
} NodeType;

typedef struct ASTNode {
    NodeType type;
    struct ASTNode* left;
    struct ASTNode* right;
    union {
        float float_val;
        char* str_val;
        char* var_name;
        char* op;
    } value;
    struct ASTNode** children;
    int num_children;
    
    struct ASTNode** true_body; // For the true part of if-else
    int num_true;               // Number of nodes in the true part
    struct ASTNode** false_body; // For the false part of if-else
    int num_false; 
    
    LLVMValueRef llvm_value; // LLVM value for this node
    
} ASTNode;

ASTNode* create_number_node(float value);
ASTNode* create_variable_node(char* name);
ASTNode* create_string_node(char* value);
ASTNode* create_binary_op_node(ASTNode* left, char* op, ASTNode* right);
ASTNode* create_unary_op_node(char* op, ASTNode* operand);
ASTNode* create_assignment_node(char* var_name, ASTNode* value);
ASTNode* create_print_node(ASTNode* expr);
ASTNode* create_function_def_node(char* name, ASTNode** body, int num_children);
ASTNode* create_main_function_node(ASTNode** body, int num_children);
ASTNode* create_call_node(char* func_name);
ASTNode* create_if_node(ASTNode* condition, ASTNode** true_body, int num_true);
ASTNode* create_while_node(ASTNode* condition, ASTNode** body, int num_children);
ASTNode* create_comparison_op_node(char* op);
ASTNode* create_if_else_node(ASTNode* condition, ASTNode** true_body, int num_true, ASTNode** false_body, int num_false);
ASTNode* create_root_node(ASTNode** children, int num_children, ASTNode* main);
void print_ast(ASTNode* root);
void print_ast_node(ASTNode* node, int depth);


// Symbol table
typedef struct Symbol {
    char *name;
    LLVMValueRef value;
    struct Symbol *next;
} Symbol;

typedef struct SymbolTable {
    Symbol **table;
    size_t size;
} SymbolTable;

SymbolTable* create_symbol_table(size_t size);
void destroy_symbol_table(SymbolTable *symbol_table);
void insert_symbol(SymbolTable *symbol_table, const char *name, LLVMValueRef value);
LLVMValueRef lookup_symbol(SymbolTable *symbol_table, const char *name);

#endif

