/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 17 "src/parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"
#include "ast.h"
#include "interpreter.h"
#include "utils.h"

int yylex(void);
void yyerror(const char *s);

extern FILE *yyin;
extern int yylineno;

static int semantic_errors = 0;
static DataType current_decl_type = TYPE_UNKNOWN;
static ASTTopLevel *program_root = NULL;

void semantic_error(const char *msg) {
    fprintf(stderr, "Semantic Error at line %d: %s\n", yylineno, msg);
    semantic_errors++;
}

/* Line 371 of yacc.c  */
#line 93 "parser.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
/* Line 387 of yacc.c  */
#line 1 "src/parser.y"

    #include "symbol_table.h"
    #include "ast.h"

    typedef struct {
        DataType type;
        ASTExpr *node;
    } ExprAttr;

    typedef struct {
        int count;
        DataType types[MAX_PARAMS];
        ASTArgList *nodes;
    } ArgListAttr;


/* Line 387 of yacc.c  */
#line 142 "parser.tab.c"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT_LITERAL = 258,
     FLOAT_LITERAL = 259,
     CHAR_LITERAL = 260,
     STRING_LITERAL = 261,
     IDENTIFIER = 262,
     PROSTABONA = 263,
     UPOSHONGHAR = 264,
     DRISSHO = 265,
     SHURU = 266,
     SHESH = 267,
     SHONKHYA = 268,
     PURNOSHONKHYA = 269,
     BAKKYO = 270,
     OKKHYOR = 271,
     SHOBDO = 272,
     JOBDO = 273,
     JODI = 274,
     ONNOTHA = 275,
     CHOKRO = 276,
     SHAKTI = 277,
     BORGOMUL = 278,
     PHEROT = 279,
     ASSIGN = 280,
     PLUS = 281,
     MINUS = 282,
     MULT = 283,
     DIV = 284,
     MOD = 285,
     GT = 286,
     LT = 287,
     GEQ = 288,
     LEQ = 289,
     EQ = 290,
     NEQ = 291,
     SEMICOLON = 292,
     COMMA = 293,
     LPAREN = 294,
     RPAREN = 295,
     LOWER_THAN_ELSE = 296,
     UMINUS = 297
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 42 "src/parser.y"

    int ival;
    double fval;
    char cval;
    char *sval;
    ExprAttr expr;
    ArgListAttr args;
    ASTStmt *stmt;
    ASTIdentifierList *idlist;
    ASTTopLevel *top;


/* Line 387 of yacc.c  */
#line 212 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 240 "parser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   264

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNRULES -- Number of states.  */
#define YYNSTATES  144

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     7,     8,    11,    13,    15,    16,    24,
      28,    29,    31,    33,    37,    41,    42,    45,    48,    51,
      54,    57,    60,    63,    65,    67,    69,    70,    74,    75,
      79,    82,    85,    87,    91,    93,    97,    99,   103,   107,
     111,   115,   118,   121,   124,   127,   130,   133,   136,   142,
     150,   160,   165,   166,   168,   170,   174,   176,   178,   180,
     184,   188,   192,   196,   200,   204,   208,   212,   216,   220,
     224,   227,   231,   238,   243,   245,   247,   249
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      44,     0,    -1,     8,    45,     9,    -1,    -1,    45,    46,
      -1,    54,    -1,    47,    -1,    -1,    10,     7,    48,    39,
      50,    40,    49,    -1,    11,    53,    12,    -1,    -1,    51,
      -1,     7,    -1,    51,    38,     7,    -1,    11,    53,    12,
      -1,    -1,    53,    54,    -1,    55,    37,    -1,    61,    37,
      -1,    62,    37,    -1,    63,    37,    -1,    67,    37,    -1,
      64,    37,    -1,    65,    -1,    66,    -1,    52,    -1,    -1,
      13,    56,    58,    -1,    -1,    14,    57,    58,    -1,    15,
      59,    -1,    16,    60,    -1,     7,    -1,     7,    25,    71,
      -1,     7,    -1,     7,    25,     6,    -1,     7,    -1,     7,
      25,     5,    -1,     7,    25,    71,    -1,     7,    25,     6,
      -1,     7,    25,     5,    -1,    17,    71,    -1,    17,     6,
      -1,    17,     5,    -1,    18,     7,    -1,    24,    71,    -1,
      24,     6,    -1,    24,     5,    -1,    19,    39,    71,    40,
      54,    -1,    19,    39,    71,    40,    54,    20,    54,    -1,
      21,    39,    61,    37,    71,    37,    61,    40,    54,    -1,
       7,    39,    68,    40,    -1,    -1,    69,    -1,    70,    -1,
      69,    38,    70,    -1,    71,    -1,     6,    -1,     5,    -1,
      71,    26,    71,    -1,    71,    27,    71,    -1,    71,    28,
      71,    -1,    71,    29,    71,    -1,    71,    30,    71,    -1,
      71,    31,    71,    -1,    71,    32,    71,    -1,    71,    33,
      71,    -1,    71,    34,    71,    -1,    71,    35,    71,    -1,
      71,    36,    71,    -1,    27,    71,    -1,    39,    71,    40,
      -1,    22,    39,    71,    38,    71,    40,    -1,    23,    39,
      71,    40,    -1,    67,    -1,     3,    -1,     4,    -1,     7,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    91,    91,   107,   110,   117,   121,   129,   128,   145,
     153,   156,   163,   170,   180,   188,   191,   198,   202,   206,
     210,   214,   218,   222,   226,   230,   238,   237,   246,   245,
     253,   257,   264,   271,   283,   290,   300,   307,   317,   329,
     341,   356,   360,   364,   371,   381,   390,   399,   411,   418,
     428,   438,   464,   468,   475,   479,   501,   507,   513,   522,
     529,   536,   543,   550,   560,   568,   576,   584,   592,   600,
     608,   618,   623,   633,   643,   648,   653,   658
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT_LITERAL", "FLOAT_LITERAL",
  "CHAR_LITERAL", "STRING_LITERAL", "IDENTIFIER", "PROSTABONA",
  "UPOSHONGHAR", "DRISSHO", "SHURU", "SHESH", "SHONKHYA", "PURNOSHONKHYA",
  "BAKKYO", "OKKHYOR", "SHOBDO", "JOBDO", "JODI", "ONNOTHA", "CHOKRO",
  "SHAKTI", "BORGOMUL", "PHEROT", "ASSIGN", "PLUS", "MINUS", "MULT", "DIV",
  "MOD", "GT", "LT", "GEQ", "LEQ", "EQ", "NEQ", "SEMICOLON", "COMMA",
  "LPAREN", "RPAREN", "LOWER_THAN_ELSE", "UMINUS", "$accept", "program",
  "global_items", "global_item", "function_definition", "$@1",
  "function_body", "parameter_list_opt", "parameter_list", "block",
  "statement_list", "statement", "declaration", "$@2", "$@3",
  "numeric_declarator", "string_declarator", "char_declarator",
  "assignment", "print_stmt", "input_stmt", "return_stmt", "if_stmt",
  "loop_stmt", "function_call", "argument_list_opt", "argument_list",
  "argument", "expression", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    46,    48,    47,    49,
      50,    50,    51,    51,    52,    53,    53,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    56,    55,    57,    55,
      55,    55,    58,    58,    59,    59,    60,    60,    61,    61,
      61,    62,    62,    62,    63,    64,    64,    64,    65,    65,
      66,    67,    68,    68,    69,    69,    70,    70,    70,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     0,     2,     1,     1,     0,     7,     3,
       0,     1,     1,     3,     3,     0,     2,     2,     2,     2,
       2,     2,     2,     1,     1,     1,     0,     3,     0,     3,
       2,     2,     1,     3,     1,     3,     1,     3,     3,     3,
       3,     2,     2,     2,     2,     2,     2,     2,     5,     7,
       9,     4,     0,     1,     1,     3,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     3,     6,     4,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     0,     0,     1,     0,     2,     0,    15,    26,
      28,     0,     0,     0,     0,     0,     0,     0,     4,     6,
      25,     5,     0,     0,     0,     0,     0,    23,    24,     0,
       0,    52,     7,     0,     0,     0,    34,    30,    36,    31,
      75,    76,    43,    42,    77,     0,     0,     0,     0,    74,
      41,    44,     0,     0,    47,    46,    45,    17,    18,    19,
      20,    22,    21,    40,    39,    38,    58,    57,     0,    53,
      54,    56,     0,    14,    16,    32,    27,    29,     0,     0,
       0,     0,    70,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    51,     0,
      10,     0,    35,    37,     0,     0,    71,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,     0,     0,
      55,    12,     0,    11,    33,     0,    73,    48,     0,     0,
       0,     0,     0,     0,    15,     8,    13,    72,    49,     0,
       0,     0,     9,    50
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    18,    19,    72,   135,   122,   123,    20,
      33,    74,    22,    34,    35,    76,    37,    39,    23,    24,
      25,    26,    27,    28,    49,    68,    69,    70,    71
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -50
static const yytype_int16 yypact[] =
{
      -5,   -50,     5,    44,   -50,    10,   -50,     6,   -50,   -50,
     -50,    18,    35,     4,    38,   -27,     7,    11,   -50,   -50,
     -50,   -50,    29,    30,    34,    54,    70,   -50,   -50,    73,
      17,    82,   -50,   129,    65,    65,    78,   -50,    92,   -50,
     -50,   -50,   -50,   -50,    79,    80,    81,    25,    25,   -50,
     228,   -50,    25,   120,   -50,   -50,   228,   -50,   -50,   -50,
     -50,   -50,   -50,   -50,   -50,   228,   -50,   -50,    88,    93,
     -50,   228,    94,   -50,   -50,   107,   -50,   -50,   128,   130,
      25,    25,   -50,    66,    25,    25,    25,    25,    25,    25,
      25,    25,    25,    25,    25,   158,   124,   115,   -50,    82,
     147,    25,   -50,   -50,   203,   173,   -50,    83,    83,   -50,
     -50,   -50,    96,    96,    96,    96,    96,    96,   159,    25,
     -50,   -50,   127,   126,   228,    25,   -50,   149,   216,   160,
     172,   188,   159,   120,   -50,   -50,   -50,   -50,   -50,   141,
     144,   159,   -50,   -50
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,
      48,    -2,   -50,   -50,   -50,   161,   -50,   -50,   -49,   -50,
     -50,   -50,   -50,   -50,    -3,   -50,   -50,    98,   -11
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      29,    21,    50,     1,    97,     4,    56,    40,    41,    42,
      43,    44,    52,    32,    40,    41,    54,    55,    44,    65,
      40,    41,    63,    64,    44,    36,    45,    46,    40,    41,
      29,    47,    44,    45,    46,    30,    82,    83,    47,    45,
      46,    95,    38,    48,    47,    51,    53,    45,    46,    31,
      48,     5,    47,     6,     7,     8,    48,     9,    10,    11,
      12,    13,    14,    15,    48,    16,    57,    58,    17,   104,
     105,    59,    75,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   139,    40,    41,    66,    67,    44,
     124,    60,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    78,    45,    46,   106,    61,   128,    47,
      62,    86,    87,    88,   131,    29,   127,    79,    31,    80,
      81,    48,    84,    85,    86,    87,    88,    96,    98,    29,
     138,    99,   101,   100,   102,   103,     5,    29,    29,   143,
       8,    73,     9,    10,    11,    12,    13,    14,    15,    30,
      16,     5,   119,    17,   121,     8,   142,     9,    10,    11,
      12,    13,    14,    15,   130,    16,     5,   129,    17,   132,
       8,   134,     9,    10,    11,    12,    13,    14,    15,   136,
      16,   141,   140,    17,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,     0,    77,   120,   118,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
       0,     0,     0,   126,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,     0,     0,     0,   137,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
       0,   125,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,   133,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-50)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       3,     3,    13,     8,    53,     0,    17,     3,     4,     5,
       6,     7,    39,     7,     3,     4,     5,     6,     7,    30,
       3,     4,     5,     6,     7,     7,    22,    23,     3,     4,
      33,    27,     7,    22,    23,    25,    47,    48,    27,    22,
      23,    52,     7,    39,    27,     7,    39,    22,    23,    39,
      39,     7,    27,     9,    10,    11,    39,    13,    14,    15,
      16,    17,    18,    19,    39,    21,    37,    37,    24,    80,
      81,    37,     7,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,   133,     3,     4,     5,     6,     7,
     101,    37,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    25,    22,    23,    40,    37,   119,    27,
      37,    28,    29,    30,   125,   118,   118,    25,    39,    39,
      39,    39,    26,    27,    28,    29,    30,     7,    40,   132,
     132,    38,    25,    39,     6,     5,     7,   140,   141,   141,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    25,
      21,     7,    37,    24,     7,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    38,    21,     7,    40,    24,    20,
      11,    11,    13,    14,    15,    16,    17,    18,    19,     7,
      21,    40,   134,    24,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    35,    99,    40,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    40,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    40,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    38,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    44,    45,     0,     7,     9,    10,    11,    13,
      14,    15,    16,    17,    18,    19,    21,    24,    46,    47,
      52,    54,    55,    61,    62,    63,    64,    65,    66,    67,
      25,    39,     7,    53,    56,    57,     7,    59,     7,    60,
       3,     4,     5,     6,     7,    22,    23,    27,    39,    67,
      71,     7,    39,    39,     5,     6,    71,    37,    37,    37,
      37,    37,    37,     5,     6,    71,     5,     6,    68,    69,
      70,    71,    48,    12,    54,     7,    58,    58,    25,    25,
      39,    39,    71,    71,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    71,     7,    61,    40,    38,
      39,    25,     6,     5,    71,    71,    40,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    40,    37,
      70,     7,    50,    51,    71,    38,    40,    54,    71,    40,
      38,    71,    20,    37,    11,    49,     7,    40,    54,    61,
      53,    40,    12,    54
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 92 "src/parser.y"
    {
          program_root = (yyvsp[(2) - (3)].top);

          if (semantic_errors == 0) {
              printf("Semantic Analysis Successful: program is meaningful.\n");
              reset_history_log();
              interpret_program(program_root);
          } else {
              printf("Semantic Analysis finished with %d semantic error(s).\n", semantic_errors);
          }
      }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 107 "src/parser.y"
    {
          (yyval.top) = NULL;
      }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 111 "src/parser.y"
    {
          (yyval.top) = append_top((yyvsp[(1) - (2)].top), (yyvsp[(2) - (2)].top));
      }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 118 "src/parser.y"
    {
          (yyval.top) = make_top_stmt((yyvsp[(1) - (1)].stmt));
      }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 122 "src/parser.y"
    {
          (yyval.top) = (yyvsp[(1) - (1)].top);
      }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 129 "src/parser.y"
    {
          if (!declare_function((yyvsp[(2) - (2)].sval))) {
              semantic_error("function redeclared");
          }
          start_function_context((yyvsp[(2) - (2)].sval));
      }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 136 "src/parser.y"
    {
          ASTIdentifierList *params = (yyvsp[(5) - (7)].idlist);
          set_current_function_body((yyvsp[(7) - (7)].stmt));
          (yyval.top) = make_top_func((yyvsp[(2) - (7)].sval), params, (yyvsp[(7) - (7)].stmt));
          end_function_context();
      }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 146 "src/parser.y"
    {
          (yyval.stmt) = make_block_stmt((yyvsp[(2) - (3)].stmt));
      }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 153 "src/parser.y"
    {
          (yyval.idlist) = NULL;
      }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 157 "src/parser.y"
    {
          (yyval.idlist) = (yyvsp[(1) - (1)].idlist);
      }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 164 "src/parser.y"
    {
          if (!add_parameter_to_current_function((yyvsp[(1) - (1)].sval), TYPE_FLOAT)) {
              semantic_error("parameter redeclared");
          }
          (yyval.idlist) = make_identifier_list((yyvsp[(1) - (1)].sval));
      }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 171 "src/parser.y"
    {
          if (!add_parameter_to_current_function((yyvsp[(3) - (3)].sval), TYPE_FLOAT)) {
              semantic_error("parameter redeclared");
          }
          (yyval.idlist) = append_identifier((yyvsp[(1) - (3)].idlist), (yyvsp[(3) - (3)].sval));
      }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 181 "src/parser.y"
    {
          (yyval.stmt) = make_block_stmt((yyvsp[(2) - (3)].stmt));
      }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 188 "src/parser.y"
    {
          (yyval.stmt) = NULL;
      }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 192 "src/parser.y"
    {
          (yyval.stmt) = append_stmt((yyvsp[(1) - (2)].stmt), (yyvsp[(2) - (2)].stmt));
      }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 199 "src/parser.y"
    {
          (yyval.stmt) = (yyvsp[(1) - (2)].stmt);
      }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 203 "src/parser.y"
    {
          (yyval.stmt) = (yyvsp[(1) - (2)].stmt);
      }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 207 "src/parser.y"
    {
          (yyval.stmt) = (yyvsp[(1) - (2)].stmt);
      }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 211 "src/parser.y"
    {
          (yyval.stmt) = (yyvsp[(1) - (2)].stmt);
      }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 215 "src/parser.y"
    {
          (yyval.stmt) = make_expr_stmt((yyvsp[(1) - (2)].expr).node);
      }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 219 "src/parser.y"
    {
          (yyval.stmt) = (yyvsp[(1) - (2)].stmt);
      }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 223 "src/parser.y"
    {
          (yyval.stmt) = (yyvsp[(1) - (1)].stmt);
      }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 227 "src/parser.y"
    {
          (yyval.stmt) = (yyvsp[(1) - (1)].stmt);
      }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 231 "src/parser.y"
    {
          (yyval.stmt) = (yyvsp[(1) - (1)].stmt);
      }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 238 "src/parser.y"
    {
          current_decl_type = TYPE_INT;
      }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 242 "src/parser.y"
    {
          (yyval.stmt) = (yyvsp[(3) - (3)].stmt);
      }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 246 "src/parser.y"
    {
          current_decl_type = TYPE_FLOAT;
      }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 250 "src/parser.y"
    {
          (yyval.stmt) = (yyvsp[(3) - (3)].stmt);
      }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 254 "src/parser.y"
    {
          (yyval.stmt) = (yyvsp[(2) - (2)].stmt);
      }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 258 "src/parser.y"
    {
          (yyval.stmt) = (yyvsp[(2) - (2)].stmt);
      }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 265 "src/parser.y"
    {
          if (!declare_variable((yyvsp[(1) - (1)].sval), current_decl_type, SYM_VAR)) {
              semantic_error("variable redeclared in same scope");
          }
          (yyval.stmt) = make_decl_stmt(current_decl_type, (yyvsp[(1) - (1)].sval), NULL);
      }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 272 "src/parser.y"
    {
          if (!declare_variable((yyvsp[(1) - (3)].sval), current_decl_type, SYM_VAR)) {
              semantic_error("variable redeclared in same scope");
          } else if (!can_assign(current_decl_type, (yyvsp[(3) - (3)].expr).type)) {
              semantic_error("type mismatch in declaration assignment");
          }
          (yyval.stmt) = make_decl_stmt(current_decl_type, (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].expr).node);
      }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 284 "src/parser.y"
    {
          if (!declare_variable((yyvsp[(1) - (1)].sval), TYPE_STRING, SYM_VAR)) {
              semantic_error("variable redeclared in same scope");
          }
          (yyval.stmt) = make_decl_stmt(TYPE_STRING, (yyvsp[(1) - (1)].sval), NULL);
      }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 291 "src/parser.y"
    {
          if (!declare_variable((yyvsp[(1) - (3)].sval), TYPE_STRING, SYM_VAR)) {
              semantic_error("variable redeclared in same scope");
          }
          (yyval.stmt) = make_decl_string_stmt((yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].sval));
      }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 301 "src/parser.y"
    {
          if (!declare_variable((yyvsp[(1) - (1)].sval), TYPE_CHAR, SYM_VAR)) {
              semantic_error("variable redeclared in same scope");
          }
          (yyval.stmt) = make_decl_stmt(TYPE_CHAR, (yyvsp[(1) - (1)].sval), NULL);
      }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 308 "src/parser.y"
    {
          if (!declare_variable((yyvsp[(1) - (3)].sval), TYPE_CHAR, SYM_VAR)) {
              semantic_error("variable redeclared in same scope");
          }
          (yyval.stmt) = make_decl_char_stmt((yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].cval));
      }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 318 "src/parser.y"
    {
          Symbol *s = lookup_symbol((yyvsp[(1) - (3)].sval));
          if (s == NULL) {
              semantic_error("assignment to undeclared variable");
          } else if (s->kind == SYM_CONST) {
              semantic_error("cannot modify constant");
          } else if (!can_assign(s->type, (yyvsp[(3) - (3)].expr).type)) {
              semantic_error("type mismatch in assignment");
          }
          (yyval.stmt) = make_assign_expr_stmt((yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].expr).node);
      }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 330 "src/parser.y"
    {
          Symbol *s = lookup_symbol((yyvsp[(1) - (3)].sval));
          if (s == NULL) {
              semantic_error("assignment to undeclared variable");
          } else if (s->kind == SYM_CONST) {
              semantic_error("cannot modify constant");
          } else if (!can_assign(s->type, TYPE_STRING)) {
              semantic_error("type mismatch in assignment");
          }
          (yyval.stmt) = make_assign_string_stmt((yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].sval));
      }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 342 "src/parser.y"
    {
          Symbol *s = lookup_symbol((yyvsp[(1) - (3)].sval));
          if (s == NULL) {
              semantic_error("assignment to undeclared variable");
          } else if (s->kind == SYM_CONST) {
              semantic_error("cannot modify constant");
          } else if (!can_assign(s->type, TYPE_CHAR)) {
              semantic_error("type mismatch in assignment");
          }
          (yyval.stmt) = make_assign_char_stmt((yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].cval));
      }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 357 "src/parser.y"
    {
          (yyval.stmt) = make_print_expr_stmt((yyvsp[(2) - (2)].expr).node);
      }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 361 "src/parser.y"
    {
          (yyval.stmt) = make_print_string_stmt((yyvsp[(2) - (2)].sval));
      }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 365 "src/parser.y"
    {
          (yyval.stmt) = make_print_char_stmt((yyvsp[(2) - (2)].cval));
      }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 372 "src/parser.y"
    {
          if (lookup_symbol((yyvsp[(2) - (2)].sval)) == NULL) {
              semantic_error("input target is undeclared");
          }
          (yyval.stmt) = make_input_stmt((yyvsp[(2) - (2)].sval));
      }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 382 "src/parser.y"
    {
          if (!in_function_context()) {
              semantic_error("pherot used outside function");
          } else if (!register_return_type((yyvsp[(2) - (2)].expr).type)) {
              semantic_error("inconsistent function return type");
          }
          (yyval.stmt) = make_return_expr_stmt((yyvsp[(2) - (2)].expr).node);
      }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 391 "src/parser.y"
    {
          if (!in_function_context()) {
              semantic_error("pherot used outside function");
          } else if (!register_return_type(TYPE_STRING)) {
              semantic_error("inconsistent function return type");
          }
          (yyval.stmt) = make_return_string_stmt((yyvsp[(2) - (2)].sval));
      }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 400 "src/parser.y"
    {
          if (!in_function_context()) {
              semantic_error("pherot used outside function");
          } else if (!register_return_type(TYPE_CHAR)) {
              semantic_error("inconsistent function return type");
          }
          (yyval.stmt) = make_return_char_stmt((yyvsp[(2) - (2)].cval));
      }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 412 "src/parser.y"
    {
          if (!is_numeric_type((yyvsp[(3) - (5)].expr).type)) {
              semantic_error("if condition must be numeric/boolean-like");
          }
          (yyval.stmt) = make_if_stmt((yyvsp[(3) - (5)].expr).node, (yyvsp[(5) - (5)].stmt), NULL);
      }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 419 "src/parser.y"
    {
          if (!is_numeric_type((yyvsp[(3) - (7)].expr).type)) {
              semantic_error("if condition must be numeric/boolean-like");
          }
          (yyval.stmt) = make_if_stmt((yyvsp[(3) - (7)].expr).node, (yyvsp[(5) - (7)].stmt), (yyvsp[(7) - (7)].stmt));
      }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 429 "src/parser.y"
    {
          if (!is_numeric_type((yyvsp[(5) - (9)].expr).type)) {
              semantic_error("loop condition must be numeric/boolean-like");
          }
          (yyval.stmt) = make_loop_stmt((yyvsp[(3) - (9)].stmt), (yyvsp[(5) - (9)].expr).node, (yyvsp[(7) - (9)].stmt), (yyvsp[(9) - (9)].stmt));
      }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 439 "src/parser.y"
    {
          Symbol *f = lookup_function((yyvsp[(1) - (4)].sval));
          if (f == NULL) {
              semantic_error("call to undeclared function");
              (yyval.expr).type = TYPE_UNKNOWN;
          } else {
              if (f->param_count != (yyvsp[(3) - (4)].args).count) {
                  semantic_error("wrong number of function arguments");
              } else {
                  int i;
                  for (i = 0; i < f->param_count && i < (yyvsp[(3) - (4)].args).count; i++) {
                      if (!can_assign(f->param_types[i], (yyvsp[(3) - (4)].args).types[i])) {
                          semantic_error("function argument type mismatch");
                          break;
                      }
                  }
              }
              (yyval.expr).type = f->return_type;
          }
          (yyval.expr).node = make_call_expr((yyvsp[(1) - (4)].sval), (yyvsp[(3) - (4)].args).nodes);
      }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 464 "src/parser.y"
    {
          (yyval.args).count = 0;
          (yyval.args).nodes = NULL;
      }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 469 "src/parser.y"
    {
          (yyval.args) = (yyvsp[(1) - (1)].args);
      }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 476 "src/parser.y"
    {
          (yyval.args) = (yyvsp[(1) - (1)].args);
      }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 480 "src/parser.y"
    {
          int i;
          (yyval.args) = (yyvsp[(1) - (3)].args);
          if ((yyval.args).count < MAX_PARAMS) {
              for (i = 0; i < (yyvsp[(3) - (3)].args).count; i++) {
                  (yyval.args).types[(yyval.args).count++] = (yyvsp[(3) - (3)].args).types[i];
              }
          }
          if ((yyvsp[(3) - (3)].args).nodes != NULL) {
              if ((yyval.args).nodes == NULL) {
                  (yyval.args).nodes = (yyvsp[(3) - (3)].args).nodes;
              } else {
                  ASTArgList *cur = (yyval.args).nodes;
                  while (cur->next != NULL) cur = cur->next;
                  cur->next = (yyvsp[(3) - (3)].args).nodes;
              }
          }
      }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 502 "src/parser.y"
    {
          (yyval.args).count = 1;
          (yyval.args).types[0] = (yyvsp[(1) - (1)].expr).type;
          (yyval.args).nodes = make_arg_list((yyvsp[(1) - (1)].expr).node);
      }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 508 "src/parser.y"
    {
          (yyval.args).count = 1;
          (yyval.args).types[0] = TYPE_STRING;
          (yyval.args).nodes = make_arg_list(make_string_expr((yyvsp[(1) - (1)].sval)));
      }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 514 "src/parser.y"
    {
          (yyval.args).count = 1;
          (yyval.args).types[0] = TYPE_CHAR;
          (yyval.args).nodes = make_arg_list(make_char_expr((yyvsp[(1) - (1)].cval)));
      }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 523 "src/parser.y"
    {
          DataType t = arithmetic_result_type((yyvsp[(1) - (3)].expr).type, (yyvsp[(3) - (3)].expr).type);
          if (t == TYPE_UNKNOWN) semantic_error("invalid operands for +");
          (yyval.expr).type = t;
          (yyval.expr).node = make_binary_expr(OP_ADD, (yyvsp[(1) - (3)].expr).node, (yyvsp[(3) - (3)].expr).node);
      }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 530 "src/parser.y"
    {
          DataType t = arithmetic_result_type((yyvsp[(1) - (3)].expr).type, (yyvsp[(3) - (3)].expr).type);
          if (t == TYPE_UNKNOWN) semantic_error("invalid operands for -");
          (yyval.expr).type = t;
          (yyval.expr).node = make_binary_expr(OP_SUB, (yyvsp[(1) - (3)].expr).node, (yyvsp[(3) - (3)].expr).node);
      }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 537 "src/parser.y"
    {
          DataType t = arithmetic_result_type((yyvsp[(1) - (3)].expr).type, (yyvsp[(3) - (3)].expr).type);
          if (t == TYPE_UNKNOWN) semantic_error("invalid operands for *");
          (yyval.expr).type = t;
          (yyval.expr).node = make_binary_expr(OP_MUL, (yyvsp[(1) - (3)].expr).node, (yyvsp[(3) - (3)].expr).node);
      }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 544 "src/parser.y"
    {
          DataType t = arithmetic_result_type((yyvsp[(1) - (3)].expr).type, (yyvsp[(3) - (3)].expr).type);
          if (t == TYPE_UNKNOWN) semantic_error("invalid operands for /");
          (yyval.expr).type = TYPE_FLOAT;
          (yyval.expr).node = make_binary_expr(OP_DIV, (yyvsp[(1) - (3)].expr).node, (yyvsp[(3) - (3)].expr).node);
      }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 551 "src/parser.y"
    {
          if ((yyvsp[(1) - (3)].expr).type != TYPE_INT || (yyvsp[(3) - (3)].expr).type != TYPE_INT) {
              semantic_error("modulo requires integer operands");
              (yyval.expr).type = TYPE_UNKNOWN;
          } else {
              (yyval.expr).type = TYPE_INT;
          }
          (yyval.expr).node = make_binary_expr(OP_MOD, (yyvsp[(1) - (3)].expr).node, (yyvsp[(3) - (3)].expr).node);
      }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 561 "src/parser.y"
    {
          if (!is_numeric_type((yyvsp[(1) - (3)].expr).type) || !is_numeric_type((yyvsp[(3) - (3)].expr).type)) {
              semantic_error("comparison requires numeric operands");
          }
          (yyval.expr).type = TYPE_INT;
          (yyval.expr).node = make_binary_expr(OP_GT, (yyvsp[(1) - (3)].expr).node, (yyvsp[(3) - (3)].expr).node);
      }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 569 "src/parser.y"
    {
          if (!is_numeric_type((yyvsp[(1) - (3)].expr).type) || !is_numeric_type((yyvsp[(3) - (3)].expr).type)) {
              semantic_error("comparison requires numeric operands");
          }
          (yyval.expr).type = TYPE_INT;
          (yyval.expr).node = make_binary_expr(OP_LT, (yyvsp[(1) - (3)].expr).node, (yyvsp[(3) - (3)].expr).node);
      }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 577 "src/parser.y"
    {
          if (!is_numeric_type((yyvsp[(1) - (3)].expr).type) || !is_numeric_type((yyvsp[(3) - (3)].expr).type)) {
              semantic_error("comparison requires numeric operands");
          }
          (yyval.expr).type = TYPE_INT;
          (yyval.expr).node = make_binary_expr(OP_GEQ, (yyvsp[(1) - (3)].expr).node, (yyvsp[(3) - (3)].expr).node);
      }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 585 "src/parser.y"
    {
          if (!is_numeric_type((yyvsp[(1) - (3)].expr).type) || !is_numeric_type((yyvsp[(3) - (3)].expr).type)) {
              semantic_error("comparison requires numeric operands");
          }
          (yyval.expr).type = TYPE_INT;
          (yyval.expr).node = make_binary_expr(OP_LEQ, (yyvsp[(1) - (3)].expr).node, (yyvsp[(3) - (3)].expr).node);
      }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 593 "src/parser.y"
    {
          if (!is_numeric_type((yyvsp[(1) - (3)].expr).type) || !is_numeric_type((yyvsp[(3) - (3)].expr).type)) {
              semantic_error("comparison requires numeric operands");
          }
          (yyval.expr).type = TYPE_INT;
          (yyval.expr).node = make_binary_expr(OP_EQ, (yyvsp[(1) - (3)].expr).node, (yyvsp[(3) - (3)].expr).node);
      }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 601 "src/parser.y"
    {
          if (!is_numeric_type((yyvsp[(1) - (3)].expr).type) || !is_numeric_type((yyvsp[(3) - (3)].expr).type)) {
              semantic_error("comparison requires numeric operands");
          }
          (yyval.expr).type = TYPE_INT;
          (yyval.expr).node = make_binary_expr(OP_NEQ, (yyvsp[(1) - (3)].expr).node, (yyvsp[(3) - (3)].expr).node);
      }
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 609 "src/parser.y"
    {
          if (!is_numeric_type((yyvsp[(2) - (2)].expr).type)) {
              semantic_error("unary minus requires numeric operand");
              (yyval.expr).type = TYPE_UNKNOWN;
          } else {
              (yyval.expr).type = (yyvsp[(2) - (2)].expr).type;
          }
          (yyval.expr).node = make_unary_expr(OP_NEG, (yyvsp[(2) - (2)].expr).node);
      }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 619 "src/parser.y"
    {
          (yyval.expr).type = (yyvsp[(2) - (3)].expr).type;
          (yyval.expr).node = (yyvsp[(2) - (3)].expr).node;
      }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 624 "src/parser.y"
    {
          if (!is_numeric_type((yyvsp[(3) - (6)].expr).type) || !is_numeric_type((yyvsp[(5) - (6)].expr).type)) {
              semantic_error("shakti requires numeric arguments");
              (yyval.expr).type = TYPE_UNKNOWN;
          } else {
              (yyval.expr).type = TYPE_FLOAT;
          }
          (yyval.expr).node = make_shakti_expr((yyvsp[(3) - (6)].expr).node, (yyvsp[(5) - (6)].expr).node);
      }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 634 "src/parser.y"
    {
          if (!is_numeric_type((yyvsp[(3) - (4)].expr).type)) {
              semantic_error("borgomul requires numeric argument");
              (yyval.expr).type = TYPE_UNKNOWN;
          } else {
              (yyval.expr).type = TYPE_FLOAT;
          }
          (yyval.expr).node = make_borgomul_expr((yyvsp[(3) - (4)].expr).node);
      }
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 644 "src/parser.y"
    {
          (yyval.expr).type = (yyvsp[(1) - (1)].expr).type;
          (yyval.expr).node = (yyvsp[(1) - (1)].expr).node;
      }
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 649 "src/parser.y"
    {
          (yyval.expr).type = TYPE_INT;
          (yyval.expr).node = make_int_expr((yyvsp[(1) - (1)].ival));
      }
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 654 "src/parser.y"
    {
          (yyval.expr).type = TYPE_FLOAT;
          (yyval.expr).node = make_float_expr((yyvsp[(1) - (1)].fval));
      }
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 659 "src/parser.y"
    {
          Symbol *s = lookup_symbol((yyvsp[(1) - (1)].sval));
          if (s == NULL) {
              semantic_error("use of undeclared variable");
              (yyval.expr).type = TYPE_UNKNOWN;
          } else {
              (yyval.expr).type = s->type;
          }
          (yyval.expr).node = make_identifier_expr((yyvsp[(1) - (1)].sval));
      }
    break;


/* Line 1792 of yacc.c  */
#line 2396 "parser.tab.c"
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 671 "src/parser.y"


void yyerror(const char *s) {
    fprintf(stderr, "Syntax Error at line %d: %s\n", yylineno, s);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: natyo.exe <input_file>\n");
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror("Could not open input file");
        return 1;
    }

    init_symbol_table();
    bootstrap_constants();

    printf("Starting syntax + semantic analysis...\n");
    yyparse();

    fclose(yyin);
    free_top_level(program_root);
    return 0;
}