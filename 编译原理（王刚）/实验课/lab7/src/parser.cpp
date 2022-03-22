/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* "%code top" blocks.  */
#line 1 "src/parser.y" /* yacc.c:316  */

    #include <iostream>
    #include <assert.h>
    #include <string>
    #include <stack>
    #include "parser.h"
    extern Ast ast;
    int yylex();
    int yyerror( char const * );
    SymbolEntry *currentSe;
    SymbolEntry *currentRet=0;
    bool isReturn;
    int params=0;
    std::stack<StmtNode*> whileStack;

#line 79 "src/parser.cpp" /* yacc.c:316  */



/* Copy the first part of user declarations.  */

#line 85 "src/parser.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
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
   by #include "parser.h".  */
#ifndef YY_YY_INCLUDE_PARSER_H_INCLUDED
# define YY_YY_INCLUDE_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 17 "src/parser.y" /* yacc.c:355  */

    #include "Ast.h"
    #include "SymbolTable.h"
    #include "Type.h"

#line 121 "src/parser.cpp" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID = 258,
    PUTINT = 259,
    GETINT = 260,
    PUTCH = 261,
    INTEGER = 262,
    IF = 263,
    ELSE = 264,
    WHILE = 265,
    CONST = 266,
    INT = 267,
    VOID = 268,
    LPAREN = 269,
    RPAREN = 270,
    LBRACKT = 271,
    RBRACKT = 272,
    LBRACE = 273,
    RBRACE = 274,
    SEMICOLON = 275,
    MUL = 276,
    DIV = 277,
    MOD = 278,
    ADD = 279,
    SUB = 280,
    OR = 281,
    AND = 282,
    LESS = 283,
    GREATER = 284,
    NOT = 285,
    EQUAL = 286,
    NOTEQUAL = 287,
    ASSIGN = 288,
    GREATEREQ = 289,
    LESSEQ = 290,
    RETURN = 291,
    CONTINUE = 292,
    BREAK = 293,
    COMMA = 294,
    THEN = 295
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 23 "src/parser.y" /* yacc.c:355  */

    int itype;
    char* strtype;
    StmtNode* stmttype;
    ExprNode* exprtype;
    Type* type;
    char chartype;
    Def* deftype;
    Defs* defstype;
    ArrayInits* arrayinitstype;
    ArrayDef* arraydeftype;

#line 187 "src/parser.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INCLUDE_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 204 "src/parser.cpp" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

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
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  80
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   230

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  175

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    61,    61,    66,    67,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    86,   108,   114,   120,
     119,   129,   135,   138,   145,   144,   157,   163,   170,   176,
     182,   187,   192,   200,   204,   207,   211,   219,   224,   229,
     236,   238,   244,   246,   266,   268,   274,   280,   288,   290,
     296,   304,   306,   312,   318,   324,   330,   338,   340,   348,
     350,   358,   360,   368,   371,   374,   380,   384,   390,   405,
     420,   427,   432,   439,   457,   462,   469,   476,   483,   492,
     504,   511,   515,   522,   539,   537,   562,   561,   584,   598,
     602,   609,   620,   631,   639,   656,   676,   680,   687,   695,
     699,   706,   712,   720
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "PUTINT", "GETINT", "PUTCH",
  "INTEGER", "IF", "ELSE", "WHILE", "CONST", "INT", "VOID", "LPAREN",
  "RPAREN", "LBRACKT", "RBRACKT", "LBRACE", "RBRACE", "SEMICOLON", "MUL",
  "DIV", "MOD", "ADD", "SUB", "OR", "AND", "LESS", "GREATER", "NOT",
  "EQUAL", "NOTEQUAL", "ASSIGN", "GREATEREQ", "LESSEQ", "RETURN",
  "CONTINUE", "BREAK", "COMMA", "THEN", "$accept", "VarDef", "ConstDef",
  "VarDefs", "ConstDefs", "ArrayInits", "ArrayDef", "Stmts", "Stmt",
  "AssignStmt", "BlockStmt", "IfStmt", "ReturnStmt", "DeclStmt",
  "ConstDeclStmt", "VarDeclStmt", "ArrayDeclStmt", "FuncDef", "FuncParas",
  "FuncPara", "FuncDecl", "ExprStmt", "WhileStmt", "FuncCallParas",
  "FuncCallPara", "BREAKSTMT", "CONTINUESTMT", "Exp", "AddExp", "Cond",
  "LOrExp", "PrimaryExp", "LVal", "RelExp", "LAndExp", "UnaryExp",
  "MulExp", "EqExp", "InitVal", "FuncCall", "IOStream", "PutStream",
  "GetStream", "ArrayMember", "Type", "UnaryOp", "Program", "$@1", "$@2",
  "$@3", "$@4", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
# endif

#define YYPACT_NINF -50

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-50)))

#define YYTABLE_NINF -85

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     192,    34,    12,    24,    33,   -50,    43,    44,    21,   -50,
     -50,   119,    40,   -50,   -50,   -50,   -50,     7,    23,    41,
     192,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,
     -11,   -50,   -50,   -50,   -50,    45,    29,   -50,    30,   -50,
       2,   -50,   -50,   -50,   -50,   -50,    61,   119,    66,    82,
     119,   119,    52,   119,   119,   119,    65,    54,   -50,   -50,
     192,   -50,    58,   -50,   -50,   -50,   -50,   -50,   -50,   119,
     119,   119,   119,   119,   119,     3,    42,    59,   -50,   -50,
     -50,   -50,    67,    51,   -50,    63,    68,   -50,    76,    29,
      77,    69,    17,    71,    62,    79,    70,    60,    84,   -50,
     156,   -50,     2,     2,    88,   -50,   -50,   -50,    94,   103,
     119,   108,   -50,   -50,   119,   -50,   -50,   -50,   192,   119,
     119,   119,   119,   119,   119,   119,   119,   -50,   119,    65,
     -50,   -50,   -50,    98,    21,    97,   -50,   -50,     6,   -50,
     -50,   106,    71,    29,    29,    29,    29,    29,    62,    17,
     192,   -50,   -50,   -50,   101,    78,   117,    95,   192,   -50,
     -50,    21,    96,   112,   -50,   -50,   119,   114,   -50,   -50,
     -50,    -4,   -50,   124,   -50
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    16,     0,     0,     0,    35,     0,     0,     0,    64,
      65,     0,    19,    32,    37,    38,    39,     0,     0,     0,
       2,     3,     5,     6,     7,     8,     9,    67,    66,    10,
       0,    12,    13,    14,    15,     0,    30,    40,    34,    44,
      48,    41,    42,    99,   100,    17,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    34,    21,
       0,    27,     0,    29,    28,     4,    11,    88,    31,     0,
       0,     0,     0,     0,     0,    68,    72,     0,    70,    43,
       1,    95,     0,    97,    98,     0,     0,   103,     0,    51,
       0,    33,    57,    61,    59,     0,     0,    75,     0,    36,
       0,    26,    49,    50,     0,    45,    46,    47,    86,     0,
       0,     0,    77,    94,     0,    83,   101,   102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    24,     0,     0,
      76,    20,    18,     0,     0,     0,    63,    69,    68,    71,
      96,    22,    62,    52,    53,    54,    55,    56,    60,    58,
       0,    73,    74,    85,     0,    90,    93,    78,     0,    25,
      87,     0,    92,     0,    23,    89,     0,     0,    79,    91,
      82,     0,    80,     0,    81
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -50,   -50,   -50,    25,     8,   -50,   -50,    72,   -16,   -50,
     105,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -23,   -50,
     -50,   -50,   -50,    26,   -35,   -50,   -50,    -9,   -49,    86,
     -50,   -50,     0,    13,    27,   -44,   -14,    20,    19,   -50,
     -50,   -50,   -50,   -50,    -7,   -50,   -50,   -50,   -50,   -50,
     -50
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    76,    97,    77,    98,   171,   168,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    78,    29,   154,   155,
      30,    31,    32,    82,    83,    33,    34,    35,    36,    90,
      91,    37,    58,    92,    93,    39,    40,    94,   137,    41,
      42,    43,    44,    45,    46,    47,    48,    60,   150,   133,
     134
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      38,    56,    57,    79,    65,    89,    89,    12,    62,    66,
       1,     2,     3,     4,     5,   172,    86,   108,    88,   109,
      38,    11,   109,    72,    73,    74,    51,    61,   105,   106,
     107,    14,    15,     9,    10,   173,   110,    16,    52,   110,
      84,    85,    84,    63,    84,   120,   121,    53,    49,   122,
      50,   123,   124,    69,    70,   102,   103,    54,    55,    59,
      38,    64,   104,    71,    75,    68,    80,    87,    96,    99,
      89,   143,   144,   145,   146,   147,    89,    89,   101,   112,
     115,   111,   113,   116,    65,     1,     2,     3,     4,     5,
     114,   117,   118,   126,   127,   119,    11,    81,   125,   129,
      38,   136,   141,   128,   130,    84,    14,    15,   132,   -84,
     135,   138,    16,   153,   157,   158,   160,   161,    38,   136,
     162,   170,     1,     2,     3,     4,     5,   156,   163,   166,
     167,   174,   100,    11,   159,    67,   139,   152,   165,   149,
     140,    95,   164,    14,    15,   148,   142,   151,     0,    16,
      38,     0,     0,     0,   156,     0,     0,   169,    38,     1,
       2,     3,     4,     5,     6,     0,     7,     8,     9,    10,
      11,     0,     0,     0,    12,   131,    13,     0,     0,     0,
      14,    15,     0,     0,     0,     0,    16,     0,     0,     0,
       0,     0,    17,    18,    19,     1,     2,     3,     4,     5,
       6,     0,     7,     8,     9,    10,    11,     0,     0,     0,
      12,     0,    13,     0,     0,     0,    14,    15,     0,     0,
       0,     0,    16,     0,     0,     0,     0,     0,    17,    18,
      19
};

static const yytype_int16 yycheck[] =
{
       0,     8,    11,    47,    20,    54,    55,    18,    17,    20,
       3,     4,     5,     6,     7,    19,    51,    14,    53,    16,
      20,    14,    16,    21,    22,    23,    14,    20,    72,    73,
      74,    24,    25,    12,    13,    39,    33,    30,    14,    33,
      49,    50,    51,    20,    53,    28,    29,    14,    14,    32,
      16,    34,    35,    24,    25,    69,    70,    14,    14,    19,
      60,    20,    71,    33,     3,    20,     0,    15,     3,    15,
     119,   120,   121,   122,   123,   124,   125,   126,    20,    20,
      17,    39,    15,    15,   100,     3,     4,     5,     6,     7,
      39,    15,    15,    31,    15,    26,    14,    15,    27,    39,
     100,   110,   118,    33,    20,   114,    24,    25,    20,    15,
       7,     3,    30,    15,    17,     9,    15,    39,   118,   128,
       3,     7,     3,     4,     5,     6,     7,   134,    33,    33,
      18,     7,    60,    14,   150,    30,   111,   129,   161,   126,
     114,    55,   158,    24,    25,   125,   119,   128,    -1,    30,
     150,    -1,    -1,    -1,   161,    -1,    -1,   166,   158,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    18,    19,    20,    -1,    -1,    -1,
      24,    25,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    36,    37,    38,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      18,    -1,    20,    -1,    -1,    -1,    24,    25,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    37,
      38
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    10,    11,    12,
      13,    14,    18,    20,    24,    25,    30,    36,    37,    38,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    58,
      61,    62,    63,    66,    67,    68,    69,    72,    73,    76,
      77,    80,    81,    82,    83,    84,    85,    86,    87,    14,
      16,    14,    14,    14,    14,    14,    85,    68,    73,    19,
      88,    20,    68,    20,    20,    49,    20,    51,    20,    24,
      25,    33,    21,    22,    23,     3,    42,    44,    57,    76,
       0,    15,    64,    65,    68,    68,    65,    15,    65,    69,
      70,    71,    74,    75,    78,    70,     3,    43,    45,    15,
      48,    20,    77,    77,    68,    76,    76,    76,    14,    16,
      33,    39,    20,    15,    39,    17,    15,    15,    15,    26,
      28,    29,    32,    34,    35,    27,    31,    15,    33,    39,
      20,    19,    20,    90,    91,     7,    68,    79,     3,    44,
      64,    49,    75,    69,    69,    69,    69,    69,    78,    74,
      89,    79,    45,    15,    59,    60,    85,    17,     9,    49,
      15,    39,     3,    33,    49,    59,    33,    18,    47,    68,
       7,    46,    19,    39,     7
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    87,    48,    48,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    73,    73,    50,    88,
      51,    51,    52,    52,    89,    63,    53,    53,    66,    67,
      68,    62,    62,    70,    72,    72,    72,    86,    86,    86,
      76,    76,    76,    76,    77,    77,    77,    77,    69,    69,
      69,    74,    74,    74,    74,    74,    74,    78,    78,    75,
      75,    71,    71,    79,    85,    85,    54,    54,    42,    42,
      42,    44,    44,    43,    45,    45,    55,    56,    57,    57,
      47,    46,    46,    84,    90,    61,    91,    61,    58,    59,
      59,    60,    60,    60,    80,    80,    64,    64,    65,    81,
      81,    82,    82,    83
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     4,     0,
       4,     2,     5,     7,     0,     6,     3,     2,     2,     2,
       1,     2,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     2,     1,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     3,     1,     3,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     3,
       1,     3,     1,     3,     3,     1,     4,     3,     4,     6,
       3,     3,     1,     4,     0,     5,     0,     6,     2,     3,
       1,     4,     2,     1,     4,     3,     3,     1,     1,     1,
       1,     4,     4,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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
      yychar = yylex ();
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
        case 2:
#line 61 "src/parser.y" /* yacc.c:1646  */
    {
        ast.setRoot((yyvsp[0].stmttype));
    }
#line 1429 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 66 "src/parser.y" /* yacc.c:1646  */
    {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1435 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 67 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.stmttype) = new SeqNode((yyvsp[-1].stmttype), (yyvsp[0].stmttype));
    }
#line 1443 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 72 "src/parser.y" /* yacc.c:1646  */
    {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1449 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 73 "src/parser.y" /* yacc.c:1646  */
    {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1455 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 74 "src/parser.y" /* yacc.c:1646  */
    {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1461 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 75 "src/parser.y" /* yacc.c:1646  */
    {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1467 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 76 "src/parser.y" /* yacc.c:1646  */
    {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1473 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 77 "src/parser.y" /* yacc.c:1646  */
    {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1479 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 78 "src/parser.y" /* yacc.c:1646  */
    {(yyval.stmttype)=(yyvsp[-1].stmttype);}
#line 1485 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 79 "src/parser.y" /* yacc.c:1646  */
    {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1491 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 80 "src/parser.y" /* yacc.c:1646  */
    {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1497 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 81 "src/parser.y" /* yacc.c:1646  */
    {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1503 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 82 "src/parser.y" /* yacc.c:1646  */
    {(yyval.stmttype)=(yyvsp[0].stmttype);}
#line 1509 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 86 "src/parser.y" /* yacc.c:1646  */
    {
        SymbolEntry *se;
        se = identifiers->lookup((yyvsp[0].strtype));
        if(se == nullptr)
        {
            fprintf(stderr, "identifier \"%s\" is undefined\n", (char*)(yyvsp[0].strtype));
            delete [](char*)(yyvsp[0].strtype);
            assert(se != nullptr);
        }
        /*Id* tempid;
        if(dynamic_cast<IdentifierSymbolEntry*>(se)->isParam()||dynamic_cast<IdentifierSymbolEntry*>(se)->isGlobal())
        {
            tempid=dynamic_cast<IdentifierSymbolEntry*>(se)->getTempReg();
        }
        else
        {
            tempid=new Id(se);
        }*/
        (yyval.exprtype) = new Id(se);
        delete [](yyvsp[0].strtype);
    }
#line 1535 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 108 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.exprtype) = (yyvsp[0].exprtype);
    }
#line 1543 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 114 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.stmttype) = new AssignStmt((yyvsp[-3].exprtype), (yyvsp[-1].exprtype));
    }
#line 1551 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 120 "src/parser.y" /* yacc.c:1646  */
    {identifiers = new SymbolTable(identifiers);}
#line 1557 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 122 "src/parser.y" /* yacc.c:1646  */
    {
            (yyval.stmttype) = new CompoundStmt((yyvsp[-1].stmttype));
            SymbolTable *top = identifiers;
            identifiers = identifiers->getPrev();
            delete top;
        }
#line 1568 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 130 "src/parser.y" /* yacc.c:1646  */
    {
            (yyval.stmttype)= new CompoundStmt();
        }
#line 1576 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 135 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.stmttype) = new IfStmt((yyvsp[-2].exprtype), (yyvsp[0].stmttype));
    }
#line 1584 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 138 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.stmttype) = new IfElseStmt((yyvsp[-4].exprtype), (yyvsp[-2].stmttype), (yyvsp[0].stmttype));
    }
#line 1592 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 145 "src/parser.y" /* yacc.c:1646  */
    {
        WhileStmt* ThisWhilestmt = new WhileStmt((yyvsp[-1].exprtype));
        whileStack.push((StmtNode*)(ThisWhilestmt));
    }
#line 1601 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 149 "src/parser.y" /* yacc.c:1646  */
    {
        WhileStmt* ThisWhilestmt = (WhileStmt*)(whileStack.top());
        ThisWhilestmt->setDostmt((yyvsp[0].stmttype));
        (yyval.stmttype) = ThisWhilestmt;
        whileStack.pop();
    }
#line 1612 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 157 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.stmttype) = new ReturnStmt((yyvsp[-1].exprtype));
        currentRet=(yyvsp[-1].exprtype)->getSymPtr();
        isReturn=1;
    }
#line 1622 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 163 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.stmttype) = new ReturnStmt;
        isReturn=1;
    }
#line 1631 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 170 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.stmttype) = new BreakStmt(whileStack.top());
    }
#line 1639 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 176 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.stmttype) = new ContinueStmt(whileStack.top());
    }
#line 1647 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 182 "src/parser.y" /* yacc.c:1646  */
    {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1653 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 188 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.stmttype)=new ExprStmt((yyvsp[-1].exprtype));
    }
#line 1661 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 193 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.stmttype)=new ExprStmt(nullptr);
    }
#line 1669 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 200 "src/parser.y" /* yacc.c:1646  */
    {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1675 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 204 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.exprtype) = (yyvsp[0].exprtype);
    }
#line 1683 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 207 "src/parser.y" /* yacc.c:1646  */
    {
        SymbolEntry *se = new ConstantSymbolEntry(TypeSystem::intType, (yyvsp[0].itype));
        (yyval.exprtype) = new Constant(se);
    }
#line 1692 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 211 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.exprtype) = (yyvsp[-1].exprtype);
    }
#line 1700 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 220 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.chartype)='+';
    }
#line 1708 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 225 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.chartype)='-';
    }
#line 1716 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 230 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.chartype)='!';
    }
#line 1724 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 236 "src/parser.y" /* yacc.c:1646  */
    {(yyval.exprtype)=(yyvsp[0].exprtype);}
#line 1730 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 239 "src/parser.y" /* yacc.c:1646  */
    {
	    SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
	    (yyval.exprtype) = new UnaryExpr(se, UnaryExpr::FUNC, (yyvsp[0].exprtype));
    }
#line 1739 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 244 "src/parser.y" /* yacc.c:1646  */
    {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1745 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 246 "src/parser.y" /* yacc.c:1646  */
    {
        SymbolEntry*se=new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        int op;
        switch((yyvsp[-1].chartype))
        {
            case '+' :
                op = UnaryExpr::ADD;
                break;
            case '-' :
                op = UnaryExpr::SUB;
                break;
            case '!' :
                op = UnaryExpr::NOT;
                break;
        }
        (yyval.exprtype) = new UnaryExpr(se, op , (yyvsp[0].exprtype));
    }
#line 1767 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 266 "src/parser.y" /* yacc.c:1646  */
    {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1773 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 269 "src/parser.y" /* yacc.c:1646  */
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::MUL, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));   
    }
#line 1782 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 275 "src/parser.y" /* yacc.c:1646  */
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::DIV, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));   
    }
#line 1791 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 281 "src/parser.y" /* yacc.c:1646  */
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::MOD, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));   
    }
#line 1800 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 288 "src/parser.y" /* yacc.c:1646  */
    {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1806 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 291 "src/parser.y" /* yacc.c:1646  */
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::ADD, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1815 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 297 "src/parser.y" /* yacc.c:1646  */
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::intType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::SUB, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1824 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 304 "src/parser.y" /* yacc.c:1646  */
    {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1830 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 307 "src/parser.y" /* yacc.c:1646  */
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::LESS, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1839 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 313 "src/parser.y" /* yacc.c:1646  */
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::GREATER, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1848 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 319 "src/parser.y" /* yacc.c:1646  */
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::NOTEQUAL, (yyvsp[-2].exprtype), (yyvsp[0].exprtype)); 
    }
#line 1857 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 325 "src/parser.y" /* yacc.c:1646  */
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::GREATEREQ, (yyvsp[-2].exprtype), (yyvsp[0].exprtype)); 
    }
#line 1866 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 331 "src/parser.y" /* yacc.c:1646  */
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::LESSEQ, (yyvsp[-2].exprtype), (yyvsp[0].exprtype)); 
    }
#line 1875 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 338 "src/parser.y" /* yacc.c:1646  */
    {(yyval.exprtype)=(yyvsp[0].exprtype);}
#line 1881 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 341 "src/parser.y" /* yacc.c:1646  */
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::EQUAL, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));      
    }
#line 1890 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 348 "src/parser.y" /* yacc.c:1646  */
    {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1896 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 351 "src/parser.y" /* yacc.c:1646  */
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::AND, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1905 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 358 "src/parser.y" /* yacc.c:1646  */
    {(yyval.exprtype) = (yyvsp[0].exprtype);}
#line 1911 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 361 "src/parser.y" /* yacc.c:1646  */
    {
        SymbolEntry *se = new TemporarySymbolEntry(TypeSystem::boolType, SymbolTable::getLabel());
        (yyval.exprtype) = new BinaryExpr(se, BinaryExpr::OR, (yyvsp[-2].exprtype), (yyvsp[0].exprtype));
    }
#line 1920 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 368 "src/parser.y" /* yacc.c:1646  */
    {(yyval.exprtype)=(yyvsp[0].exprtype);}
#line 1926 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 371 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.type) = TypeSystem::intType;
    }
#line 1934 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 374 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.type) = TypeSystem::voidType;
    }
#line 1942 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 380 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.stmttype)=(yyvsp[0].stmttype);
    }
#line 1950 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 384 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.stmttype)=(yyvsp[0].stmttype);
    }
#line 1958 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 391 "src/parser.y" /* yacc.c:1646  */
    {
        SymbolEntry *se;
        se = new IdentifierSymbolEntry(TypeSystem::intType, (yyvsp[0].strtype), identifiers->getLevel());
        dynamic_cast<IdentifierSymbolEntry*>(se)->setvar();
        identifiers->install((yyvsp[0].strtype), se);
        Id* tempid=new Id(se);
        if(dynamic_cast<IdentifierSymbolEntry*>(se)->isGlobal())
        {
            dynamic_cast<IdentifierSymbolEntry*>(se)->setTempReg(tempid);
        }
        (yyval.deftype)=new Def(tempid);
        delete [](yyvsp[0].strtype);
    }
#line 1976 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 406 "src/parser.y" /* yacc.c:1646  */
    {
        SymbolEntry *se;
        se = new IdentifierSymbolEntry(TypeSystem::intType, (yyvsp[-2].strtype), identifiers->getLevel());
        dynamic_cast<IdentifierSymbolEntry*>(se)->setvar();
        identifiers->install((yyvsp[-2].strtype), se);
        Id* tempid=new Id(se);
        if(dynamic_cast<IdentifierSymbolEntry*>(se)->isGlobal())
        {
            dynamic_cast<IdentifierSymbolEntry*>(se)->setTempReg(tempid);
        }
        (yyval.deftype)=new Def(tempid,(yyvsp[0].exprtype));
        delete [](yyvsp[-2].strtype);
    }
#line 1994 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 421 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.deftype)=new Def((yyvsp[0].stmttype));
    }
#line 2002 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 428 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.defstype)=new Defs((yyvsp[-2].deftype),(yyvsp[0].defstype));
    }
#line 2010 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 433 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.defstype)=new Defs((yyvsp[0].deftype));
    }
#line 2018 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 440 "src/parser.y" /* yacc.c:1646  */
    {
        SymbolEntry *se;
        se = new IdentifierSymbolEntry(TypeSystem::intType, (yyvsp[-2].strtype), identifiers->getLevel());
        dynamic_cast<IdentifierSymbolEntry*>(se)->setcon();
        identifiers->install((yyvsp[-2].strtype), se);
        Id* tempid=new Id(se);
        if(dynamic_cast<IdentifierSymbolEntry*>(se)->isGlobal())
        {
            dynamic_cast<IdentifierSymbolEntry*>(se)->setTempReg(tempid);
        }
        (yyval.deftype)=new Def(tempid,(yyvsp[0].exprtype));
        delete [](yyvsp[-2].strtype);
    }
#line 2036 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 458 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.defstype)=new Defs((yyvsp[-2].deftype),(yyvsp[0].defstype));
    }
#line 2044 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 463 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.defstype)=new Defs((yyvsp[0].deftype));
    }
#line 2052 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 469 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.stmttype)=new ConstDeclStmt((yyvsp[-1].defstype));
    }
#line 2060 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 476 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.stmttype)=new VarDeclStmt((yyvsp[-1].defstype));
    }
#line 2068 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 483 "src/parser.y" /* yacc.c:1646  */
    {
        SymbolEntry *se;
        se = new IdentifierSymbolEntry(TypeSystem::intType, (yyvsp[-3].strtype), identifiers->getLevel());
        dynamic_cast<IdentifierSymbolEntry*>(se)->setvar();
        identifiers->install((yyvsp[-3].strtype), se);
        Id* tempid=new Id(se);
        (yyval.stmttype)=new ArrayDeclStmt(tempid,(yyvsp[-1].itype));
    }
#line 2081 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 492 "src/parser.y" /* yacc.c:1646  */
    {
        SymbolEntry *se;
        se = new IdentifierSymbolEntry(TypeSystem::intType, (yyvsp[-5].strtype), identifiers->getLevel());
        dynamic_cast<IdentifierSymbolEntry*>(se)->setvar();
        identifiers->install((yyvsp[-5].strtype), se);
        Id* tempid=new Id(se);
        (yyval.stmttype)=new ArrayDeclStmt(tempid,(yyvsp[-3].itype),(yyvsp[0].arraydeftype));
    }
#line 2094 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 504 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.arraydeftype)=new ArrayDef((yyvsp[-1].arrayinitstype));
    }
#line 2102 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 511 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.arrayinitstype)=new ArrayInits((yyvsp[0].itype),(yyvsp[-2].arrayinitstype));
    }
#line 2110 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 515 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.arrayinitstype)=new ArrayInits((yyvsp[0].itype));
    }
#line 2118 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 522 "src/parser.y" /* yacc.c:1646  */
    {
        SymbolEntry *se=identifiers->lookup((yyvsp[-3].strtype));
        if(!se)
        {
            fprintf(stderr, "identifier \"%s\" is undefined\n", (char*)(yyvsp[-3].strtype));
            delete [](char*)(yyvsp[-3].strtype);
            assert(se != nullptr);
        }
        Id* tempid=new Id(se);
        (yyval.exprtype)=new ArrayMember(tempid,(yyvsp[-1].exprtype),se);
    }
#line 2134 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 539 "src/parser.y" /* yacc.c:1646  */
    {       
        identifiers = new SymbolTable(identifiers);
    }
#line 2142 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 543 "src/parser.y" /* yacc.c:1646  */
    {
        string funcname;
        funcname=(yyvsp[-3].strtype);
        if(funcname!="main")
        {
            funcname+='0';
        }
        SymbolTable*p=identifiers->getPrev();
        Type *funcType;
        funcType = new FunctionType((yyvsp[-4].type),{});
        SymbolEntry *se = new IdentifierSymbolEntry(funcType,funcname.c_str(), p->getLevel());
        currentSe = se;
        p->install(funcname.c_str(),se);
        (yyval.stmttype)=new FunctionDecl(new Id(currentSe),0);
        delete [](yyvsp[-3].strtype);
        params=0;
    }
#line 2164 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 562 "src/parser.y" /* yacc.c:1646  */
    {    
        identifiers = new SymbolTable(identifiers);
    }
#line 2172 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 566 "src/parser.y" /* yacc.c:1646  */
    {
        string funcname;
        funcname=(yyvsp[-4].strtype);
        funcname+=params+'0';
        SymbolTable*p=identifiers->getPrev();
        Type *funcType;
        funcType = new FunctionType((yyvsp[-5].type),{});
        SymbolEntry *se = new IdentifierSymbolEntry(funcType, funcname.c_str(), p->getLevel());
        currentSe = se;
        p->install(funcname.c_str(),se);
        (yyval.stmttype)=new FunctionDecl(new Id(currentSe),(yyvsp[-1].stmttype));
        delete [](yyvsp[-4].strtype);
        params=0;
    }
#line 2191 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 584 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.stmttype)=new FunctionDef((yyvsp[-1].stmttype),(yyvsp[0].stmttype));
        SymbolTable *top = identifiers;
        identifiers = identifiers->getPrev();
        delete top;
        dynamic_cast<FunctionType*>(dynamic_cast<FunctionDecl*>(dynamic_cast<FunctionDef*>((yyval.stmttype))->getdecl())->getid()->getSymPtr()->getType())->setReturn(currentRet);
        dynamic_cast<FunctionType*>(dynamic_cast<FunctionDecl*>(dynamic_cast<FunctionDef*>((yyval.stmttype))->getdecl())->getid()->getSymPtr()->getType())->setisret(isReturn);
        currentRet=0;
        isReturn=0;
    }
#line 2206 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 598 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.stmttype) = new funcParams((yyvsp[-2].stmttype), (yyvsp[0].stmttype));
    }
#line 2214 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 602 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.stmttype) =new funcParams((yyvsp[0].stmttype));
    }
#line 2222 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 609 "src/parser.y" /* yacc.c:1646  */
    {
        params++;
        SymbolEntry *se;
        se = new IdentifierSymbolEntry((yyvsp[-3].type), (yyvsp[-2].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[-2].strtype), se);
        Id* tempid=new Id(se);
        dynamic_cast<IdentifierSymbolEntry*>(se)->setTempReg(tempid);
        (yyval.stmttype) = new funcParam(tempid, (yyvsp[0].exprtype),(yyvsp[-3].type));
        delete [](yyvsp[-2].strtype);
    }
#line 2237 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 620 "src/parser.y" /* yacc.c:1646  */
    {
        params++;
        SymbolEntry *se;
        se = new IdentifierSymbolEntry((yyvsp[-1].type), (yyvsp[0].strtype), identifiers->getLevel());
        identifiers->install((yyvsp[0].strtype), se);
        Id* tempid=new Id(se);
        dynamic_cast<IdentifierSymbolEntry*>(se)->setTempReg(tempid);
        (yyval.stmttype) = new funcParam(tempid,(yyvsp[-1].type));
        delete [](yyvsp[0].strtype);
    }
#line 2252 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 631 "src/parser.y" /* yacc.c:1646  */
    {
        params++;
        (yyval.stmttype)=new funcParam(0,0,(yyvsp[0].type));
    }
#line 2261 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 639 "src/parser.y" /* yacc.c:1646  */
    {
        string funcname=(yyvsp[-3].strtype);
        if(funcname!="putint"&&funcname!="getint"&&funcname!="getch"&&funcname!="putch"&&funcname!="getarray"&&funcname!="putarray")
            funcname+=params+'0';
        SymbolEntry* se = identifiers->lookup(funcname.c_str());
        if(se == nullptr)
        {
            fprintf(stderr, "identifier \"%s\" is undefined\n", funcname.c_str());
            delete [](char*)(yyvsp[-3].strtype);
            assert(se != nullptr);
        }
        
        SymbolEntry* thisSe= new IdentifierSymbolEntry(dynamic_cast<FunctionType*>(se->getType())->getRetType(), funcname.c_str(), identifiers->getLevel());
        (yyval.exprtype) = new funcCall(se,thisSe,(yyvsp[-1].stmttype));
        params=0;
    }
#line 2282 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 656 "src/parser.y" /* yacc.c:1646  */
    {
        string funcname=(yyvsp[-2].strtype);
        if(funcname!="putint"&&funcname!="getint"&&funcname!="getch"&&funcname!="putch"&&funcname!="getarray"&&funcname!="putarray")
            funcname+=params+'0';
        SymbolEntry* se = identifiers->lookup(funcname.c_str());
        if(se == nullptr)
        {
            fprintf(stderr, "identifier \"%s\" is undefined\n", funcname.c_str());
            delete [](char*)(yyvsp[-2].strtype);
            assert(se != nullptr);
        }
        
        SymbolEntry* thisSe= new IdentifierSymbolEntry(dynamic_cast<FunctionType*>(se->getType())->getRetType(),funcname.c_str(), identifiers->getLevel());
        (yyval.exprtype) = new funcCall(se,thisSe,nullptr);
        params =0;
    }
#line 2303 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 676 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.stmttype) = new funcCallParas((yyvsp[-2].stmttype), (yyvsp[0].stmttype));
    }
#line 2311 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 680 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.stmttype) = new funcCallParas((yyvsp[0].stmttype));
    }
#line 2319 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 687 "src/parser.y" /* yacc.c:1646  */
    {
        params++;
        (yyval.stmttype) = new funcCallPara( (yyvsp[0].exprtype));
    }
#line 2328 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 695 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.exprtype) = (yyvsp[0].exprtype);
    }
#line 2336 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 699 "src/parser.y" /* yacc.c:1646  */
    {
        (yyval.exprtype) = (yyvsp[0].exprtype);
    }
#line 2344 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 706 "src/parser.y" /* yacc.c:1646  */
    {
        SymbolEntry* se = identifiers->lookup((yyvsp[-3].strtype));
        (yyval.exprtype) = new OStreamFunction(se, (yyvsp[-1].stmttype), 0);

    }
#line 2354 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 712 "src/parser.y" /* yacc.c:1646  */
    {
        SymbolEntry* se = identifiers->lookup((yyvsp[-3].strtype));
        (yyval.exprtype) = new OStreamFunction(se, (yyvsp[-1].stmttype), 1);
    }
#line 2363 "src/parser.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 720 "src/parser.y" /* yacc.c:1646  */
    {
        SymbolEntry* se = identifiers->lookup((yyvsp[-2].strtype));
        (yyval.exprtype) = new IStreamFunction(se, nullptr);
    }
#line 2372 "src/parser.cpp" /* yacc.c:1646  */
    break;


#line 2376 "src/parser.cpp" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 726 "src/parser.y" /* yacc.c:1906  */


int yyerror(char const* message)
{
    std::cerr<<message<<std::endl;
    return -1;
}
