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
    node->children = true_body;
    node->num_children = num_true;
    return node;
}

ASTNode* create_if_else_node(ASTNode* condition, ASTNode** true_body, int num_true, ASTNode** false_body, int num_false) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = NODE_TYPE_IF;
    node->left = condition;
    node->children = (ASTNode**)malloc((num_true + num_false) * sizeof(ASTNode*));
    memcpy(node->children, true_body, num_true * sizeof(ASTNode*));
    memcpy(node->children + num_true, false_body, num_false * sizeof(ASTNode*));
    node->num_children = num_true + num_false;
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

ASTNode* create_statement_list_node(ASTNode** statements, int num_statements) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = NODE_TYPE_STATEMENT_LIST;
    node->children = statements;
    node->num_children = num_statements;
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
            printf("  Left:\n");
            print_ast_node(node->left, depth + 1);
            printf("  Right:\n");
            print_ast_node(node->right, depth + 1);
            break;
        case NODE_TYPE_UNARY_OP:
            printf("Unary Operator: %s\n", node->value.op);
            printf("  Operand:\n");
            print_ast_node(node->left, depth + 1);
            break;
        case NODE_TYPE_ASSIGNMENT:
            printf("Assignment: %s\n", node->value.var_name);
            printf("  Value:\n");
            print_ast_node(node->left, depth + 1);
            break;
        case NODE_TYPE_PRINT:
            printf("Print:\n");
            print_ast_node(node->left, depth + 1);
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
            printf("  Condition:\n");
            print_ast_node(node->left, depth + 1);
            printf("  True Body:\n");
            for (int i = 0; i < node->num_children; i++) {
                print_ast_node(node->children[i], depth + 2);
            }
            break;
        case NODE_TYPE_WHILE:
            printf("While:\n");
            printf("  Condition:\n");
            print_ast_node(node->left, depth + 1);
            printf("  Body:\n");
            for (int i = 0; i < node->num_children; i++) {
                print_ast_node(node->children[i], depth + 2);
            }
            break;
        case NODE_TYPE_STATEMENT_LIST:
            printf("Statement List:\n");
            for (int i = 0; i < node->num_children; i++) {
                print_ast_node(node->children[i], depth + 1);
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

