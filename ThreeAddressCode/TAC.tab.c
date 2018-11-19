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




/* Copy the first part of user declarations.  */
#line 1 "TAC.y" /* yacc.c:339  */

//Headers
#include <bits/stdc++.h>
using namespace std;


//Structure to be used
struct exprType{
	char *place;
	char *code;
};

//global Variables
int varNo=1;
int labNo=1;
char *s,*s1,*s2;
char* switchCaseVar;
struct exprType *to_return_expr;

void yyerror(char* s);
int yylex(void);

char* concat(char* a,char *b,char c);
char* newVar();
char* newLabel();
char* myatoi(int x);
void replace(char* og,char* oldS,char* newS);
exprType* operate(exprType* e1,exprType* e2,char oprt);
exprType* assignOperate(char* e1,exprType* e2,char oprt);

#line 97 "TAC.tab.c" /* yacc.c:339  */

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
   by #include "TAC.tab.h".  */
#ifndef YY_YY_TAC_TAB_H_INCLUDED
# define YY_YY_TAC_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    DIGIT = 258,
    FLOAT = 259,
    ID = 260,
    IF = 261,
    ELSE = 262,
    WHILE = 263,
    TYPES = 264,
    REL_OPT = 265,
    OR = 266,
    AND = 267,
    NOT = 268,
    TRUE = 269,
    FALSE = 270,
    PE = 271,
    CASE = 272,
    SWITCH = 273,
    INCR = 274,
    DECR = 275,
    BOR = 276,
    BAND = 277,
    BXOR = 278,
    DEFAULT = 279,
    ME = 280,
    IE = 281,
    DE = 282
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 34 "TAC.y" /* yacc.c:355  */

	int ival;
	float fval;
	char *sval;
	struct exprType *EXPRTYPE;

#line 172 "TAC.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TAC_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 189 "TAC.tab.c" /* yacc.c:358  */

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
#define YYFINAL  30
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   431

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  13
/* YYNRULES -- Number of rules.  */
#define YYNRULES  54
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  123

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   282

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      30,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    29,     2,     2,
      38,    39,    26,    24,    43,    25,     2,    27,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    42,    32,
       2,    31,     2,     2,    37,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    28,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,    41,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    33,
      34,    35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    63,    63,    76,    87,    92,    97,   108,   125,   142,
     156,   161,   166,   171,   176,   196,   210,   222,   227,   232,
     239,   246,   256,   261,   270,   281,   291,   296,   301,   306,
     311,   326,   343,   348,   354,   367,   379,   391,   399,   407,
     419,   424,   429,   434,   439,   444,   449,   454,   459,   464,
     469,   478,   488,   492,   499
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DIGIT", "FLOAT", "ID", "IF", "ELSE",
  "WHILE", "TYPES", "REL_OPT", "OR", "AND", "NOT", "TRUE", "FALSE", "PE",
  "CASE", "SWITCH", "INCR", "DECR", "BOR", "BAND", "BXOR", "'+'", "'-'",
  "'*'", "'/'", "'^'", "'%'", "'\\n'", "'='", "';'", "DEFAULT", "ME", "IE",
  "DE", "'@'", "'('", "')'", "'{'", "'}'", "':'", "','", "$accept",
  "startSym", "program", "construct", "block", "caseList", "list", "stat",
  "dec", "bool", "expr", "text", "number", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,    43,    45,    42,    47,    94,    37,
      10,    61,    59,   279,   280,   281,   282,    64,    40,    41,
     123,   125,    58,    44
};
# endif

#define YYPACT_NINF -34

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-34)))

#define YYTABLE_NINF -14

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     148,   -34,   -34,   -34,   -25,   -24,    16,   -16,   -34,    46,
     148,    26,   148,   -34,   -34,    89,   -34,    42,   252,   208,
     -34,    53,    53,   -15,    46,   224,   -34,   137,    -1,   130,
     -34,   -34,    24,   -34,    46,   -34,    46,    46,    46,    46,
      46,    46,    46,    46,   -34,    46,    46,    29,    33,    46,
      46,    46,    46,    31,   -34,   -34,    -8,   175,    13,    16,
     233,   -34,   -34,   -34,   -34,   -34,   269,   380,   387,   394,
     -18,   -18,    38,    38,    38,    38,   286,   -34,   -34,   303,
     320,   337,   354,    53,    53,    53,   155,    46,   155,   -34,
      36,   -34,   -34,   -34,   -34,   -34,   -34,    32,    65,   -34,
      92,   371,   -34,   -10,   -34,   155,    46,    59,    83,   -34,
     184,   155,    46,    61,   -34,   155,   -34,   193,   155,   -34,
     155,   -34,   -34
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    53,    54,    52,     0,     0,     0,     0,    21,     0,
       0,     0,     2,     4,     5,     0,    18,     0,     0,    50,
      51,     0,     0,    32,     0,     0,    50,     0,     4,     0,
       1,     3,     0,    19,     0,    23,     0,     0,     0,     0,
       0,     0,     0,     0,    22,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    37,    38,     0,     0,     0,     0,
       0,    40,    12,    11,    10,    20,     0,    47,    48,    49,
      41,    42,    44,    43,    45,    46,     0,    30,    31,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    33,
       0,    25,    26,    24,    27,    28,    29,     0,    35,    36,
       6,    34,     7,     0,    39,     0,     0,     0,     0,     8,
       0,     0,     0,     0,     9,     0,    17,     0,     0,    16,
       0,    15,    14
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -34,   -34,    94,    60,   -33,   -34,    99,   -13,   -34,   -21,
      -4,     0,   -34
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    11,    12,    31,    14,   108,    15,    16,    17,    56,
      18,    26,    20
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      19,    58,    33,    84,    85,    25,    23,   106,    41,    42,
      19,    43,    19,    21,    22,    19,    33,    57,    57,    45,
      60,     3,    24,   107,    84,    85,    30,    19,    59,    19,
      66,    86,    67,    68,    69,    70,    71,    72,    73,    74,
      63,    75,    76,    84,    85,    79,    80,    81,    82,     1,
       2,     3,    88,   100,    65,   102,     1,     2,     3,    89,
      13,    77,    97,    98,    99,    78,    53,    54,    55,    83,
      28,   104,   109,    34,    35,    45,   103,    85,   116,    57,
      57,    57,   119,   101,     9,   121,    19,   122,    19,   -13,
      32,     9,     1,     2,     3,   -13,   -13,   -13,     6,   105,
     112,   111,   110,   118,    27,    19,   -13,   -13,   117,    29,
       0,    19,     0,     0,     0,    19,   113,     0,    19,     0,
      19,     8,   -13,     0,   114,     0,     0,     9,     0,   -13,
     -13,    32,     0,     1,     2,     3,   -13,     0,   -13,     6,
       1,     2,     3,     4,     0,     5,     6,     0,   -13,     0,
       0,     1,     2,     3,     4,     7,     5,     6,     1,     2,
       3,     0,     8,     0,     6,     0,     7,     0,     9,     8,
     -13,    64,     0,     0,     0,     9,     0,    10,    62,     0,
       8,     0,     0,     0,     0,    87,     9,     8,    10,     0,
       0,     0,     0,     9,     0,    10,    36,    37,    38,    39,
      40,    41,    42,     0,    43,    36,    37,    38,    39,    40,
      41,    42,    45,    43,    36,    37,    38,    39,    40,    41,
      42,    45,    43,     0,    46,     0,   115,    47,    48,     0,
      45,     0,     0,     0,     0,   120,     0,     0,     0,    49,
       0,     0,    50,    51,    52,    36,    37,    38,    39,    40,
      41,    42,     0,    43,    36,    37,    38,    39,    40,    41,
      42,    45,    43,    61,     0,     0,     0,     0,     0,     0,
      45,     0,    90,    36,    37,    38,    39,    40,    41,    42,
       0,    43,     0,     0,    44,     0,     0,     0,     0,    45,
      36,    37,    38,    39,    40,    41,    42,     0,    43,     0,
       0,    91,     0,     0,     0,     0,    45,    36,    37,    38,
      39,    40,    41,    42,     0,    43,     0,     0,    92,     0,
       0,     0,     0,    45,    36,    37,    38,    39,    40,    41,
      42,     0,    43,     0,     0,    93,     0,     0,     0,     0,
      45,    36,    37,    38,    39,    40,    41,    42,     0,    43,
       0,     0,    94,     0,     0,     0,     0,    45,    36,    37,
      38,    39,    40,    41,    42,     0,    43,     0,     0,    95,
       0,     0,     0,     0,    45,    36,    37,    38,    39,    40,
      41,    42,     0,    43,     0,     0,    96,     0,     0,     0,
       0,    45,    36,    37,    38,    39,    40,    41,    42,     0,
      43,     0,    37,    38,    39,    40,    41,    42,    45,    43,
      38,    39,    40,    41,    42,     0,    43,    45,    39,    40,
      41,    42,     0,    43,    45,     0,     0,     0,     0,     0,
       0,    45
};

static const yytype_int8 yycheck[] =
{
       0,    22,    15,    11,    12,     9,     6,    17,    26,    27,
      10,    29,    12,    38,    38,    15,    29,    21,    22,    37,
      24,     5,    38,    33,    11,    12,     0,    27,    43,    29,
      34,    39,    36,    37,    38,    39,    40,    41,    42,    43,
      41,    45,    46,    11,    12,    49,    50,    51,    52,     3,
       4,     5,    39,    86,    30,    88,     3,     4,     5,    59,
       0,    32,    83,    84,    85,    32,    13,    14,    15,    38,
      10,    39,   105,    31,    32,    37,    40,    12,   111,    83,
      84,    85,   115,    87,    38,   118,    86,   120,    88,     0,
       1,    38,     3,     4,     5,     6,     7,     8,     9,     7,
      17,    42,   106,    42,    10,   105,    17,    18,   112,    10,
      -1,   111,    -1,    -1,    -1,   115,    33,    -1,   118,    -1,
     120,    32,    33,    -1,    41,    -1,    -1,    38,    -1,    40,
      41,     1,    -1,     3,     4,     5,     6,    -1,     8,     9,
       3,     4,     5,     6,    -1,     8,     9,    -1,    18,    -1,
      -1,     3,     4,     5,     6,    18,     8,     9,     3,     4,
       5,    -1,    32,    -1,     9,    -1,    18,    -1,    38,    32,
      40,    41,    -1,    -1,    -1,    38,    -1,    40,    41,    -1,
      32,    -1,    -1,    -1,    -1,    10,    38,    32,    40,    -1,
      -1,    -1,    -1,    38,    -1,    40,    21,    22,    23,    24,
      25,    26,    27,    -1,    29,    21,    22,    23,    24,    25,
      26,    27,    37,    29,    21,    22,    23,    24,    25,    26,
      27,    37,    29,    -1,    16,    -1,    42,    19,    20,    -1,
      37,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    31,
      -1,    -1,    34,    35,    36,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,    21,    22,    23,    24,    25,    26,
      27,    37,    29,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    -1,    39,    21,    22,    23,    24,    25,    26,    27,
      -1,    29,    -1,    -1,    32,    -1,    -1,    -1,    -1,    37,
      21,    22,    23,    24,    25,    26,    27,    -1,    29,    -1,
      -1,    32,    -1,    -1,    -1,    -1,    37,    21,    22,    23,
      24,    25,    26,    27,    -1,    29,    -1,    -1,    32,    -1,
      -1,    -1,    -1,    37,    21,    22,    23,    24,    25,    26,
      27,    -1,    29,    -1,    -1,    32,    -1,    -1,    -1,    -1,
      37,    21,    22,    23,    24,    25,    26,    27,    -1,    29,
      -1,    -1,    32,    -1,    -1,    -1,    -1,    37,    21,    22,
      23,    24,    25,    26,    27,    -1,    29,    -1,    -1,    32,
      -1,    -1,    -1,    -1,    37,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,    -1,    -1,    32,    -1,    -1,    -1,
      -1,    37,    21,    22,    23,    24,    25,    26,    27,    -1,
      29,    -1,    22,    23,    24,    25,    26,    27,    37,    29,
      23,    24,    25,    26,    27,    -1,    29,    37,    24,    25,
      26,    27,    -1,    29,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    37
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     8,     9,    18,    32,    38,
      40,    45,    46,    47,    48,    50,    51,    52,    54,    55,
      56,    38,    38,    55,    38,    54,    55,    46,    47,    50,
       0,    47,     1,    51,    31,    32,    21,    22,    23,    24,
      25,    26,    27,    29,    32,    37,    16,    19,    20,    31,
      34,    35,    36,    13,    14,    15,    53,    54,    53,    43,
      54,    39,    41,    41,    41,    30,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    32,    32,    54,
      54,    54,    54,    38,    11,    12,    39,    10,    39,    55,
      39,    32,    32,    32,    32,    32,    32,    53,    53,    53,
      48,    54,    48,    40,    39,     7,    17,    33,    49,    48,
      54,    42,    17,    33,    41,    42,    48,    54,    42,    48,
      42,    48,    48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    47,    47,    47,
      48,    48,    48,    48,    49,    49,    49,    49,    50,    50,
      50,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    52,    52,    53,    53,    53,    53,    53,    53,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    55,    56,    56
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     5,     5,     7,     7,
       3,     3,     3,     1,     5,     4,     4,     3,     1,     2,
       3,     1,     2,     2,     4,     4,     4,     4,     4,     4,
       3,     3,     2,     4,     3,     3,     3,     1,     1,     4,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     1
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
#line 64 "TAC.y" /* yacc.c:1646  */
    {
	char* s1 = (yyvsp[0].sval);
	char* lab = newLabel();
	replace(s1,"NEXT",lab);
	s1=concat(s1,lab,'\n');
	s1=concat(s1,"TERMINATE",':');
	s = s1;
	cout<<"The final Three Address Code is :"<<endl;
	cout<<s<<endl;
	(yyval.sval)=s;
}
#line 1415 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 77 "TAC.y" /* yacc.c:1646  */
    {
	char* s1= (yyvsp[-1].sval);
	char* s2= (yyvsp[0].sval);
	char* lab= newLabel();
	replace(s1,"NEXT",lab);
	s=concat(s1,lab,'\n');
	s=concat(s,s2,':');
	(yyval.sval)=s;
}
#line 1429 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 88 "TAC.y" /* yacc.c:1646  */
    {
	(yyval.sval) = (yyvsp[0].sval);
}
#line 1437 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 93 "TAC.y" /* yacc.c:1646  */
    {
	(yyval.sval)=(yyvsp[0].sval);
}
#line 1445 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 98 "TAC.y" /* yacc.c:1646  */
    {
	char* lab = newLabel();
	char* s1 = (yyvsp[-2].sval);
	replace(s1,"TRUE",lab);
	replace(s1,"FAIL","NEXT");
	s=concat((yyvsp[-2].sval),lab,'\n');
	s=concat(s,(yyvsp[0].sval),':');
	(yyval.sval)=s;
}
#line 1459 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 109 "TAC.y" /* yacc.c:1646  */
    {
	char* b1=(yyvsp[-2].sval);
	char* s1=(yyvsp[0].sval);
	char* beg= newLabel();
	char* lab= newLabel();
	replace(b1,"TRUE",lab);
	replace(b1,"FAIL","NEXT");
	replace(s1,"NEXT",beg);
	s=concat(beg,b1,':');
	s=concat(s,lab,'\n');
	s=concat(s,s1,':');
	s=concat(s,"jump ",'\n');
	s=concat(s,beg,' ');
	(yyval.sval)=s;
}
#line 1479 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 126 "TAC.y" /* yacc.c:1646  */
    {
	char* b1=(yyvsp[-4].sval);
	char* lab1=newLabel();
	replace(b1,"TRUE",lab1);
	char* lab2=newLabel();
	replace(b1,"FAIL",lab2);
	char* stp;
	stp=concat(b1,lab1,'\n');
	stp=concat(stp,(yyvsp[-2].sval),':');
	stp=concat(stp,"jump NEXT",'\n');
	char* tp=concat(lab2,(yyvsp[0].sval),':');
	strcat(stp,"\n");
	strcat(stp,tp);
	(yyval.sval)=stp;
}
#line 1499 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 143 "TAC.y" /* yacc.c:1646  */
    {
	char* s1= (yyvsp[-1].sval);
	replace(s1,"VARI",(yyvsp[-4].EXPRTYPE)->place);
	char* lab=newLabel();
	replace(s1,"NEXT",lab);
	char* stp;
	stp=concat(s1,lab,'\n');
	char* cd;
	cd=concat((yyvsp[-4].EXPRTYPE)->code,stp,':');
	(yyval.sval)=cd;
}
#line 1515 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 157 "TAC.y" /* yacc.c:1646  */
    {
	(yyval.sval)=(yyvsp[-1].sval);
}
#line 1523 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 162 "TAC.y" /* yacc.c:1646  */
    {
	(yyval.sval)=(yyvsp[-1].sval);
}
#line 1531 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 167 "TAC.y" /* yacc.c:1646  */
    {
	(yyval.sval)=(yyvsp[-1].sval);
}
#line 1539 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 172 "TAC.y" /* yacc.c:1646  */
    {
	(yyval.sval)=(yyvsp[0].sval);
}
#line 1547 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 177 "TAC.y" /* yacc.c:1646  */
    {

	char* s1= (yyvsp[-4].sval);
	char* lab=newLabel();
	replace(s1,"NEXT",lab);
	char* str = (yyvsp[-2].EXPRTYPE)->place;
	char* stp;
	stp=concat(s1,lab,'\n');
	stp=concat(stp,(yyvsp[-2].EXPRTYPE)->code,':');
	stp=concat(stp,"if(",'\n');
	strcat(stp,"VARI");
	stp=concat(stp,"!=",' ');
	strcat(stp,str);
	strcat(stp,")");
	stp=concat(stp,"jump NEXT",' ');
	stp=concat(stp,(yyvsp[0].sval),'\n');
	(yyval.sval)=stp;
}
#line 1570 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 197 "TAC.y" /* yacc.c:1646  */
    {
	char* s1= (yyvsp[-3].sval);
	char* lab=newLabel();
	replace(s1,"NEXT",lab);
	char* str = " ";
	char* stp;
	stp=concat(s1,lab,'\n');
	stp=concat(stp," ",':');
	stp=concat(stp,"jump NEXT",' ');
	stp=concat(stp,(yyvsp[0].sval),'\n');
	(yyval.sval)=stp;
}
#line 1587 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 211 "TAC.y" /* yacc.c:1646  */
    {
	char* stp;
	stp=concat("if(","VARI",' ');
	stp=concat(stp,"!=",' ');
	strcat(stp,(yyvsp[-2].EXPRTYPE)->place);
	strcat(stp,")");
	stp=concat(stp,"jump NEXT",' ');
	stp=concat(stp,(yyvsp[0].sval),'\n');
	(yyval.sval)=concat((yyvsp[-2].EXPRTYPE)->code,stp,'\n');
}
#line 1602 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 223 "TAC.y" /* yacc.c:1646  */
    {
	(yyval.sval)=concat((yyvsp[0].sval)," ",'\n');	
}
#line 1610 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 228 "TAC.y" /* yacc.c:1646  */
    {
	(yyval.sval)=(yyvsp[0].EXPRTYPE)->code;
}
#line 1618 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 233 "TAC.y" /* yacc.c:1646  */
    {
	s1=(yyvsp[-1].sval);
	s2=(yyvsp[0].EXPRTYPE)->code;
	(yyval.sval)=concat(s1,s2,'\n');
}
#line 1628 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 240 "TAC.y" /* yacc.c:1646  */
    {
  yyerrok;
}
#line 1636 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 247 "TAC.y" /* yacc.c:1646  */
    {
	to_return_expr = new exprType();
	to_return_expr->place = (yyvsp[0].sval);
	to_return_expr->code = new char[20];
	to_return_expr->code[0]=0;

	(yyval.EXPRTYPE)=to_return_expr;
}
#line 1649 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 257 "TAC.y" /* yacc.c:1646  */
    {
	(yyval.EXPRTYPE)=(yyvsp[-1].EXPRTYPE);
}
#line 1657 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 262 "TAC.y" /* yacc.c:1646  */
    {
	to_return_expr = new exprType();
	to_return_expr->place = (yyvsp[-1].sval);
	to_return_expr->code = new char[20];
	to_return_expr->code[0]=0;
	(yyval.EXPRTYPE) = to_return_expr;
}
#line 1669 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 271 "TAC.y" /* yacc.c:1646  */
    {
	to_return_expr = new exprType();
	to_return_expr->place =  newVar();
	char *tp = concat((yyvsp[-3].sval),(yyvsp[-1].EXPRTYPE)->place,'=');

	s=concat((yyvsp[-1].EXPRTYPE)->code,tp,'\n');
	to_return_expr->code = s;
	(yyval.EXPRTYPE) = to_return_expr;
}
#line 1683 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 282 "TAC.y" /* yacc.c:1646  */
    {
	to_return_expr = new exprType();
	to_return_expr->place =  newVar();
	char *tp = concat((yyvsp[-3].sval),(yyvsp[-1].EXPRTYPE)->place,'=');
	s=concat((yyvsp[-1].EXPRTYPE)->code,tp,'\n');
	to_return_expr->code = s;
	(yyval.EXPRTYPE) = to_return_expr;
}
#line 1696 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 292 "TAC.y" /* yacc.c:1646  */
    {
	(yyval.EXPRTYPE)=assignOperate((yyvsp[-3].sval),(yyvsp[-1].EXPRTYPE),'+');		
}
#line 1704 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 297 "TAC.y" /* yacc.c:1646  */
    {
	(yyval.EXPRTYPE)=assignOperate((yyvsp[-3].sval),(yyvsp[-1].EXPRTYPE),'-');
}
#line 1712 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 302 "TAC.y" /* yacc.c:1646  */
    {
	(yyval.EXPRTYPE)=assignOperate((yyvsp[-3].sval),(yyvsp[-1].EXPRTYPE),'*');
}
#line 1720 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 307 "TAC.y" /* yacc.c:1646  */
    {
	(yyval.EXPRTYPE)=assignOperate((yyvsp[-3].sval),(yyvsp[-1].EXPRTYPE),'/');
}
#line 1728 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 312 "TAC.y" /* yacc.c:1646  */
    {
	to_return_expr = new exprType();
	to_return_expr->place=newVar();
	char* tp =concat(to_return_expr->place,(yyvsp[-2].sval),'=');
	tp=concat(tp,"1",'+');
	strcat(tp,"\n");
	char* stp;
	stp=concat(" ",tp,'\n');
	s=concat((yyvsp[-2].sval),to_return_expr->place,'=');
	strcat(stp,s);
	to_return_expr->code=stp;		
	(yyval.EXPRTYPE)=to_return_expr;
}
#line 1746 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 327 "TAC.y" /* yacc.c:1646  */
    {
	to_return_expr = new exprType();
	to_return_expr->place=newVar();
	char* tp =concat(to_return_expr->place,(yyvsp[-2].sval),'=');
	tp=concat(tp,"1",'-');
	strcat(tp,"\n");
	char* stp;
	stp=concat(" ",tp,'\n');
	s=concat((yyvsp[-2].sval),to_return_expr->place,'=');
	strcat(stp,s);
	to_return_expr->code=stp;		
	(yyval.EXPRTYPE)=to_return_expr;	
}
#line 1764 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 344 "TAC.y" /* yacc.c:1646  */
    {
	(yyval.sval)=(yyvsp[0].sval);
}
#line 1772 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 349 "TAC.y" /* yacc.c:1646  */
    {
	cout<<"Here \n";
	// $$=concat($1,$2,'\n');
}
#line 1781 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 355 "TAC.y" /* yacc.c:1646  */
    {
	char* tp;
	tp=concat("if(",(yyvsp[-2].EXPRTYPE)->place,' ');
	tp=concat(tp,(yyvsp[-1].sval),' ');
	tp=concat(tp,(yyvsp[0].EXPRTYPE)->place,' ');
	tp=concat(tp,") jump TRUE \n jump FAIL",' ');
	char* st;
	st=concat((yyvsp[-2].EXPRTYPE)->code,(yyvsp[0].EXPRTYPE)->code,'\n');
	st=concat(st,tp,'\n');
	(yyval.sval)=st;
}
#line 1797 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 368 "TAC.y" /* yacc.c:1646  */
    {
	char* tp;
	char* s1=(yyvsp[-2].sval);
	char* s2=(yyvsp[0].sval);
	char* lab=newLabel();
	replace(s1,"FAIL",lab);
	tp=concat(s1,lab,'\n');
	tp=concat(tp,s2,':');
	(yyval.sval)=tp;
}
#line 1812 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 380 "TAC.y" /* yacc.c:1646  */
    {
	char* tp;
	char* s1=(yyvsp[-2].sval);
	char* s2=(yyvsp[0].sval);
	char* lab=newLabel();
	replace(s1,"TRUE",lab);
	tp=concat(s1,lab,'\n');
	tp=concat(tp,s2,':');
	(yyval.sval)=tp;
}
#line 1827 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 392 "TAC.y" /* yacc.c:1646  */
    {
	s = (char *)malloc(20);
	s[0] = 0;
	strcat(s,"\njump TRUE");
	(yyval.sval) = s;
}
#line 1838 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 400 "TAC.y" /* yacc.c:1646  */
    {
	s = (char *)malloc(20);
	s[0] = 0;
	strcat(s,"\njump FAIL");
	(yyval.sval) = s;
}
#line 1849 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 408 "TAC.y" /* yacc.c:1646  */
    {
	char* lab="TEMP";
	char* sl=(yyvsp[-1].sval);
	replace(sl,"TRUE",lab);
	replace(sl,"FAIL","TRUE");
	replace(sl,lab,"FAIL");
	(yyval.sval)=sl;
}
#line 1862 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 420 "TAC.y" /* yacc.c:1646  */
    {
	(yyval.EXPRTYPE)=(yyvsp[-1].EXPRTYPE);
}
#line 1870 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 425 "TAC.y" /* yacc.c:1646  */
    {
	(yyval.EXPRTYPE)=operate((yyvsp[-2].EXPRTYPE),(yyvsp[0].EXPRTYPE),'+');
}
#line 1878 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 430 "TAC.y" /* yacc.c:1646  */
    {
	(yyval.EXPRTYPE)=operate((yyvsp[-2].EXPRTYPE),(yyvsp[0].EXPRTYPE),'-');
}
#line 1886 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 435 "TAC.y" /* yacc.c:1646  */
    {
	(yyval.EXPRTYPE)=operate((yyvsp[-2].EXPRTYPE),(yyvsp[0].EXPRTYPE),'/');
}
#line 1894 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 440 "TAC.y" /* yacc.c:1646  */
    {
	(yyval.EXPRTYPE)=operate((yyvsp[-2].EXPRTYPE),(yyvsp[0].EXPRTYPE),'*');
}
#line 1902 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 445 "TAC.y" /* yacc.c:1646  */
    {
	(yyval.EXPRTYPE)=operate((yyvsp[-2].EXPRTYPE),(yyvsp[0].EXPRTYPE),'%');
}
#line 1910 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 450 "TAC.y" /* yacc.c:1646  */
    {
	(yyval.EXPRTYPE)=operate((yyvsp[-2].EXPRTYPE),(yyvsp[0].EXPRTYPE),'@');
}
#line 1918 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 455 "TAC.y" /* yacc.c:1646  */
    {
	(yyval.EXPRTYPE)=operate((yyvsp[-2].EXPRTYPE),(yyvsp[0].EXPRTYPE),'|');
}
#line 1926 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 460 "TAC.y" /* yacc.c:1646  */
    {
	(yyval.EXPRTYPE)=operate((yyvsp[-2].EXPRTYPE),(yyvsp[0].EXPRTYPE),'&');
}
#line 1934 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 465 "TAC.y" /* yacc.c:1646  */
    {
	(yyval.EXPRTYPE)=operate((yyvsp[-2].EXPRTYPE),(yyvsp[0].EXPRTYPE),'^');
}
#line 1942 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 470 "TAC.y" /* yacc.c:1646  */
    {
	to_return_expr = new exprType();
	to_return_expr->place = (yyvsp[0].sval);
	to_return_expr->code = new char[2];
	to_return_expr->code[0]=0;
	(yyval.EXPRTYPE) = to_return_expr;
}
#line 1954 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 479 "TAC.y" /* yacc.c:1646  */
    {
	to_return_expr = (struct exprType *)malloc(sizeof(struct exprType));
	to_return_expr->place = (yyvsp[0].sval);
	to_return_expr->code = new char[2];
	to_return_expr->code[0] = 0;
	(yyval.EXPRTYPE) = to_return_expr;
}
#line 1966 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 488 "TAC.y" /* yacc.c:1646  */
    {
	(yyval.sval)=(yyvsp[0].sval);
}
#line 1974 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 493 "TAC.y" /* yacc.c:1646  */
    {
	s = new char[20];
   	snprintf(s, 10,"%d",(yyvsp[0].ival));
	(yyval.sval) = s;        
}
#line 1984 "TAC.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 500 "TAC.y" /* yacc.c:1646  */
    {
	s = (char *)malloc(20);
   	snprintf(s, 10,"%f",(yyvsp[0].fval));
	(yyval.sval) = s;          
}
#line 1994 "TAC.tab.c" /* yacc.c:1646  */
    break;


#line 1998 "TAC.tab.c" /* yacc.c:1646  */
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
#line 506 "TAC.y" /* yacc.c:1906  */



char* concat(char *a,char *b,char c){
	s =new char[strlen(a)+strlen(b)+10];
	s[0]=0;
	string str="";
	str+=c;
	if(a[0]){
	strcat(s,a);
	strcat(s,str.c_str());
	}
	if(b[0])
	strcat(s,b);
	return s;
}

char* newVar(){
	s = new char[10];
	s[0]=0;
	strcat(s,"t");
	strcat(s,myatoi(varNo));
	varNo++;
	return s;
} 

char* newLabel(){
	s = new char[10];
	s[0]=0;
	strcat(s,"L");
	strcat(s,myatoi(labNo));
	labNo++;
	return s;
}

extern int yyparse();
extern FILE *yyin;

int main() {
	FILE *myfile = fopen("input.txt", "r");
	if (!myfile) {
		printf("I can't open a.snazzle.file!");
		return -1;
	}
	// set lex to read from it instead of defaulting to STDIN:
	yyin = myfile;
	
	// parse through the input until there is no more:
	do {
		yyparse();
	} while (!feof(yyin));
	
}

void yyerror(char *s) {
	printf("Parsing error.  Message: %s ",s);
	exit(-1);
}

char* myatoi(int x){
	char* arr = new char[5];
	string sp="";
	sp+=to_string(x);
	arr[0]=0;
	strcat(arr,sp.c_str());
	return arr;
}

void replace(char* og,char* oldS,char* newS){
	char* pos = strstr(og,oldS);
	int l =strlen(newS);
	while(pos){
		strncpy (pos,newS,l);
		strncpy (pos+strlen(newS),"    ",max(4-l,0));
		pos = strstr(og,oldS);
	}
}
exprType* operate(exprType* e1,exprType* e2,char oprt)
{
	exprType* tmp;
	tmp = new exprType();
	tmp->place=newVar();
	char* sl;
	sl=concat(tmp->place,e1->place,'=');
	sl=concat(sl,e2->place,oprt);
	char *tp = concat(e1->code,e2->code,'\n');
	tp = concat(tp,sl,'\n');
	tmp->code=tp;
	return tmp; 	
}
exprType* assignOperate(char* e1,exprType* e2,char oprt){
	exprType* tmp;
	tmp = new exprType();
	tmp->place=newVar();
	char* tp =concat(tmp->place,e1,'=');
	tp=concat(tp,e2->place,oprt);
	strcat(tp,"\n");
	char* stp;
	// stp=concat($3->code,$1,'\n');
	stp=concat(e2->code,tp,'\n');
	s=concat(e1,tmp->place,'=');
	strcat(stp,s);
	tmp->code=stp;
	return tmp;
}
