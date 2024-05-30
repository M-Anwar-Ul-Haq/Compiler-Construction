# Define commands
BISON = bison -d parser.y
FLEX = flex lexer.l
GCC_COMPILER = gcc -o compiler ast.c codegen.c lex.yy.c parser.tab.c -lfl -I/usr/lib/llvm-14/include -L/usr/lib/llvm-14/lib -lLLVM-14
RUN_COMPILER = ./compiler < input.txt
LLC = llc -filetype=obj -o output.o output.ll
GCC_EXEC = gcc -no-pie output.o -o my_comp -lm -lc
RUN_EXEC = ./my_comp

# Default target
all: my_comp

# Target to generate the parser
parser: 
	@$(BISON) > /dev/null 2>&1

# Target to generate the lexer
lexer: 
	@$(FLEX) > /dev/null 2>&1

# Target to compile the compiler
compiler: parser lexer
	@$(GCC_COMPILER) > /dev/null 2>&1

# Target to run the compiler and generate LLVM IR
llvm_ir: compiler
	@$(RUN_COMPILER) > /dev/null 2>&1

# Target to compile the LLVM IR to an object file
output: llvm_ir
	@$(LLC) > /dev/null 2>&1

# Target to link the final executable
my_comp: output
	@$(GCC_EXEC) > /dev/null 2>&1

# Clean up generated files
clean:
	@rm -f compiler lex.yy.c parser.tab.c parser.tab.h output.o my_comp output.ll parse_tree

# Phony targets
.PHONY: all parser lexer compiler llvm_ir output my_comp run clean

