#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ASTNode* create_number_node(float value) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = NODE_TYPE_NUMBER;
    node->value.float_val = value;
    node->left = node->right = NULL;
    node->children = NULL;
    node->num_children = 0; 
    return node;
}

ASTNode* create_variable_node(char* name) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = NODE_TYPE_VARIABLE;
    node->value.var_name = strdup(name);
    node->left = node->right = NULL;
    node->children = NULL;
    node->num_children = 0;
    return node;
}

ASTNode* create_string_node(char* value) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = NODE_TYPE_STRING;
    node->value.str_val = strdup(value);
    node->left = node->right = NULL;
    node->children = NULL;
    node->num_children = 0;
    return node;
}

ASTNode* create_binary_op_node(ASTNode* left, char* op, ASTNode* right) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = NODE_TYPE_BINARY_OP;
    node->left = left;
    node->right = right;
    node->value.op = op;
    node->children = NULL;
    node->num_children = 0;
    return node;
}

ASTNode* create_unary_op_node(char* op, ASTNode* operand) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = NODE_TYPE_UNARY_OP;
    node->left = operand;
    node->right = NULL;
    node->value.op = op;
    node->children = NULL;
    node->num_children = 0;
    return node;
}

ASTNode* create_assignment_node(char* var_name, ASTNode* value) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = NODE_TYPE_ASSIGNMENT;
    node->value.var_name = strdup(var_name);
    node->left = value;
    node->right = NULL;
    node->children = NULL;
    node->num_children = 0;
    return node;
}

ASTNode* create_print_node(ASTNode* expr) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = NODE_TYPE_PRINT;
    node->left = expr;
    node->right = NULL;
    node->children = NULL;
    node->num_children = 0;
    return node;
}

ASTNode* create_main_function_node(ASTNode** body, int num_children) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = NODE_TYPE_MAIN_FUNC;
    node->value.var_name = strdup("Main");
    node->children = body;
    node->num_children = num_children;
    return node;
}

ASTNode* create_function_def_node(char* name, ASTNode** body, int num_children) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = NODE_TYPE_FUNCTION_DEF;
    node->value.var_name = strdup(name);
    node->children = body;
    node->num_children = num_children;
    return node;
}

ASTNode* create_call_node(char* func_name) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = NODE_TYPE_CALL;
    node->value.var_name = strdup(func_name);
    node->left = node->right = NULL;
    node->children = NULL;
    node->num_children = 0;
    return node;
}

ASTNode* create_if_node(ASTNode* condition, ASTNode** true_body, int num_true) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = NODE_TYPE_IF;
    node->left = condition;
    node->true_body = true_body;
    node->num_true = num_true;
    node->num_false=0;
    return node;
}

ASTNode* create_if_else_node(ASTNode* condition, ASTNode** true_body, int num_true, ASTNode** false_body, int num_false) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = NODE_TYPE_IF;
    node->left = condition;
    node->true_body = (ASTNode**)malloc(num_true * sizeof(ASTNode*));
    memcpy(node->true_body, true_body, num_true * sizeof(ASTNode*));
    node->num_true = num_true;
    node->false_body = (ASTNode**)malloc(num_false * sizeof(ASTNode*));
    memcpy(node->false_body, false_body, num_false * sizeof(ASTNode*));
    node->num_false = num_false;
    return node;
}

ASTNode* create_while_node(ASTNode* condition, ASTNode** body, int num_children) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = NODE_TYPE_WHILE;
    node->left = condition;
    node->children = body;
    node->num_children = num_children;
    return node;
}


ASTNode* create_comparison_op_node(char* op) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = NODE_TYPE_COMPARISON_OP;
    node->value.op = op;
    node->left = node->right = NULL;
    node->children = NULL;
    node->num_children = 0;
    return node;
}


ASTNode* create_root_node(ASTNode** children, int num_children, ASTNode* main) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = NODE_TYPE_ROOT;
    node->num_children = num_children+1;
    node->children = children;
    node->children[num_children] = main;
    return node;
}

void printSpace(int depth){
	for (int i = 0; i < depth; i++) {
        printf("  ");
    }
}

void print_ast_node(ASTNode* node, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }

    switch (node->type) {
        case NODE_TYPE_NUMBER:
            printf("Number: %f\n", node->value.float_val);
            break;
        case NODE_TYPE_VARIABLE:
            printf("Variable: %s\n", node->value.var_name);
            break;
        case NODE_TYPE_STRING:
            printf("String: %s\n", node->value.str_val);
            break;
        case NODE_TYPE_BINARY_OP:
            printf("Binary Operator: %s\n", node->value.op);
            printSpace(depth);
            printf("  Left:\n");
            print_ast_node(node->left, depth + 1);
            printSpace(depth);
            printf("  Right:\n");
            print_ast_node(node->right, depth + 1);
            break;
        case NODE_TYPE_UNARY_OP:
            printf("Unary Operator: %s\n", node->value.op);
            printSpace(depth);
            printf("  Operand:\n");
            print_ast_node(node->left, depth + 1);
            break;
        case NODE_TYPE_ASSIGNMENT:
            printf("Assignment: %s\n", node->value.var_name);
            printSpace(depth);
            printf("  Value:\n");
            print_ast_node(node->left, depth + 1);
            break;
        case NODE_TYPE_PRINT:
            printf("Print:\n");
            print_ast_node(node->left, depth + 1);
            break;
        case NODE_TYPE_MAIN_FUNC:
            printf("Function Definition: %s\n", node->value.var_name);
            for (int i = 0; i < node->num_children; i++) {
                print_ast_node(node->children[i], depth + 1);
            }
            break;
        case NODE_TYPE_FUNCTION_DEF:
            printf("Function Definition: %s\n", node->value.var_name);
            for (int i = 0; i < node->num_children; i++) {
                print_ast_node(node->children[i], depth + 1);
            }
            break;
        case NODE_TYPE_CALL:
            printf("Function Call: %s\n", node->value.var_name);
            break;
        case NODE_TYPE_IF:
            printf("If:\n");
            printSpace(depth);
            printf("  Condition:\n");
            print_ast_node(node->left, depth + 1);
            printSpace(depth);
            printf("  True Body:\n");
            for (int i = 0; i < node->num_true; i++) {
                print_ast_node(node->true_body[i], depth + 2);
            }
            
            printSpace(depth);
            printf("  False Body:\n");
            for (int i = 0; i < node->num_false; i++) {
                print_ast_node(node->false_body[i], depth + 2);
            }
            break;
        case NODE_TYPE_WHILE:
            printf("While:\n");
            printSpace(depth);
            printf("  Condition:\n");
            print_ast_node(node->left, depth + 1);
            printSpace(depth);
            printf("  Body:\n");
            for (int i = 0; i < node->num_children; i++) {
                print_ast_node(node->children[i], depth + 2);
            }
            break;
        case NODE_TYPE_ROOT:
            printf("Root:\n");
            for (int i = 0; i < node->num_children; i++) {
                print_ast_node(node->children[i], depth + 1);
                printf("\n");
            }
            break;
        case NODE_TYPE_COMPARISON_OP:
            printf("Comparison Operator: %s\n", node->value.op);
            break;
    }
}

void print_ast(ASTNode* root) {
    if (root == NULL) {
        printf("Empty AST\n");
    } else {
        print_ast_node(root, 0);
    }
}


// Symbol Table Functions
static unsigned hash(const char *str, size_t size) {
    unsigned hash = 0;
    while (*str) {
        hash = (hash << 5) + *str++;
    }
    return hash % size;
}

SymbolTable* create_symbol_table(size_t size) {
    SymbolTable *symbol_table = (SymbolTable*)malloc(sizeof(SymbolTable));
    symbol_table->table = (Symbol**)calloc(size, sizeof(Symbol*));
    symbol_table->size = size;
    return symbol_table;
}

void destroy_symbol_table(SymbolTable *symbol_table) {
    for (size_t i = 0; i < symbol_table->size; ++i) {
        Symbol *symbol = symbol_table->table[i];
        while (symbol) {
            Symbol *temp = symbol;
            symbol = symbol->next;
            free(temp->name);
            free(temp);
        }
    }
    free(symbol_table->table);
    free(symbol_table);
}

void insert_symbol(SymbolTable *symbol_table, const char *name, LLVMValueRef value) {
    unsigned index = hash(name, symbol_table->size);
    Symbol *symbol = (Symbol*)malloc(sizeof(Symbol));
    symbol->name = strdup(name);
    symbol->value = value;
    symbol->next = symbol_table->table[index];
    symbol_table->table[index] = symbol;
}

LLVMValueRef lookup_symbol(SymbolTable *symbol_table, const char *name) {
    unsigned index = hash(name, symbol_table->size);
    Symbol *symbol = symbol_table->table[index];
    while (symbol) {
        if (strcmp(symbol->name, name) == 0) {
            return symbol->value;
        }
        symbol = symbol->next;
    }
    return NULL;
}

