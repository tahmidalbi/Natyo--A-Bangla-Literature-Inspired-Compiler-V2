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
#include "optimizer.h"
#include "tac.h"

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
#line 95 "parser.tab.c"

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
#line 144 "parser.tab.c"

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
     LBRACKET = 296,
     RBRACKET = 297,
     LOWER_THAN_ELSE = 298,
     UMINUS = 299
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 44 "src/parser.y"

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
#line 216 "parser.tab.c"
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
#line 244 "parser.tab.c"

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
#define YYLAST   371

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNRULES -- Number of states.  */
#define YYNSTATES  166

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,     8,    11,    13,    15,    16,    24,
      28,    29,    31,    33,    37,    41,    42,    45,    48,    51,
      54,    57,    60,    63,    65,    67,    69,    70,    74,    75,
      79,    82,    85,    87,    91,    96,    98,   102,   107,   109,
     113,   118,   122,   126,   130,   137,   144,   151,   154,   157,
     160,   163,   169,   172,   175,   178,   184,   192,   202,   207,
     208,   210,   212,   216,   218,   220,   222,   226,   230,   234,
     238,   242,   246,   250,   254,   258,   262,   266,   269,   273,
     280,   285,   287,   289,   291,   293
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      46,     0,    -1,     8,    47,     9,    -1,    -1,    47,    48,
      -1,    56,    -1,    49,    -1,    -1,    10,     7,    50,    39,
      52,    40,    51,    -1,    11,    55,    12,    -1,    -1,    53,
      -1,     7,    -1,    53,    38,     7,    -1,    11,    55,    12,
      -1,    -1,    55,    56,    -1,    57,    37,    -1,    63,    37,
      -1,    64,    37,    -1,    65,    37,    -1,    69,    37,    -1,
      66,    37,    -1,    67,    -1,    68,    -1,    54,    -1,    -1,
      13,    58,    60,    -1,    -1,    14,    59,    60,    -1,    15,
      61,    -1,    16,    62,    -1,     7,    -1,     7,    25,    73,
      -1,     7,    41,     3,    42,    -1,     7,    -1,     7,    25,
       6,    -1,     7,    41,     3,    42,    -1,     7,    -1,     7,
      25,     5,    -1,     7,    41,     3,    42,    -1,     7,    25,
      73,    -1,     7,    25,     6,    -1,     7,    25,     5,    -1,
       7,    41,    73,    42,    25,    73,    -1,     7,    41,    73,
      42,    25,     6,    -1,     7,    41,    73,    42,    25,     5,
      -1,    17,    73,    -1,    17,     6,    -1,    17,     5,    -1,
      18,     7,    -1,    18,     7,    41,    73,    42,    -1,    24,
      73,    -1,    24,     6,    -1,    24,     5,    -1,    19,    39,
      73,    40,    56,    -1,    19,    39,    73,    40,    56,    20,
      56,    -1,    21,    39,    63,    37,    73,    37,    63,    40,
      56,    -1,     7,    39,    70,    40,    -1,    -1,    71,    -1,
      72,    -1,    71,    38,    72,    -1,    73,    -1,     6,    -1,
       5,    -1,    73,    26,    73,    -1,    73,    27,    73,    -1,
      73,    28,    73,    -1,    73,    29,    73,    -1,    73,    30,
      73,    -1,    73,    31,    73,    -1,    73,    32,    73,    -1,
      73,    33,    73,    -1,    73,    34,    73,    -1,    73,    35,
      73,    -1,    73,    36,    73,    -1,    27,    73,    -1,    39,
      73,    40,    -1,    22,    39,    73,    38,    73,    40,    -1,
      23,    39,    73,    40,    -1,    69,    -1,     3,    -1,     4,
      -1,     7,    -1,     7,    41,    73,    42,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    94,    94,   116,   119,   126,   130,   138,   137,   154,
     162,   165,   172,   179,   189,   197,   200,   207,   211,   215,
     219,   223,   227,   231,   235,   239,   247,   246,   255,   254,
     262,   266,   273,   280,   289,   301,   308,   315,   327,   334,
     341,   353,   367,   381,   395,   409,   423,   440,   444,   448,
     455,   465,   480,   489,   498,   510,   517,   527,   537,   563,
     567,   574,   578,   600,   606,   612,   621,   628,   635,   642,
     649,   659,   667,   675,   683,   691,   699,   707,   717,   722,
     732,   742,   747,   752,   757,   771
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
  "LPAREN", "RPAREN", "LBRACKET", "RBRACKET", "LOWER_THAN_ELSE", "UMINUS",
  "$accept", "program", "global_items", "global_item",
  "function_definition", "$@1", "function_body", "parameter_list_opt",
  "parameter_list", "block", "statement_list", "statement", "declaration",
  "$@2", "$@3", "numeric_declarator", "string_declarator",
  "char_declarator", "assignment", "print_stmt", "input_stmt",
  "return_stmt", "if_stmt", "loop_stmt", "function_call",
  "argument_list_opt", "argument_list", "argument", "expression", YY_NULL
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
     295,   296,   297,   298,   299
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    50,    49,    51,
      52,    52,    53,    53,    54,    55,    55,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    58,    57,    59,    57,
      57,    57,    60,    60,    60,    61,    61,    61,    62,    62,
      62,    63,    63,    63,    63,    63,    63,    64,    64,    64,
      65,    65,    66,    66,    66,    67,    67,    68,    69,    70,
      70,    71,    71,    72,    72,    72,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     0,     2,     1,     1,     0,     7,     3,
       0,     1,     1,     3,     3,     0,     2,     2,     2,     2,
       2,     2,     2,     1,     1,     1,     0,     3,     0,     3,
       2,     2,     1,     3,     4,     1,     3,     4,     1,     3,
       4,     3,     3,     3,     6,     6,     6,     2,     2,     2,
       2,     5,     2,     2,     2,     5,     7,     9,     4,     0,
       1,     1,     3,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     6,
       4,     1,     1,     1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     0,     0,     1,     0,     2,     0,    15,    26,
      28,     0,     0,     0,     0,     0,     0,     0,     4,     6,
      25,     5,     0,     0,     0,     0,     0,    23,    24,     0,
       0,    59,     0,     7,     0,     0,     0,    35,    30,    38,
      31,    82,    83,    49,    48,    84,     0,     0,     0,     0,
      81,    47,    50,     0,     0,    54,    53,    52,    17,    18,
      19,    20,    22,    21,    43,    42,    41,    65,    64,     0,
      60,    61,    63,     0,     0,    14,    16,    32,    27,    29,
       0,     0,     0,     0,     0,     0,     0,    77,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    58,     0,     0,    10,     0,     0,
      36,     0,    39,     0,     0,     0,     0,    78,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,     0,
       0,     0,    62,     0,    12,     0,    11,    33,     0,    37,
      40,    85,     0,    80,    51,    55,     0,    46,    45,    44,
       0,     0,    34,     0,     0,     0,    15,     8,    13,    79,
      56,     0,     0,     0,     9,    57
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    18,    19,    74,   157,   135,   136,    20,
      34,    76,    22,    35,    36,    78,    38,    40,    23,    24,
      25,    26,    27,    28,    50,    69,    70,    71,    72
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -52
static const yytype_int16 yypact[] =
{
      -4,   -52,    14,    40,   -52,     0,   -52,     8,   -52,   -52,
     -52,    19,    23,     5,    26,   -34,     4,    87,   -52,   -52,
     -52,   -52,    11,    58,    59,    61,    68,   -52,   -52,    69,
      96,   135,    13,   -52,   170,    38,    38,   -18,   -52,   -12,
     -52,   -52,   -52,   -52,   -52,   -17,    24,    37,    13,    13,
     -52,   335,    36,    13,    53,   -52,   -52,   335,   -52,   -52,
     -52,   -52,   -52,   -52,   -52,   -52,   335,   -52,   -52,    67,
      70,   -52,   335,   199,    72,   -52,   -52,    -7,   -52,   -52,
     106,   110,   111,   112,    13,    13,    13,   -52,   250,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,   265,    21,    80,   -52,   135,    99,   114,    13,   122,
     -52,    88,   -52,    90,   216,   310,   280,   -52,    42,    42,
     -52,   -52,   -52,    39,    39,    39,    39,    39,    39,   233,
     200,    13,   -52,   141,   -52,    89,    95,   335,    92,   -52,
     -52,   -52,    13,   -52,   -52,   116,   323,   -52,   -52,   335,
     126,   136,   -52,   295,   200,    53,   -52,   -52,   -52,   -52,
     -52,   109,   185,   200,   -52,   -52
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,
      -6,    -2,   -52,   -52,   -52,   117,   -52,   -52,   -51,   -52,
     -52,   -52,   -52,   -52,    -3,   -52,   -52,    49,   -11
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      29,    21,    51,   103,     1,    53,    57,    80,    41,    42,
      43,    44,    45,    82,     4,    33,    41,    42,   108,    66,
      45,    73,    31,    81,    84,    30,    37,    46,    47,    83,
      39,    29,    48,    52,   109,    46,    47,    87,    88,    31,
      48,    32,   101,    54,    49,    77,    30,     5,    58,     6,
       7,     8,    49,     9,    10,    11,    12,    13,    14,    15,
     102,    16,    32,    85,    17,    89,    90,    91,    92,    93,
      91,    92,    93,   114,   115,   116,    86,   100,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
      41,    42,    55,    56,    45,    59,    60,   137,    61,    41,
      42,    64,    65,    45,   161,    62,    63,   104,   105,    46,
      47,   107,   110,   111,    48,   113,   112,   131,    46,    47,
     146,   134,   149,    48,   133,   138,    49,    29,   145,   150,
     139,   153,   140,   151,   152,    49,   154,   156,    41,    42,
      67,    68,    45,   158,    41,    42,   147,   148,    45,   163,
     162,    29,   160,    79,   132,     0,     0,    46,    47,    29,
      29,   165,    48,    46,    47,     0,     0,     0,    48,     0,
       0,     0,     0,     0,    49,     0,     0,     5,     0,     0,
      49,     8,    75,     9,    10,    11,    12,    13,    14,    15,
       0,    16,     5,     0,    17,     0,     8,   164,     9,    10,
      11,    12,    13,    14,    15,     0,    16,     5,     0,    17,
       0,     8,     0,     9,    10,    11,    12,    13,    14,    15,
       0,    16,     0,     0,    17,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,     0,     0,     0,     0,
       0,   106,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,     0,     0,     0,     0,     0,   141,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
       0,     0,     0,     0,     0,   144,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,     0,     0,     0,
     117,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,     0,     0,     0,   130,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,     0,     0,     0,
     143,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,     0,     0,     0,   159,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,     0,   142,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     155,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-52)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       3,     3,    13,    54,     8,    39,    17,    25,     3,     4,
       5,     6,     7,    25,     0,     7,     3,     4,    25,    30,
       7,    32,    39,    41,    41,    25,     7,    22,    23,    41,
       7,    34,    27,     7,    41,    22,    23,    48,    49,    39,
      27,    41,    53,    39,    39,     7,    25,     7,    37,     9,
      10,    11,    39,    13,    14,    15,    16,    17,    18,    19,
       7,    21,    41,    39,    24,    26,    27,    28,    29,    30,
      28,    29,    30,    84,    85,    86,    39,    41,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
       3,     4,     5,     6,     7,    37,    37,   108,    37,     3,
       4,     5,     6,     7,   155,    37,    37,    40,    38,    22,
      23,    39,     6,     3,    27,     3,     5,    37,    22,    23,
     131,     7,   133,    27,    25,     3,    39,   130,   130,    40,
      42,   142,    42,    38,    42,    39,    20,    11,     3,     4,
       5,     6,     7,     7,     3,     4,     5,     6,     7,    40,
     156,   154,   154,    36,   105,    -1,    -1,    22,    23,   162,
     163,   163,    27,    22,    23,    -1,    -1,    -1,    27,    -1,
      -1,    -1,    -1,    -1,    39,    -1,    -1,     7,    -1,    -1,
      39,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      -1,    21,     7,    -1,    24,    -1,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    -1,    21,     7,    -1,    24,
      -1,    11,    -1,    13,    14,    15,    16,    17,    18,    19,
      -1,    21,    -1,    -1,    24,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    42,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    42,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    42,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      40,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    40,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      40,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    40,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    38,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    46,    47,     0,     7,     9,    10,    11,    13,
      14,    15,    16,    17,    18,    19,    21,    24,    48,    49,
      54,    56,    57,    63,    64,    65,    66,    67,    68,    69,
      25,    39,    41,     7,    55,    58,    59,     7,    61,     7,
      62,     3,     4,     5,     6,     7,    22,    23,    27,    39,
      69,    73,     7,    39,    39,     5,     6,    73,    37,    37,
      37,    37,    37,    37,     5,     6,    73,     5,     6,    70,
      71,    72,    73,    73,    50,    12,    56,     7,    60,    60,
      25,    41,    25,    41,    41,    39,    39,    73,    73,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      41,    73,     7,    63,    40,    38,    42,    39,    25,    41,
       6,     3,     5,     3,    73,    73,    73,    40,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      40,    37,    72,    25,     7,    52,    53,    73,     3,    42,
      42,    42,    38,    40,    42,    56,    73,     5,     6,    73,
      40,    38,    42,    73,    20,    37,    11,    51,     7,    40,
      56,    63,    55,    40,    12,    56
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
#line 95 "src/parser.y"
    {
          program_root = (yyvsp[(2) - (3)].top);

          if (semantic_errors == 0) {
              printf("Semantic Analysis Successful: program is meaningful.\n");

              optimize_program(program_root);
              generate_tac(program_root, "tac_output.txt");
              printf("Optimization complete: constant folding applied where possible.\n");
              printf("TAC generated in tac_output.txt\n");

              reset_history_log();
              interpret_program(program_root);
          } else {
              printf("Semantic Analysis finished with %d semantic error(s).\n", semantic_errors);
          }
      }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 116 "src/parser.y"
    {
          (yyval.top) = NULL;
      }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 120 "src/parser.y"
    {
          (yyval.top) = append_top((yyvsp[(1) - (2)].top), (yyvsp[(2) - (2)].top));
      }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 127 "src/parser.y"
    {
          (yyval.top) = make_top_stmt((yyvsp[(1) - (1)].stmt));
      }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 131 "src/parser.y"
    {
          (yyval.top) = (yyvsp[(1) - (1)].top);
      }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 138 "src/parser.y"
    {
          if (!declare_function((yyvsp[(2) - (2)].sval))) {
              semantic_error("function redeclared");
          }
          start_function_context((yyvsp[(2) - (2)].sval));
      }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 145 "src/parser.y"
    {
          ASTIdentifierList *params = (yyvsp[(5) - (7)].idlist);
          set_current_function_body((yyvsp[(7) - (7)].stmt));
          (yyval.top) = make_top_func((yyvsp[(2) - (7)].sval), params, (yyvsp[(7) - (7)].stmt));
          end_function_context();
      }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 155 "src/parser.y"
    {
          (yyval.stmt) = make_block_stmt((yyvsp[(2) - (3)].stmt));
      }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 162 "src/parser.y"
    {
          (yyval.idlist) = NULL;
      }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 166 "src/parser.y"
    {
          (yyval.idlist) = (yyvsp[(1) - (1)].idlist);
      }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 173 "src/parser.y"
    {
          if (!add_parameter_to_current_function((yyvsp[(1) - (1)].sval), TYPE_FLOAT)) {
              semantic_error("parameter redeclared");
          }
          (yyval.idlist) = make_identifier_list((yyvsp[(1) - (1)].sval));
      }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 180 "src/parser.y"
    {
          if (!add_parameter_to_current_function((yyvsp[(3) - (3)].sval), TYPE_FLOAT)) {
              semantic_error("parameter redeclared");
          }
          (yyval.idlist) = append_identifier((yyvsp[(1) - (3)].idlist), (yyvsp[(3) - (3)].sval));
      }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 190 "src/parser.y"
    {
          (yyval.stmt) = make_block_stmt((yyvsp[(2) - (3)].stmt));
      }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 197 "src/parser.y"
    {
          (yyval.stmt) = NULL;
      }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 201 "src/parser.y"
    {
          (yyval.stmt) = append_stmt((yyvsp[(1) - (2)].stmt), (yyvsp[(2) - (2)].stmt));
      }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 208 "src/parser.y"
    {
          (yyval.stmt) = (yyvsp[(1) - (2)].stmt);
      }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 212 "src/parser.y"
    {
          (yyval.stmt) = (yyvsp[(1) - (2)].stmt);
      }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 216 "src/parser.y"
    {
          (yyval.stmt) = (yyvsp[(1) - (2)].stmt);
      }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 220 "src/parser.y"
    {
          (yyval.stmt) = (yyvsp[(1) - (2)].stmt);
      }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 224 "src/parser.y"
    {
          (yyval.stmt) = make_expr_stmt((yyvsp[(1) - (2)].expr).node);
      }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 228 "src/parser.y"
    {
          (yyval.stmt) = (yyvsp[(1) - (2)].stmt);
      }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 232 "src/parser.y"
    {
          (yyval.stmt) = (yyvsp[(1) - (1)].stmt);
      }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 236 "src/parser.y"
    {
          (yyval.stmt) = (yyvsp[(1) - (1)].stmt);
      }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 240 "src/parser.y"
    {
          (yyval.stmt) = (yyvsp[(1) - (1)].stmt);
      }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 247 "src/parser.y"
    {
          current_decl_type = TYPE_INT;
      }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 251 "src/parser.y"
    {
          (yyval.stmt) = (yyvsp[(3) - (3)].stmt);
      }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 255 "src/parser.y"
    {
          current_decl_type = TYPE_FLOAT;
      }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 259 "src/parser.y"
    {
          (yyval.stmt) = (yyvsp[(3) - (3)].stmt);
      }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 263 "src/parser.y"
    {
          (yyval.stmt) = (yyvsp[(2) - (2)].stmt);
      }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 267 "src/parser.y"
    {
          (yyval.stmt) = (yyvsp[(2) - (2)].stmt);
      }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 274 "src/parser.y"
    {
          if (!declare_variable((yyvsp[(1) - (1)].sval), current_decl_type, SYM_VAR)) {
              semantic_error("variable redeclared in same scope");
          }
          (yyval.stmt) = make_decl_stmt(current_decl_type, (yyvsp[(1) - (1)].sval), NULL);
      }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 281 "src/parser.y"
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
#line 290 "src/parser.y"
    {
          if ((yyvsp[(3) - (4)].ival) <= 0) {
              semantic_error("array size must be positive");
          } else if (!declare_array((yyvsp[(1) - (4)].sval), current_decl_type, SYM_VAR, (yyvsp[(3) - (4)].ival))) {
              semantic_error("array redeclared in same scope");
          }
          (yyval.stmt) = make_array_decl_stmt(current_decl_type, (yyvsp[(1) - (4)].sval), (yyvsp[(3) - (4)].ival));
      }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 302 "src/parser.y"
    {
          if (!declare_variable((yyvsp[(1) - (1)].sval), TYPE_STRING, SYM_VAR)) {
              semantic_error("variable redeclared in same scope");
          }
          (yyval.stmt) = make_decl_stmt(TYPE_STRING, (yyvsp[(1) - (1)].sval), NULL);
      }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 309 "src/parser.y"
    {
          if (!declare_variable((yyvsp[(1) - (3)].sval), TYPE_STRING, SYM_VAR)) {
              semantic_error("variable redeclared in same scope");
          }
          (yyval.stmt) = make_decl_string_stmt((yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].sval));
      }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 316 "src/parser.y"
    {
          if ((yyvsp[(3) - (4)].ival) <= 0) {
              semantic_error("array size must be positive");
          } else if (!declare_array((yyvsp[(1) - (4)].sval), TYPE_STRING, SYM_VAR, (yyvsp[(3) - (4)].ival))) {
              semantic_error("array redeclared in same scope");
          }
          (yyval.stmt) = make_array_decl_stmt(TYPE_STRING, (yyvsp[(1) - (4)].sval), (yyvsp[(3) - (4)].ival));
      }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 328 "src/parser.y"
    {
          if (!declare_variable((yyvsp[(1) - (1)].sval), TYPE_CHAR, SYM_VAR)) {
              semantic_error("variable redeclared in same scope");
          }
          (yyval.stmt) = make_decl_stmt(TYPE_CHAR, (yyvsp[(1) - (1)].sval), NULL);
      }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 335 "src/parser.y"
    {
          if (!declare_variable((yyvsp[(1) - (3)].sval), TYPE_CHAR, SYM_VAR)) {
              semantic_error("variable redeclared in same scope");
          }
          (yyval.stmt) = make_decl_char_stmt((yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].cval));
      }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 342 "src/parser.y"
    {
          if ((yyvsp[(3) - (4)].ival) <= 0) {
              semantic_error("array size must be positive");
          } else if (!declare_array((yyvsp[(1) - (4)].sval), TYPE_CHAR, SYM_VAR, (yyvsp[(3) - (4)].ival))) {
              semantic_error("array redeclared in same scope");
          }
          (yyval.stmt) = make_array_decl_stmt(TYPE_CHAR, (yyvsp[(1) - (4)].sval), (yyvsp[(3) - (4)].ival));
      }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 354 "src/parser.y"
    {
          Symbol *s = lookup_symbol((yyvsp[(1) - (3)].sval));
          if (s == NULL) {
              semantic_error("assignment to undeclared variable");
          } else if (s->is_array) {
              semantic_error("array variable requires index for assignment");
          } else if (s->kind == SYM_CONST) {
              semantic_error("cannot modify constant");
          } else if (!can_assign(s->type, (yyvsp[(3) - (3)].expr).type)) {
              semantic_error("type mismatch in assignment");
          }
          (yyval.stmt) = make_assign_expr_stmt((yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].expr).node);
      }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 368 "src/parser.y"
    {
          Symbol *s = lookup_symbol((yyvsp[(1) - (3)].sval));
          if (s == NULL) {
              semantic_error("assignment to undeclared variable");
          } else if (s->is_array) {
              semantic_error("array variable requires index for assignment");
          } else if (s->kind == SYM_CONST) {
              semantic_error("cannot modify constant");
          } else if (!can_assign(s->type, TYPE_STRING)) {
              semantic_error("type mismatch in assignment");
          }
          (yyval.stmt) = make_assign_string_stmt((yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].sval));
      }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 382 "src/parser.y"
    {
          Symbol *s = lookup_symbol((yyvsp[(1) - (3)].sval));
          if (s == NULL) {
              semantic_error("assignment to undeclared variable");
          } else if (s->is_array) {
              semantic_error("array variable requires index for assignment");
          } else if (s->kind == SYM_CONST) {
              semantic_error("cannot modify constant");
          } else if (!can_assign(s->type, TYPE_CHAR)) {
              semantic_error("type mismatch in assignment");
          }
          (yyval.stmt) = make_assign_char_stmt((yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].cval));
      }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 396 "src/parser.y"
    {
          Symbol *s = lookup_symbol((yyvsp[(1) - (6)].sval));
          if (s == NULL) {
              semantic_error("assignment to undeclared array");
          } else if (!s->is_array) {
              semantic_error("indexed assignment requires an array");
          } else if ((yyvsp[(3) - (6)].expr).type != TYPE_INT && (yyvsp[(3) - (6)].expr).type != TYPE_UNKNOWN) {
              semantic_error("array index must be integer");
          } else if (!can_assign(s->type, (yyvsp[(6) - (6)].expr).type)) {
              semantic_error("type mismatch in array assignment");
          }
          (yyval.stmt) = make_array_assign_expr_stmt((yyvsp[(1) - (6)].sval), (yyvsp[(3) - (6)].expr).node, (yyvsp[(6) - (6)].expr).node);
      }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 410 "src/parser.y"
    {
          Symbol *s = lookup_symbol((yyvsp[(1) - (6)].sval));
          if (s == NULL) {
              semantic_error("assignment to undeclared array");
          } else if (!s->is_array) {
              semantic_error("indexed assignment requires an array");
          } else if ((yyvsp[(3) - (6)].expr).type != TYPE_INT && (yyvsp[(3) - (6)].expr).type != TYPE_UNKNOWN) {
              semantic_error("array index must be integer");
          } else if (!can_assign(s->type, TYPE_STRING)) {
              semantic_error("type mismatch in array assignment");
          }
          (yyval.stmt) = make_array_assign_string_stmt((yyvsp[(1) - (6)].sval), (yyvsp[(3) - (6)].expr).node, (yyvsp[(6) - (6)].sval));
      }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 424 "src/parser.y"
    {
          Symbol *s = lookup_symbol((yyvsp[(1) - (6)].sval));
          if (s == NULL) {
              semantic_error("assignment to undeclared array");
          } else if (!s->is_array) {
              semantic_error("indexed assignment requires an array");
          } else if ((yyvsp[(3) - (6)].expr).type != TYPE_INT && (yyvsp[(3) - (6)].expr).type != TYPE_UNKNOWN) {
              semantic_error("array index must be integer");
          } else if (!can_assign(s->type, TYPE_CHAR)) {
              semantic_error("type mismatch in array assignment");
          }
          (yyval.stmt) = make_array_assign_char_stmt((yyvsp[(1) - (6)].sval), (yyvsp[(3) - (6)].expr).node, (yyvsp[(6) - (6)].cval));
      }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 441 "src/parser.y"
    {
          (yyval.stmt) = make_print_expr_stmt((yyvsp[(2) - (2)].expr).node);
      }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 445 "src/parser.y"
    {
          (yyval.stmt) = make_print_string_stmt((yyvsp[(2) - (2)].sval));
      }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 449 "src/parser.y"
    {
          (yyval.stmt) = make_print_char_stmt((yyvsp[(2) - (2)].cval));
      }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 456 "src/parser.y"
    {
          Symbol *s = lookup_symbol((yyvsp[(2) - (2)].sval));
          if (s == NULL) {
              semantic_error("input target is undeclared");
          } else if (s->is_array) {
              semantic_error("array input requires index");
          }
          (yyval.stmt) = make_input_stmt((yyvsp[(2) - (2)].sval));
      }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 466 "src/parser.y"
    {
          Symbol *s = lookup_symbol((yyvsp[(2) - (5)].sval));
          if (s == NULL) {
              semantic_error("input target array is undeclared");
          } else if (!s->is_array) {
              semantic_error("indexed input requires an array");
          } else if ((yyvsp[(4) - (5)].expr).type != TYPE_INT && (yyvsp[(4) - (5)].expr).type != TYPE_UNKNOWN) {
              semantic_error("array index must be integer");
          }
          (yyval.stmt) = make_array_input_stmt((yyvsp[(2) - (5)].sval), (yyvsp[(4) - (5)].expr).node);
      }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 481 "src/parser.y"
    {
          if (!in_function_context()) {
              semantic_error("pherot used outside function");
          } else if (!register_return_type((yyvsp[(2) - (2)].expr).type)) {
              semantic_error("inconsistent function return type");
          }
          (yyval.stmt) = make_return_expr_stmt((yyvsp[(2) - (2)].expr).node);
      }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 490 "src/parser.y"
    {
          if (!in_function_context()) {
              semantic_error("pherot used outside function");
          } else if (!register_return_type(TYPE_STRING)) {
              semantic_error("inconsistent function return type");
          }
          (yyval.stmt) = make_return_string_stmt((yyvsp[(2) - (2)].sval));
      }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 499 "src/parser.y"
    {
          if (!in_function_context()) {
              semantic_error("pherot used outside function");
          } else if (!register_return_type(TYPE_CHAR)) {
              semantic_error("inconsistent function return type");
          }
          (yyval.stmt) = make_return_char_stmt((yyvsp[(2) - (2)].cval));
      }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 511 "src/parser.y"
    {
          if (!is_numeric_type((yyvsp[(3) - (5)].expr).type)) {
              semantic_error("if condition must be numeric/boolean-like");
          }
          (yyval.stmt) = make_if_stmt((yyvsp[(3) - (5)].expr).node, (yyvsp[(5) - (5)].stmt), NULL);
      }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 518 "src/parser.y"
    {
          if (!is_numeric_type((yyvsp[(3) - (7)].expr).type)) {
              semantic_error("if condition must be numeric/boolean-like");
          }
          (yyval.stmt) = make_if_stmt((yyvsp[(3) - (7)].expr).node, (yyvsp[(5) - (7)].stmt), (yyvsp[(7) - (7)].stmt));
      }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 528 "src/parser.y"
    {
          if (!is_numeric_type((yyvsp[(5) - (9)].expr).type)) {
              semantic_error("loop condition must be numeric/boolean-like");
          }
          (yyval.stmt) = make_loop_stmt((yyvsp[(3) - (9)].stmt), (yyvsp[(5) - (9)].expr).node, (yyvsp[(7) - (9)].stmt), (yyvsp[(9) - (9)].stmt));
      }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 538 "src/parser.y"
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

  case 59:
/* Line 1792 of yacc.c  */
#line 563 "src/parser.y"
    {
          (yyval.args).count = 0;
          (yyval.args).nodes = NULL;
      }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 568 "src/parser.y"
    {
          (yyval.args) = (yyvsp[(1) - (1)].args);
      }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 575 "src/parser.y"
    {
          (yyval.args) = (yyvsp[(1) - (1)].args);
      }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 579 "src/parser.y"
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

  case 63:
/* Line 1792 of yacc.c  */
#line 601 "src/parser.y"
    {
          (yyval.args).count = 1;
          (yyval.args).types[0] = (yyvsp[(1) - (1)].expr).type;
          (yyval.args).nodes = make_arg_list((yyvsp[(1) - (1)].expr).node);
      }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 607 "src/parser.y"
    {
          (yyval.args).count = 1;
          (yyval.args).types[0] = TYPE_STRING;
          (yyval.args).nodes = make_arg_list(make_string_expr((yyvsp[(1) - (1)].sval)));
      }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 613 "src/parser.y"
    {
          (yyval.args).count = 1;
          (yyval.args).types[0] = TYPE_CHAR;
          (yyval.args).nodes = make_arg_list(make_char_expr((yyvsp[(1) - (1)].cval)));
      }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 622 "src/parser.y"
    {
          DataType t = arithmetic_result_type((yyvsp[(1) - (3)].expr).type, (yyvsp[(3) - (3)].expr).type);
          if (t == TYPE_UNKNOWN) semantic_error("invalid operands for +");
          (yyval.expr).type = t;
          (yyval.expr).node = make_binary_expr(OP_ADD, (yyvsp[(1) - (3)].expr).node, (yyvsp[(3) - (3)].expr).node);
      }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 629 "src/parser.y"
    {
          DataType t = arithmetic_result_type((yyvsp[(1) - (3)].expr).type, (yyvsp[(3) - (3)].expr).type);
          if (t == TYPE_UNKNOWN) semantic_error("invalid operands for -");
          (yyval.expr).type = t;
          (yyval.expr).node = make_binary_expr(OP_SUB, (yyvsp[(1) - (3)].expr).node, (yyvsp[(3) - (3)].expr).node);
      }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 636 "src/parser.y"
    {
          DataType t = arithmetic_result_type((yyvsp[(1) - (3)].expr).type, (yyvsp[(3) - (3)].expr).type);
          if (t == TYPE_UNKNOWN) semantic_error("invalid operands for *");
          (yyval.expr).type = t;
          (yyval.expr).node = make_binary_expr(OP_MUL, (yyvsp[(1) - (3)].expr).node, (yyvsp[(3) - (3)].expr).node);
      }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 643 "src/parser.y"
    {
          DataType t = arithmetic_result_type((yyvsp[(1) - (3)].expr).type, (yyvsp[(3) - (3)].expr).type);
          if (t == TYPE_UNKNOWN) semantic_error("invalid operands for /");
          (yyval.expr).type = TYPE_FLOAT;
          (yyval.expr).node = make_binary_expr(OP_DIV, (yyvsp[(1) - (3)].expr).node, (yyvsp[(3) - (3)].expr).node);
      }
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 650 "src/parser.y"
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

  case 71:
/* Line 1792 of yacc.c  */
#line 660 "src/parser.y"
    {
          if (!is_numeric_type((yyvsp[(1) - (3)].expr).type) || !is_numeric_type((yyvsp[(3) - (3)].expr).type)) {
              semantic_error("comparison requires numeric operands");
          }
          (yyval.expr).type = TYPE_INT;
          (yyval.expr).node = make_binary_expr(OP_GT, (yyvsp[(1) - (3)].expr).node, (yyvsp[(3) - (3)].expr).node);
      }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 668 "src/parser.y"
    {
          if (!is_numeric_type((yyvsp[(1) - (3)].expr).type) || !is_numeric_type((yyvsp[(3) - (3)].expr).type)) {
              semantic_error("comparison requires numeric operands");
          }
          (yyval.expr).type = TYPE_INT;
          (yyval.expr).node = make_binary_expr(OP_LT, (yyvsp[(1) - (3)].expr).node, (yyvsp[(3) - (3)].expr).node);
      }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 676 "src/parser.y"
    {
          if (!is_numeric_type((yyvsp[(1) - (3)].expr).type) || !is_numeric_type((yyvsp[(3) - (3)].expr).type)) {
              semantic_error("comparison requires numeric operands");
          }
          (yyval.expr).type = TYPE_INT;
          (yyval.expr).node = make_binary_expr(OP_GEQ, (yyvsp[(1) - (3)].expr).node, (yyvsp[(3) - (3)].expr).node);
      }
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 684 "src/parser.y"
    {
          if (!is_numeric_type((yyvsp[(1) - (3)].expr).type) || !is_numeric_type((yyvsp[(3) - (3)].expr).type)) {
              semantic_error("comparison requires numeric operands");
          }
          (yyval.expr).type = TYPE_INT;
          (yyval.expr).node = make_binary_expr(OP_LEQ, (yyvsp[(1) - (3)].expr).node, (yyvsp[(3) - (3)].expr).node);
      }
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 692 "src/parser.y"
    {
          if (!is_numeric_type((yyvsp[(1) - (3)].expr).type) || !is_numeric_type((yyvsp[(3) - (3)].expr).type)) {
              semantic_error("comparison requires numeric operands");
          }
          (yyval.expr).type = TYPE_INT;
          (yyval.expr).node = make_binary_expr(OP_EQ, (yyvsp[(1) - (3)].expr).node, (yyvsp[(3) - (3)].expr).node);
      }
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 700 "src/parser.y"
    {
          if (!is_numeric_type((yyvsp[(1) - (3)].expr).type) || !is_numeric_type((yyvsp[(3) - (3)].expr).type)) {
              semantic_error("comparison requires numeric operands");
          }
          (yyval.expr).type = TYPE_INT;
          (yyval.expr).node = make_binary_expr(OP_NEQ, (yyvsp[(1) - (3)].expr).node, (yyvsp[(3) - (3)].expr).node);
      }
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 708 "src/parser.y"
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

  case 78:
/* Line 1792 of yacc.c  */
#line 718 "src/parser.y"
    {
          (yyval.expr).type = (yyvsp[(2) - (3)].expr).type;
          (yyval.expr).node = (yyvsp[(2) - (3)].expr).node;
      }
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 723 "src/parser.y"
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

  case 80:
/* Line 1792 of yacc.c  */
#line 733 "src/parser.y"
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

  case 81:
/* Line 1792 of yacc.c  */
#line 743 "src/parser.y"
    {
          (yyval.expr).type = (yyvsp[(1) - (1)].expr).type;
          (yyval.expr).node = (yyvsp[(1) - (1)].expr).node;
      }
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 748 "src/parser.y"
    {
          (yyval.expr).type = TYPE_INT;
          (yyval.expr).node = make_int_expr((yyvsp[(1) - (1)].ival));
      }
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 753 "src/parser.y"
    {
          (yyval.expr).type = TYPE_FLOAT;
          (yyval.expr).node = make_float_expr((yyvsp[(1) - (1)].fval));
      }
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 758 "src/parser.y"
    {
          Symbol *s = lookup_symbol((yyvsp[(1) - (1)].sval));
          if (s == NULL) {
              semantic_error("use of undeclared variable");
              (yyval.expr).type = TYPE_UNKNOWN;
          } else if (s->is_array) {
              semantic_error("array variable requires index");
              (yyval.expr).type = TYPE_UNKNOWN;
          } else {
              (yyval.expr).type = s->type;
          }
          (yyval.expr).node = make_identifier_expr((yyvsp[(1) - (1)].sval));
      }
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 772 "src/parser.y"
    {
          Symbol *s = lookup_symbol((yyvsp[(1) - (4)].sval));
          if (s == NULL) {
              semantic_error("use of undeclared array");
              (yyval.expr).type = TYPE_UNKNOWN;
          } else if (!s->is_array) {
              semantic_error("indexed access requires an array");
              (yyval.expr).type = TYPE_UNKNOWN;
          } else if ((yyvsp[(3) - (4)].expr).type != TYPE_INT && (yyvsp[(3) - (4)].expr).type != TYPE_UNKNOWN) {
              semantic_error("array index must be integer");
              (yyval.expr).type = TYPE_UNKNOWN;
          } else {
              (yyval.expr).type = s->type;
          }
          (yyval.expr).node = make_array_access_expr((yyvsp[(1) - (4)].sval), (yyvsp[(3) - (4)].expr).node);
      }
    break;


/* Line 1792 of yacc.c  */
#line 2584 "parser.tab.c"
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
#line 790 "src/parser.y"


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