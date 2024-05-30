#include "codegen.h"
#include <llvm-c/Analysis.h>
#include <llvm-c/ExecutionEngine.h>
#include <llvm-c/Target.h>
#include <llvm-c/TargetMachine.h>
#include <llvm-c/Transforms/PassManagerBuilder.h>
#include <llvm-c/Transforms/Scalar.h>

#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

static LLVMModuleRef module;
static LLVMBuilderRef builder;
static LLVMExecutionEngineRef engine;
static LLVMValueRef main_function;

void initialize_llvm() {
    LLVMInitializeNativeTarget();
    LLVMInitializeNativeAsmPrinter();
    LLVMInitializeNativeAsmParser();
    
    module = LLVMModuleCreateWithName("my_module");
    builder = LLVMCreateBuilder();
    
    LLVMPassManagerBuilderRef pass_manager_builder = LLVMPassManagerBuilderCreate();
    LLVMPassManagerRef pass_manager = LLVMCreateFunctionPassManagerForModule(module);
    LLVMPassManagerBuilderPopulateFunctionPassManager(pass_manager_builder, pass_manager);
    LLVMInitializeFunctionPassManager(pass_manager);
}

void finalize_llvm(const char *filename) {
    // Open the file for writing
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file for writing");
        exit(1);
    }
    
    // Print the LLVM module to the file
    char *error = NULL;
    LLVMPrintModuleToFile(module, filename, &error);
    
    // Close the file
    fclose(file);
    
    LLVMDisposeBuilder(builder);
    LLVMDisposeExecutionEngine(engine);
    LLVMDisposeModule(module);
}

LLVMValueRef codegen_number(ASTNode* node) {
    return LLVMConstReal(LLVMFloatType(), node->value.float_val);
}

LLVMValueRef codegen_string(ASTNode* node) {
    return LLVMBuildGlobalStringPtr(builder, node->value.str_val, "str");
}

LLVMValueRef codegen_variable(ASTNode* node, SymbolTable* symbol_table) {
    LLVMValueRef var = lookup_symbol(symbol_table, node->value.var_name);
    if (!var) {
        fprintf(stderr, "Undefined variable: %s\n", node->value.var_name);
        exit(1);
    }
    return LLVMBuildLoad(builder, var, node->value.var_name);
}

LLVMValueRef codegen_binary_op(ASTNode* node, SymbolTable* symbol_table) {
    LLVMValueRef left = generate_code(node->left, symbol_table);
    LLVMValueRef right = generate_code(node->right, symbol_table);
    if (strcmp(node->value.op, "+") == 0) {
        return LLVMBuildFAdd(builder, left, right, "addtmp");
    } else if (strcmp(node->value.op, "-") == 0) {
        return LLVMBuildFSub(builder, left, right, "subtmp");
    } else if (strcmp(node->value.op, "*") == 0) {
        return LLVMBuildFMul(builder, left, right, "multmp");
    } else if (strcmp(node->value.op, "/") == 0) {
        return LLVMBuildFDiv(builder, left, right, "divtmp");
    } else if (strcmp(node->value.op, "%") == 0) {
        return LLVMBuildFRem(builder, left, right, "modtmp");
    } else if (strcmp(node->value.op, "<") == 0) {
        return LLVMBuildFCmp(builder, LLVMRealOLT, left, right, "cmptmp");
    } else if (strcmp(node->value.op, "<=") == 0) {
        return LLVMBuildFCmp(builder, LLVMRealOLE, left, right, "cmptmp");
    } else if (strcmp(node->value.op, ">") == 0) {
        return LLVMBuildFCmp(builder, LLVMRealOGT, left, right, "cmptmp");
    } else if (strcmp(node->value.op, ">=") == 0) {
        return LLVMBuildFCmp(builder, LLVMRealOGE, left, right, "cmptmp");
    } else if (strcmp(node->value.op, "==") == 0) {
        return LLVMBuildFCmp(builder, LLVMRealOEQ, left, right, "cmptmp");
    } else if (strcmp(node->value.op, "!=") == 0) {
        return LLVMBuildFCmp(builder, LLVMRealONE, left, right, "cmptmp");
    } else if (strcmp(node->value.op, "&&") == 0) {
        return LLVMBuildAnd(builder, left, right, "andtmp");
    } else if (strcmp(node->value.op, "||") == 0) {
        return LLVMBuildOr(builder, left, right, "ortmp");
    } else {
        fprintf(stderr, "Unknown binary operator %s\n", node->value.op);
        exit(1);
    }
}

LLVMValueRef codegen_unary_op(ASTNode* node, SymbolTable* symbol_table) {
    LLVMValueRef operand = generate_code(node->left, symbol_table);
    if (strcmp(node->value.op, "-") == 0) {
        return LLVMBuildFNeg(builder, operand, "negtmp");
    } else if (strcmp(node->value.op, "!") == 0) {
        LLVMValueRef zero = LLVMConstReal(LLVMFloatType(), 0.0);
        return LLVMBuildFCmp(builder, LLVMRealOEQ, operand, zero, "nottmp");
    } else {
        fprintf(stderr, "Unknown unary operator %s\n", node->value.op);
        exit(1);
    }
}

LLVMValueRef codegen_assignment(ASTNode* node, SymbolTable* symbol_table) {
    LLVMValueRef value = generate_code(node->left, symbol_table);
    LLVMValueRef variable = lookup_symbol(symbol_table, node->value.var_name);
    if (!variable) {
        variable = LLVMBuildAlloca(builder, LLVMFloatType(), node->value.var_name);
        insert_symbol(symbol_table, node->value.var_name, variable);
    }
    LLVMBuildStore(builder, value, variable);
    return value;
}

LLVMValueRef codegen_print(ASTNode* node, SymbolTable* symbol_table) {
    LLVMValueRef value = generate_code(node->left, symbol_table);

    // Define the printf function type
    LLVMTypeRef printf_args_types[] = { LLVMPointerType(LLVMInt8Type(), 0) };
    LLVMTypeRef printf_type = LLVMFunctionType(LLVMInt32Type(), printf_args_types, 1, 1);
    LLVMValueRef printf_func = LLVMGetNamedFunction(module, "printf");
    
    if (!printf_func) {
        printf_func = LLVMAddFunction(module, "printf", printf_type);
    }

    if (node->left->type == NODE_TYPE_STRING) {
        LLVMValueRef formatStr = LLVMBuildGlobalStringPtr(builder, "%s\n", "formatStr");
        LLVMValueRef printf_args[] = { formatStr, value };
        LLVMBuildCall(builder, printf_func, printf_args, 2, "");
    } else if (node->left->type == NODE_TYPE_NUMBER || node->left->type == NODE_TYPE_VARIABLE) {
        LLVMTypeRef valueType = LLVMTypeOf(value);
        
        // Print float value
        LLVMValueRef formatStr = LLVMBuildGlobalStringPtr(builder, "%f\n", "formatStr");
        // Check if the value is a float and convert to double if necessary
        if (LLVMGetTypeKind(valueType) == LLVMFloatTypeKind) {
            value = LLVMBuildFPExt(builder, value, LLVMDoubleType(), "convToDouble");
        }
        LLVMValueRef printf_args[] = { formatStr, value };
        LLVMBuildCall(builder, printf_func, printf_args, 2, "");
        
    } else {
        fprintf(stderr, "Invalid argument type for print statement\n");
        exit(1);
    }

    return value;
}

LLVMValueRef codegen_function_def(ASTNode* node, SymbolTable* symbol_table) {
    LLVMTypeRef func_type = LLVMFunctionType(LLVMVoidType(), NULL, 0, 0);
    LLVMValueRef func = LLVMAddFunction(module, node->value.var_name, func_type);
    LLVMBasicBlockRef entry = LLVMAppendBasicBlock(func, "entry");
    LLVMPositionBuilderAtEnd(builder, entry);
    
    for (int i = 0; i < node->num_children; i++) {
        generate_code(node->children[i], symbol_table);
    }
    
    LLVMBuildRetVoid(builder);
    return func;
}

LLVMValueRef codegen_call(ASTNode* node, SymbolTable* symbol_table) {
    LLVMValueRef func = LLVMGetNamedFunction(module, node->value.var_name);
    if (!func) {
        fprintf(stderr, "Unknown function referenced: %s\n", node->value.var_name);
        exit(1);
    }
    return LLVMBuildCall(builder, func, NULL, 0, "");
}

LLVMValueRef codegen_if(ASTNode* node, SymbolTable* symbol_table) {
    LLVMValueRef condition = generate_code(node->left, symbol_table);
    LLVMBasicBlockRef then_block = LLVMAppendBasicBlock(main_function, "then");
    LLVMBasicBlockRef else_block = LLVMAppendBasicBlock(main_function, "else");
    LLVMBasicBlockRef merge_block = LLVMAppendBasicBlock(main_function, "ifcont");
    
    LLVMBuildCondBr(builder, condition, then_block, else_block);
    
    LLVMPositionBuilderAtEnd(builder, then_block);
    for (int i = 0; i < node->num_true; i++) {
        generate_code(node->true_body[i], symbol_table);
    }
    LLVMBuildBr(builder, merge_block);
    
    LLVMPositionBuilderAtEnd(builder, else_block);
    for (int i = 0; i < node->num_false; i++) {
        generate_code(node->false_body[i], symbol_table);
    }
    LLVMBuildBr(builder, merge_block);
    
    LLVMPositionBuilderAtEnd(builder, merge_block);
    
    return NULL;
}

LLVMValueRef codegen_while(ASTNode* node, SymbolTable* symbol_table) {
    LLVMBasicBlockRef cond_block = LLVMAppendBasicBlock(main_function, "loopcond");
    LLVMBasicBlockRef loop_block = LLVMAppendBasicBlock(main_function, "loop");
    LLVMBasicBlockRef after_block = LLVMAppendBasicBlock(main_function, "afterloop");
    
    LLVMBuildBr(builder, cond_block);
    
    LLVMPositionBuilderAtEnd(builder, cond_block);
    LLVMValueRef condition = generate_code(node->left, symbol_table);
    LLVMBuildCondBr(builder, condition, loop_block, after_block);
    
    LLVMPositionBuilderAtEnd(builder, loop_block);
    for (int i = 0; i < node->num_children; i++) {
        generate_code(node->children[i], symbol_table);
    }
    LLVMBuildBr(builder, cond_block);
    
    LLVMPositionBuilderAtEnd(builder, after_block);
    
    return NULL;
}

LLVMValueRef generate_code(ASTNode* node, SymbolTable* symbol_table) {
    switch (node->type) {
        case NODE_TYPE_NUMBER:
            return codegen_number(node);
        case NODE_TYPE_VARIABLE:
            return codegen_variable(node, symbol_table);
        case NODE_TYPE_BINARY_OP:
            return codegen_binary_op(node, symbol_table);
        case NODE_TYPE_UNARY_OP:
            return codegen_unary_op(node, symbol_table);
        case NODE_TYPE_ASSIGNMENT:
            return codegen_assignment(node, symbol_table);
        case NODE_TYPE_PRINT:
            return codegen_print(node, symbol_table);
        case NODE_TYPE_CALL:
            return codegen_call(node, symbol_table);
        case NODE_TYPE_IF:
            return codegen_if(node, symbol_table);
        case NODE_TYPE_WHILE:
            return codegen_while(node, symbol_table);
        case NODE_TYPE_STRING:
            return codegen_string(node);
        case NODE_TYPE_FUNCTION_DEF:
            return codegen_function_def(node, symbol_table);
        default:
            fprintf(stderr, "Unknown AST node type: %d\n", node->type);
            exit(1);
    }
}

LLVMValueRef gencode(ASTNode* root) {
    if (root->type == NODE_TYPE_MAIN_FUNC) {
        SymbolTable* local_symbol_table = create_symbol_table(1024);
        LLVMTypeRef func_type = LLVMFunctionType(LLVMVoidType(), NULL, 0, 0);
        main_function = LLVMAddFunction(module, "main", func_type);
        LLVMBasicBlockRef entry = LLVMAppendBasicBlock(main_function, "entry");
        LLVMPositionBuilderAtEnd(builder, entry);
        
        for (int i = 0; i < root->num_children; i++) {
            if (root->children[i]->type == NODE_TYPE_ASSIGNMENT) {
                LLVMValueRef var = LLVMBuildAlloca(builder, LLVMFloatType(), root->children[i]->value.var_name);
                insert_symbol(local_symbol_table, root->children[i]->value.var_name, var);
            }
        }

        for (int i = 0; i < root->num_children; i++) {
            generate_code(root->children[i], local_symbol_table);
        }
        
        LLVMBuildRetVoid(builder);
        destroy_symbol_table(local_symbol_table);
        
    } else if (root->type == NODE_TYPE_ROOT) {
    
        for (int i = 0; i < root->num_children - 1; i++) {
    		SymbolTable* local_symbol_table = create_symbol_table(1024);
            generate_code(root->children[i],local_symbol_table);
    		destroy_symbol_table(local_symbol_table);
        }
        
        gencode(root->children[root->num_children - 1]);
    }
}
#pragma GCC diagnostic warning "-Wdeprecated-declarations"

