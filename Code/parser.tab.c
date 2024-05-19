/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ASTNode* root;
extern FILE* yyin;
int yylex(void);

#line 82 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER = 3,                     /* NUMBER  */
  YYSYMBOL_VARIABLE = 4,                   /* VARIABLE  */
  YYSYMBOL_STRING = 5,                     /* STRING  */
  YYSYMBOL_FUNCTION_DEF = 6,               /* FUNCTION_DEF  */
  YYSYMBOL_START_DIRECTIVE = 7,            /* START_DIRECTIVE  */
  YYSYMBOL_PRINT_DIRECTIVE = 8,            /* PRINT_DIRECTIVE  */
  YYSYMBOL_WHILE_DIRECTIVE = 9,            /* WHILE_DIRECTIVE  */
  YYSYMBOL_IF_DIRECTIVE = 10,              /* IF_DIRECTIVE  */
  YYSYMBOL_ELSE_DIRECTIVE = 11,            /* ELSE_DIRECTIVE  */
  YYSYMBOL_EQUALS = 12,                    /* EQUALS  */
  YYSYMBOL_LESS_THAN = 13,                 /* LESS_THAN  */
  YYSYMBOL_LESS_THAN_EQUAL = 14,           /* LESS_THAN_EQUAL  */
  YYSYMBOL_GREATER_THAN = 15,              /* GREATER_THAN  */
  YYSYMBOL_GREATER_THAN_EQUAL = 16,        /* GREATER_THAN_EQUAL  */
  YYSYMBOL_NOT_EQUAL = 17,                 /* NOT_EQUAL  */
  YYSYMBOL_AND = 18,                       /* AND  */
  YYSYMBOL_OR = 19,                        /* OR  */
  YYSYMBOL_ASSIGN = 20,                    /* ASSIGN  */
  YYSYMBOL_PLUS = 21,                      /* PLUS  */
  YYSYMBOL_MINUS = 22,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 23,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 24,                    /* DIVIDE  */
  YYSYMBOL_MODULO = 25,                    /* MODULO  */
  YYSYMBOL_CALL_FUNC = 26,                 /* CALL_FUNC  */
  YYSYMBOL_NEWLINE = 27,                   /* NEWLINE  */
  YYSYMBOL_SPACE = 28,                     /* SPACE  */
  YYSYMBOL_OPEN_PAREN = 29,                /* OPEN_PAREN  */
  YYSYMBOL_CLOSE_PAREN = 30,               /* CLOSE_PAREN  */
  YYSYMBOL_NOT = 31,                       /* NOT  */
  YYSYMBOL_UNARY_MINUS = 32,               /* UNARY_MINUS  */
  YYSYMBOL_YYACCEPT = 33,                  /* $accept  */
  YYSYMBOL_program = 34,                   /* program  */
  YYSYMBOL_functions = 35,                 /* functions  */
  YYSYMBOL_one_function = 36,              /* one_function  */
  YYSYMBOL_directive = 37,                 /* directive  */
  YYSYMBOL_statement_list = 38,            /* statement_list  */
  YYSYMBOL_statement = 39,                 /* statement  */
  YYSYMBOL_assignment = 40,                /* assignment  */
  YYSYMBOL_expression = 41,                /* expression  */
  YYSYMBOL_term = 42,                      /* term  */
  YYSYMBOL_factor = 43,                    /* factor  */
  YYSYMBOL_print_statement = 44,           /* print_statement  */
  YYSYMBOL_print_expressions = 45,         /* print_expressions  */
  YYSYMBOL_condition = 46,                 /* condition  */
  YYSYMBOL_comparison_operator = 47,       /* comparison_operator  */
  YYSYMBOL_in_statements = 48,             /* in_statements  */
  YYSYMBOL_w_statements = 49,              /* w_statements  */
  YYSYMBOL_while_statement = 50,           /* while_statement  */
  YYSYMBOL_while_statements = 51,          /* while_statements  */
  YYSYMBOL_if_statement = 52,              /* if_statement  */
  YYSYMBOL_conditional_statements = 53     /* conditional_statements  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   119

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  54
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  100

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   287


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    37,    37,    38,    41,    42,    45,    48,    55,    59,
      68,    69,    70,    71,    72,    75,    78,    79,    80,    83,
      84,    85,    86,    89,    90,    91,    92,    95,    98,    99,
     102,   103,   104,   105,   106,   109,   110,   111,   112,   113,
     114,   117,   118,   119,   122,   126,   135,   142,   154,   161,
     171,   174,   179,   189,   193
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "VARIABLE",
  "STRING", "FUNCTION_DEF", "START_DIRECTIVE", "PRINT_DIRECTIVE",
  "WHILE_DIRECTIVE", "IF_DIRECTIVE", "ELSE_DIRECTIVE", "EQUALS",
  "LESS_THAN", "LESS_THAN_EQUAL", "GREATER_THAN", "GREATER_THAN_EQUAL",
  "NOT_EQUAL", "AND", "OR", "ASSIGN", "PLUS", "MINUS", "MULTIPLY",
  "DIVIDE", "MODULO", "CALL_FUNC", "NEWLINE", "SPACE", "OPEN_PAREN",
  "CLOSE_PAREN", "NOT", "UNARY_MINUS", "$accept", "program", "functions",
  "one_function", "directive", "statement_list", "statement", "assignment",
  "expression", "term", "factor", "print_statement", "print_expressions",
  "condition", "comparison_operator", "in_statements", "w_statements",
  "while_statement", "while_statements", "if_statement",
  "conditional_statements", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-65)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      59,   -20,   -11,     5,    -7,   -65,   -65,    38,    38,   -65,
      59,     4,   101,     0,     0,    27,    38,   -65,     9,    18,
      52,    54,    38,   -65,   -65,     8,   -65,   -65,   -65,   -65,
     -65,     8,     0,     0,    75,    78,   -65,    25,    76,    58,
     -65,   -65,   -65,   -65,   -65,     8,    87,   -65,    46,    -4,
     -65,   -65,   -65,   -65,   -65,   -65,   -65,     8,     8,     8,
       8,     8,     8,     0,     0,    47,    48,   -65,    77,   -65,
     -65,    78,    78,    87,   -65,   -65,   -65,   -65,    36,    94,
     -65,   -65,   -65,    65,   -65,    84,   -65,     2,   -65,    47,
      48,    48,   -65,   -65,    85,    86,    48,    48,    48,    86
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     4,     3,     0,     0,     1,
       0,     0,     0,     0,     0,     0,     6,     8,     0,     0,
       0,     0,     7,     5,     2,     0,    28,    29,    27,    23,
      24,     0,     0,     0,     0,    16,    19,     0,     0,     0,
       9,    10,    13,    11,    12,     0,    15,    25,     0,     0,
      33,    35,    36,    37,    38,    39,    40,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    14,     0,    26,
      34,    17,    18,    30,    20,    21,    22,    31,    32,     0,
      42,    41,    44,    50,    46,     0,    53,    51,    43,     0,
       0,     0,    54,    45,    48,    49,    52,     0,     0,    47
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -65,   -65,   -65,   105,   106,   109,    61,    62,   -24,    53,
     -22,    64,   -65,   -14,   -65,   -64,   -15,   -65,   -65,   -48,
      28
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,     6,    16,    17,    80,    34,    35,
      36,    81,    28,    37,    59,    82,    83,    20,    84,    21,
      87
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      38,    46,    86,    29,    30,     9,    11,     7,    48,    47,
      12,    29,    30,    91,    63,    64,     8,    85,    49,    50,
      10,    68,    31,    92,    25,    93,    70,    86,    79,    32,
      31,    33,    92,    39,    93,    73,    41,    45,    74,    75,
      76,    94,    11,    63,    64,    42,    12,    13,    14,    77,
      78,    11,    11,    65,    63,    12,    12,    14,    51,    52,
      53,    54,    55,    56,    15,     1,     2,    57,    58,    18,
      18,    19,    19,    79,    79,    95,    69,    40,    18,    43,
      19,    44,    99,    40,    18,    67,    19,    51,    52,    53,
      54,    55,    56,    89,    63,    64,    57,    58,    57,    58,
      88,    60,    61,    62,    66,    26,    27,    69,    57,    58,
      71,    72,    90,    97,    98,    23,    24,    22,     0,    96
};

static const yytype_int8 yycheck[] =
{
      14,    25,    66,     3,     4,     0,     4,    27,    32,    31,
       8,     3,     4,    11,    18,    19,    27,    65,    32,    33,
      27,    45,    22,    87,    20,    89,    30,    91,    26,    29,
      22,    31,    96,     6,    98,    59,    27,    29,    60,    61,
      62,    89,     4,    18,    19,    27,     8,     9,    10,    63,
      64,     4,     4,    28,    18,     8,     8,    10,    12,    13,
      14,    15,    16,    17,    26,     6,     7,    21,    22,     7,
       8,     7,     8,    26,    26,    90,    30,    16,    16,    27,
      16,    27,    97,    22,    22,    27,    22,    12,    13,    14,
      15,    16,    17,    28,    18,    19,    21,    22,    21,    22,
       6,    23,    24,    25,    28,     4,     5,    30,    21,    22,
      57,    58,    28,    28,    28,    10,    10,     8,    -1,    91
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,     7,    34,    35,    36,    37,    27,    27,     0,
      27,     4,     8,     9,    10,    26,    38,    39,    40,    44,
      50,    52,    38,    36,    37,    20,     4,     5,    45,     3,
       4,    22,    29,    31,    41,    42,    43,    46,    46,     6,
      39,    27,    27,    27,    27,    29,    41,    43,    41,    46,
      46,    12,    13,    14,    15,    16,    17,    21,    22,    47,
      23,    24,    25,    18,    19,    28,    28,    27,    41,    30,
      30,    42,    42,    41,    43,    43,    43,    46,    46,    26,
      40,    44,    48,    49,    51,    52,    48,    53,     6,    28,
      28,    11,    48,    48,    52,    49,    53,    28,    28,    49
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    33,    34,    34,    35,    35,    36,    37,    38,    38,
      39,    39,    39,    39,    39,    40,    41,    41,    41,    42,
      42,    42,    42,    43,    43,    43,    43,    44,    45,    45,
      46,    46,    46,    46,    46,    47,    47,    47,    47,    47,
      47,    48,    48,    48,    49,    49,    50,    51,    51,    51,
      51,    52,    52,    53,    53
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     1,     1,     3,     3,     3,     1,     2,
       2,     2,     2,     2,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     1,     1,     2,     3,     2,     1,     1,
       3,     3,     3,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     3,     4,     5,     3,     3,
       1,     4,     6,     1,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: functions NEWLINE directive  */
#line 37 "parser.y"
                                     { root = (yyvsp[0].node); }
#line 1189 "parser.tab.c"
    break;

  case 3: /* program: directive  */
#line 38 "parser.y"
                   { root = (yyvsp[0].node); }
#line 1195 "parser.tab.c"
    break;

  case 4: /* functions: one_function  */
#line 41 "parser.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 1201 "parser.tab.c"
    break;

  case 5: /* functions: functions NEWLINE one_function  */
#line 42 "parser.y"
                                          { /* handle multiple functions if needed */ }
#line 1207 "parser.tab.c"
    break;

  case 6: /* one_function: FUNCTION_DEF NEWLINE statement_list  */
#line 45 "parser.y"
                                                  { (yyval.node) = create_function_def_node((yyvsp[-2].str_val), (yyvsp[0].node_list), (yyvsp[0].node_list) == NULL ? 0 : (*(yyvsp[0].node_list))->num_children); }
#line 1213 "parser.tab.c"
    break;

  case 7: /* directive: START_DIRECTIVE NEWLINE statement_list  */
#line 48 "parser.y"
                                                  {
                    int count = 0;
                    while ((yyvsp[0].node_list)[count] != NULL) count++;
                    (yyval.node) = create_statement_list_node((yyvsp[0].node_list), count);
                }
#line 1223 "parser.tab.c"
    break;

  case 8: /* statement_list: statement  */
#line 55 "parser.y"
                          { 
                    (yyval.node_list) = malloc(sizeof(ASTNode*));
                    (yyval.node_list)[0] = (yyvsp[0].node); 
                }
#line 1232 "parser.tab.c"
    break;

  case 9: /* statement_list: statement_list statement  */
#line 59 "parser.y"
                                         { 
                    int count = 0;
                    while ((yyvsp[-1].node_list)[count] != NULL) count++;
                    (yyval.node_list) = realloc((yyvsp[-1].node_list), (count + 2) * sizeof(ASTNode*));
                    (yyval.node_list)[count] = (yyvsp[0].node);
                    (yyval.node_list)[count + 1] = NULL;
                }
#line 1244 "parser.tab.c"
    break;

  case 10: /* statement: assignment NEWLINE  */
#line 68 "parser.y"
                              { (yyval.node) = (yyvsp[-1].node); }
#line 1250 "parser.tab.c"
    break;

  case 11: /* statement: while_statement NEWLINE  */
#line 69 "parser.y"
                                   { (yyval.node) = (yyvsp[-1].node); }
#line 1256 "parser.tab.c"
    break;

  case 12: /* statement: if_statement NEWLINE  */
#line 70 "parser.y"
                                { (yyval.node) = (yyvsp[-1].node); }
#line 1262 "parser.tab.c"
    break;

  case 13: /* statement: print_statement NEWLINE  */
#line 71 "parser.y"
                                   { (yyval.node) = (yyvsp[-1].node); }
#line 1268 "parser.tab.c"
    break;

  case 14: /* statement: CALL_FUNC FUNCTION_DEF NEWLINE  */
#line 72 "parser.y"
                                          { (yyval.node) = create_call_node((yyvsp[-1].str_val)); }
#line 1274 "parser.tab.c"
    break;

  case 15: /* assignment: VARIABLE ASSIGN expression  */
#line 75 "parser.y"
                                       { (yyval.node) = create_assignment_node((yyvsp[-2].str_val), (yyvsp[0].node)); }
#line 1280 "parser.tab.c"
    break;

  case 16: /* expression: term  */
#line 78 "parser.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1286 "parser.tab.c"
    break;

  case 17: /* expression: expression PLUS term  */
#line 79 "parser.y"
                                 { (yyval.node) = create_binary_op_node((yyvsp[-2].node), "+", (yyvsp[0].node)); }
#line 1292 "parser.tab.c"
    break;

  case 18: /* expression: expression MINUS term  */
#line 80 "parser.y"
                                  { (yyval.node) = create_binary_op_node((yyvsp[-2].node), "-", (yyvsp[0].node)); }
#line 1298 "parser.tab.c"
    break;

  case 19: /* term: factor  */
#line 83 "parser.y"
             { (yyval.node) = (yyvsp[0].node); }
#line 1304 "parser.tab.c"
    break;

  case 20: /* term: term MULTIPLY factor  */
#line 84 "parser.y"
                           { (yyval.node) = create_binary_op_node((yyvsp[-2].node), "*", (yyvsp[0].node)); }
#line 1310 "parser.tab.c"
    break;

  case 21: /* term: term DIVIDE factor  */
#line 85 "parser.y"
                         { (yyval.node) = create_binary_op_node((yyvsp[-2].node), "/", (yyvsp[0].node)); }
#line 1316 "parser.tab.c"
    break;

  case 22: /* term: term MODULO factor  */
#line 86 "parser.y"
                         { (yyval.node) = create_binary_op_node((yyvsp[-2].node), "%", (yyvsp[0].node)); }
#line 1322 "parser.tab.c"
    break;

  case 23: /* factor: NUMBER  */
#line 89 "parser.y"
               { (yyval.node) = create_number_node((yyvsp[0].float_val)); }
#line 1328 "parser.tab.c"
    break;

  case 24: /* factor: VARIABLE  */
#line 90 "parser.y"
                 { (yyval.node) = create_variable_node((yyvsp[0].str_val)); }
#line 1334 "parser.tab.c"
    break;

  case 25: /* factor: MINUS factor  */
#line 91 "parser.y"
                     { (yyval.node) = create_unary_op_node("-", (yyvsp[0].node)); }
#line 1340 "parser.tab.c"
    break;

  case 26: /* factor: OPEN_PAREN expression CLOSE_PAREN  */
#line 92 "parser.y"
                                          { (yyval.node) = (yyvsp[-1].node); }
#line 1346 "parser.tab.c"
    break;

  case 27: /* print_statement: PRINT_DIRECTIVE print_expressions  */
#line 95 "parser.y"
                                                   { (yyval.node) = create_print_node((yyvsp[0].node)); }
#line 1352 "parser.tab.c"
    break;

  case 28: /* print_expressions: VARIABLE  */
#line 98 "parser.y"
                            { (yyval.node) = create_variable_node((yyvsp[0].str_val)); }
#line 1358 "parser.tab.c"
    break;

  case 29: /* print_expressions: STRING  */
#line 99 "parser.y"
                          { (yyval.node) = create_string_node((yyvsp[0].str_val)); }
#line 1364 "parser.tab.c"
    break;

  case 30: /* condition: expression comparison_operator expression  */
#line 102 "parser.y"
                                                     { (yyval.node) = create_binary_op_node((yyvsp[-2].node), (yyvsp[-1].node)->value.op, (yyvsp[0].node)); }
#line 1370 "parser.tab.c"
    break;

  case 31: /* condition: condition AND condition  */
#line 103 "parser.y"
                                   { (yyval.node) = create_binary_op_node((yyvsp[-2].node), "&&", (yyvsp[0].node)); }
#line 1376 "parser.tab.c"
    break;

  case 32: /* condition: condition OR condition  */
#line 104 "parser.y"
                                  { (yyval.node) = create_binary_op_node((yyvsp[-2].node), "||", (yyvsp[0].node)); }
#line 1382 "parser.tab.c"
    break;

  case 33: /* condition: NOT condition  */
#line 105 "parser.y"
                         { (yyval.node) = create_unary_op_node("!", (yyvsp[0].node)); }
#line 1388 "parser.tab.c"
    break;

  case 34: /* condition: OPEN_PAREN condition CLOSE_PAREN  */
#line 106 "parser.y"
                                            { (yyval.node) = (yyvsp[-1].node); }
#line 1394 "parser.tab.c"
    break;

  case 35: /* comparison_operator: EQUALS  */
#line 109 "parser.y"
                            { (yyval.node) = create_comparison_op_node("="); }
#line 1400 "parser.tab.c"
    break;

  case 36: /* comparison_operator: LESS_THAN  */
#line 110 "parser.y"
                               { (yyval.node) = create_comparison_op_node("<"); }
#line 1406 "parser.tab.c"
    break;

  case 37: /* comparison_operator: LESS_THAN_EQUAL  */
#line 111 "parser.y"
                                     { (yyval.node) = create_comparison_op_node("<="); }
#line 1412 "parser.tab.c"
    break;

  case 38: /* comparison_operator: GREATER_THAN  */
#line 112 "parser.y"
                                  { (yyval.node) = create_comparison_op_node(">"); }
#line 1418 "parser.tab.c"
    break;

  case 39: /* comparison_operator: GREATER_THAN_EQUAL  */
#line 113 "parser.y"
                                        { (yyval.node) = create_comparison_op_node(">="); }
#line 1424 "parser.tab.c"
    break;

  case 40: /* comparison_operator: NOT_EQUAL  */
#line 114 "parser.y"
                               { (yyval.node) = create_comparison_op_node("!="); }
#line 1430 "parser.tab.c"
    break;

  case 41: /* in_statements: print_statement  */
#line 117 "parser.y"
                               { (yyval.node) = (yyvsp[0].node); }
#line 1436 "parser.tab.c"
    break;

  case 42: /* in_statements: assignment  */
#line 118 "parser.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1442 "parser.tab.c"
    break;

  case 43: /* in_statements: CALL_FUNC FUNCTION_DEF  */
#line 119 "parser.y"
                                      { (yyval.node) = create_call_node((yyvsp[0].str_val)); }
#line 1448 "parser.tab.c"
    break;

  case 44: /* w_statements: in_statements  */
#line 122 "parser.y"
                            { 
                (yyval.node_list) = malloc(sizeof(ASTNode*));
                (yyval.node_list)[0] = (yyvsp[0].node); 
              }
#line 1457 "parser.tab.c"
    break;

  case 45: /* w_statements: w_statements SPACE in_statements  */
#line 126 "parser.y"
                                               { 
                int count = 0;
                while ((yyvsp[-2].node_list)[count] != NULL) count++;
                (yyval.node_list) = realloc((yyvsp[-2].node_list), (count + 2) * sizeof(ASTNode*));
                (yyval.node_list)[count] = (yyvsp[0].node);
                (yyval.node_list)[count + 1] = NULL;
              }
#line 1469 "parser.tab.c"
    break;

  case 46: /* while_statement: WHILE_DIRECTIVE condition SPACE while_statements  */
#line 135 "parser.y"
                                                                  { 
                    int count = 0;
                    while ((yyvsp[0].node_list)[count] != NULL) count++;
                    (yyval.node) = create_while_node((yyvsp[-2].node), (yyvsp[0].node_list), count); 
               }
#line 1479 "parser.tab.c"
    break;

  case 47: /* while_statements: w_statements SPACE if_statement SPACE w_statements  */
#line 142 "parser.y"
                                                                     { 
                    int count1 = 0;
                    while ((yyvsp[-4].node_list)[count1] != NULL) count1++;
                    int count2 = 0;
                    while ((yyvsp[0].node_list)[count2] != NULL) count2++;
                    (yyval.node_list) = realloc((yyvsp[-4].node_list), (count1 + 1 + count2 + 1) * sizeof(ASTNode*));
                    (yyval.node_list)[count1] = (yyvsp[-2].node);
                    for (int i = 0; i < count2; i++) {
                        (yyval.node_list)[count1 + 1 + i] = (yyvsp[0].node_list)[i];
                    }
                    (yyval.node_list)[count1 + 1 + count2] = NULL;
                  }
#line 1496 "parser.tab.c"
    break;

  case 48: /* while_statements: w_statements SPACE if_statement  */
#line 154 "parser.y"
                                                  { 
                    int count = 0;
                    while ((yyvsp[-2].node_list)[count] != NULL) count++;
                    (yyval.node_list) = realloc((yyvsp[-2].node_list), (count + 2) * sizeof(ASTNode*));
                    (yyval.node_list)[count] = (yyvsp[0].node);
                    (yyval.node_list)[count + 1] = NULL;
                  }
#line 1508 "parser.tab.c"
    break;

  case 49: /* while_statements: if_statement SPACE w_statements  */
#line 161 "parser.y"
                                                  { 
                    int count = 0;
                    while ((yyvsp[0].node_list)[count] != NULL) count++;
                    (yyval.node_list) = malloc((1 + count + 1) * sizeof(ASTNode*));
                    (yyval.node_list)[0] = (yyvsp[-2].node);
                    for (int i = 0; i < count; i++) {
                        (yyval.node_list)[1 + i] = (yyvsp[0].node_list)[i];
                    }
                    (yyval.node_list)[1 + count] = NULL;
                  }
#line 1523 "parser.tab.c"
    break;

  case 50: /* while_statements: w_statements  */
#line 171 "parser.y"
                               { (yyval.node_list) = (yyvsp[0].node_list); }
#line 1529 "parser.tab.c"
    break;

  case 51: /* if_statement: IF_DIRECTIVE condition SPACE conditional_statements  */
#line 174 "parser.y"
                                                                  { 
                    int count = 0;
                    while ((yyvsp[0].node_list)[count] != NULL) count++;
                    (yyval.node) = create_if_node((yyvsp[-2].node), (yyvsp[0].node_list), count); 
            }
#line 1539 "parser.tab.c"
    break;

  case 52: /* if_statement: IF_DIRECTIVE condition SPACE conditional_statements ELSE_DIRECTIVE conditional_statements  */
#line 179 "parser.y"
                                                                                                        { 
                    int count = 0;
                    while ((yyvsp[-2].node_list)[count] != NULL) count++;
                    int count2 = 0;
                    while ((yyvsp[0].node_list)[count2] != NULL) count2++;
                    (yyval.node) = create_if_else_node((yyvsp[-4].node), (yyvsp[-2].node_list), count, (yyvsp[0].node_list), count2); 
            }
#line 1551 "parser.tab.c"
    break;

  case 53: /* conditional_statements: in_statements  */
#line 189 "parser.y"
                                      { 
                          (yyval.node_list) = malloc(sizeof(ASTNode*));
                          (yyval.node_list)[0] = (yyvsp[0].node); 
                      }
#line 1560 "parser.tab.c"
    break;

  case 54: /* conditional_statements: conditional_statements in_statements  */
#line 193 "parser.y"
                                                             { 
                          int count = 0;
                          while ((yyvsp[-1].node_list)[count] != NULL) count++;
                          (yyval.node_list) = realloc((yyvsp[-1].node_list), (count + 2) * sizeof(ASTNode*));
                          (yyval.node_list)[count] = (yyvsp[0].node);
                          (yyval.node_list)[count + 1] = NULL;
                      }
#line 1572 "parser.tab.c"
    break;


#line 1576 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 203 "parser.y"




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

