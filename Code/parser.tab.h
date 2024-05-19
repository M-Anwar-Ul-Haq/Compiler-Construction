/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUMBER = 258,                  /* NUMBER  */
    VARIABLE = 259,                /* VARIABLE  */
    STRING = 260,                  /* STRING  */
    FUNCTION_DEF = 261,            /* FUNCTION_DEF  */
    START_DIRECTIVE = 262,         /* START_DIRECTIVE  */
    PRINT_DIRECTIVE = 263,         /* PRINT_DIRECTIVE  */
    WHILE_DIRECTIVE = 264,         /* WHILE_DIRECTIVE  */
    IF_DIRECTIVE = 265,            /* IF_DIRECTIVE  */
    ELSE_DIRECTIVE = 266,          /* ELSE_DIRECTIVE  */
    EQUALS = 267,                  /* EQUALS  */
    LESS_THAN = 268,               /* LESS_THAN  */
    LESS_THAN_EQUAL = 269,         /* LESS_THAN_EQUAL  */
    GREATER_THAN = 270,            /* GREATER_THAN  */
    GREATER_THAN_EQUAL = 271,      /* GREATER_THAN_EQUAL  */
    NOT_EQUAL = 272,               /* NOT_EQUAL  */
    AND = 273,                     /* AND  */
    OR = 274,                      /* OR  */
    ASSIGN = 275,                  /* ASSIGN  */
    PLUS = 276,                    /* PLUS  */
    MINUS = 277,                   /* MINUS  */
    MULTIPLY = 278,                /* MULTIPLY  */
    DIVIDE = 279,                  /* DIVIDE  */
    MODULO = 280,                  /* MODULO  */
    CALL_FUNC = 281,               /* CALL_FUNC  */
    NEWLINE = 282,                 /* NEWLINE  */
    SPACE = 283,                   /* SPACE  */
    OPEN_PAREN = 284,              /* OPEN_PAREN  */
    CLOSE_PAREN = 285,             /* CLOSE_PAREN  */
    NOT = 286,                     /* NOT  */
    UNARY_MINUS = 287              /* UNARY_MINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 12 "parser.y"

    int int_val;
    char* str_val;
    float float_val;
    ASTNode* node;
    ASTNode** node_list;

#line 104 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
