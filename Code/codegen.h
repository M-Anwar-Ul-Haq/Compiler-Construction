#ifndef CODEGEN_H
#define CODEGEN_H

#include "ast.h"

void initialize_llvm();
void finalize_llvm(const char *filename);
LLVMValueRef generate_code(ASTNode* node, SymbolTable* symbol_table);
LLVMValueRef gencode(ASTNode* root);

#endif

