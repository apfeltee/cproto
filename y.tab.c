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
#line 68 "./grammar.y" /* yacc.c:339  */


#include <symbol.h>
#include <semantic.h>

#define YYMAXDEPTH 150

extern int yylex(void);

/* declaration specifier attributes for the typedef statement currently being
 * scanned
 */
static int cur_decl_spec_flags;

/* pointer to parameter list for the current function definition */
static ParameterList *func_params;

/* A parser semantic action sets this pointer to the current declarator in
 * a function parameter declaration in order to catch any comments following
 * the parameter declaration on the same line.  If the lexer scans a comment
 * and <cur_declarator> is not NULL, then the comment is attached to the
 * declarator.  To ignore subsequent comments, the lexer sets this to NULL
 * after scanning a comment or end of line.
 */
static Declarator *cur_declarator;

/* temporary string buffer */
static char *temp_buf = 0;
static size_t temp_len = 0;

/* table of typedef names */
static SymbolTable *typedef_names;

/* table of define names */
static SymbolTable *define_names;

/* table of type qualifiers */
static SymbolTable *type_qualifiers;

/* information about the current input file */
typedef struct {
    char *base_name;		/* base input file name */
    char *file_name;		/* current file name */
    size_t len_file_name;	/* ...its allocated size */
    FILE *file;			/* input file */
    unsigned line_num;		/* current line number in input file */
    FILE *tmp_file;		/* temporary file */
    long begin_comment;		/* tmp file offset after last written ) or ; */
    long end_comment;		/* tmp file offset after last comment */
    boolean convert;		/* if TRUE, convert function definitions */
    boolean changed;		/* TRUE if conversion done in this file */
} IncludeStack;

static IncludeStack *cur_file;	/* current input file */

#include "yyerror.c"

static int haveAnsiParam(void);

/* Flags to enable us to find if a procedure returns a value.
 */
static int return_val,		/* nonzero on BRACES iff return-expression found */
  returned_at;			/* marker for token-number to set 'return_val' */

#if OPT_LINTLIBRARY
static const char *
dft_decl_spec(void)
{
    return (lintLibrary() && !return_val) ? "void" : "int";
}

#else
#define dft_decl_spec() "int"
#endif

static int
haveAnsiParam(void)
{
    Parameter *p;
    if (func_params != 0) {
	for (p = func_params->first; p != 0; p = p->next) {
	    if (p->declarator->func_def == FUNC_ANSI) {
		return TRUE;
	    }
	}
    }
    return FALSE;
}

static void
need_temp(size_t need)
{
    if (need > temp_len) {
	if (need < MAX_TEXT_SIZE)
	    need = MAX_TEXT_SIZE;
	if (need < temp_len * 2)
	    need = temp_len * 2;
	temp_buf = type_realloc(char, temp_buf, need);
	temp_len = need;
    }
}


#line 170 "y.tab.c" /* yacc.c:339  */

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
    T_IDENTIFIER = 258,
    T_TYPEDEF_NAME = 259,
    T_DEFINE_NAME = 260,
    T_AUTO = 261,
    T_EXTERN = 262,
    T_REGISTER = 263,
    T_STATIC = 264,
    T_TYPEDEF = 265,
    T_INLINE = 266,
    T_EXTENSION = 267,
    T_CHAR = 268,
    T_DOUBLE = 269,
    T_FLOAT = 270,
    T_INT = 271,
    T_VOID = 272,
    T_LONG = 273,
    T_SHORT = 274,
    T_SIGNED = 275,
    T_UNSIGNED = 276,
    T_ENUM = 277,
    T_STRUCT = 278,
    T_UNION = 279,
    T_Bool = 280,
    T_Complex = 281,
    T_Imaginary = 282,
    T_TYPE_QUALIFIER = 283,
    T_BRACKETS = 284,
    T_LBRACE = 285,
    T_MATCHRBRACE = 286,
    T_ELLIPSIS = 287,
    T_INITIALIZER = 288,
    T_STRING_LITERAL = 289,
    T_ASM = 290,
    T_ASMARG = 291,
    T_VA_DCL = 292
  };
#endif
/* Tokens.  */
#define T_IDENTIFIER 258
#define T_TYPEDEF_NAME 259
#define T_DEFINE_NAME 260
#define T_AUTO 261
#define T_EXTERN 262
#define T_REGISTER 263
#define T_STATIC 264
#define T_TYPEDEF 265
#define T_INLINE 266
#define T_EXTENSION 267
#define T_CHAR 268
#define T_DOUBLE 269
#define T_FLOAT 270
#define T_INT 271
#define T_VOID 272
#define T_LONG 273
#define T_SHORT 274
#define T_SIGNED 275
#define T_UNSIGNED 276
#define T_ENUM 277
#define T_STRUCT 278
#define T_UNION 279
#define T_Bool 280
#define T_Complex 281
#define T_Imaginary 282
#define T_TYPE_QUALIFIER 283
#define T_BRACKETS 284
#define T_LBRACE 285
#define T_MATCHRBRACE 286
#define T_ELLIPSIS 287
#define T_INITIALIZER 288
#define T_STRING_LITERAL 289
#define T_ASM 290
#define T_ASMARG 291
#define T_VA_DCL 292

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 287 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  67
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   527

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  117
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  155

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     5,     2,
       3,    44,     4,     2,    42,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    41,
       2,    43,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   173,   173,   175,   179,   180,   184,   185,   186,   187,
     188,   189,   193,   200,   204,   211,   218,   229,   244,   243,
     255,   259,   265,   267,   271,   283,   296,   307,   295,   332,
     331,   359,   361,   362,   366,   367,   371,   372,   381,   382,
     383,   387,   391,   395,   399,   403,   407,   414,   418,   422,
     426,   430,   434,   438,   442,   446,   450,   454,   458,   462,
     469,   470,   474,   478,   491,   500,   509,   518,   522,   529,
     533,   540,   550,   549,   561,   562,   569,   578,   587,   596,
     604,   605,   609,   621,   625,   629,   640,   650,   658,   669,
     675,   687,   691,   695,   702,   714,   715,   722,   726,   733,
     738,   743,   752,   755,   759,   764,   771,   775,   789,   793,
     804,   808,   819,   829,   833,   841,   848,   859
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'('", "'*'", "'&'", "T_IDENTIFIER",
  "T_TYPEDEF_NAME", "T_DEFINE_NAME", "T_AUTO", "T_EXTERN", "T_REGISTER",
  "T_STATIC", "T_TYPEDEF", "T_INLINE", "T_EXTENSION", "T_CHAR", "T_DOUBLE",
  "T_FLOAT", "T_INT", "T_VOID", "T_LONG", "T_SHORT", "T_SIGNED",
  "T_UNSIGNED", "T_ENUM", "T_STRUCT", "T_UNION", "T_Bool", "T_Complex",
  "T_Imaginary", "T_TYPE_QUALIFIER", "T_BRACKETS", "T_LBRACE",
  "T_MATCHRBRACE", "T_ELLIPSIS", "T_INITIALIZER", "T_STRING_LITERAL",
  "T_ASM", "T_ASMARG", "T_VA_DCL", "';'", "','", "'='", "')'", "$accept",
  "program", "translation_unit", "external_declaration", "braces",
  "linkage_specification", "declaration", "$@1", "any_typedef",
  "opt_declarator_list", "declarator_list", "function_definition", "$@2",
  "$@3", "$@4", "opt_declaration_list", "declaration_list",
  "decl_specifiers", "decl_specifier", "storage_class", "type_specifier",
  "type_qualifier", "struct_or_union_specifier", "struct_or_union",
  "init_declarator_list", "init_declarator", "$@5", "asm_specifier",
  "enum_specifier", "enumeration", "any_id", "declarator",
  "direct_declarator", "pointer", "opt_type_qualifiers",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "opt_identifier_list", "identifier_list",
  "identifier_or_ref", "abs_declarator", "direct_abs_declarator", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,    40,    42,    38,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,    59,    44,    61,    41
};
# endif

#define YYPACT_NINF -79

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-79)))

#define YYTABLE_NINF -100

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     140,    18,    51,    13,    60,   -79,    -8,   -79,   -79,   -27,
     -79,   -79,   -79,   -79,    -1,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -25,   -79,    22,   179,   -79,   -79,   -79,   496,   -79,
     249,   -79,   -79,   -79,   -79,   -79,    20,   -79,   -79,    20,
     -79,   -79,    16,    76,   -20,   -79,   -79,   -79,   -79,   -16,
     -79,    27,    13,   -79,   418,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   496,   218,   -79,   -79,   -79,    43,   -79,    35,
      10,   -79,    17,     0,   -79,    29,   -79,    29,   354,   446,
     -79,    16,    21,   -79,   -79,   -79,   -79,   -79,   288,    51,
     -79,   392,    26,    30,   -79,    36,   -79,    51,   -79,   354,
      17,   316,   -79,   -79,   -79,   -79,   -79,   -79,    31,   471,
     -79,    44,    45,    32,   -79,    47,    46,    50,   -79,   -79,
     -79,   100,   -79,   -79,    57,    61,   -79,    54,    66,   -79,
     -79,   -79,    60,   -79,    51,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,    67,   -79
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    91,     0,    80,    59,    63,    41,    42,
      43,    44,    21,    45,    46,    47,    48,    49,    50,    55,
      51,    52,    53,    54,    79,    67,    68,    56,    57,    58,
      62,     0,     8,     0,     0,     4,     9,     6,     0,     7,
     101,    36,    38,    39,    40,    60,     0,    10,    61,     0,
     106,    29,    83,     0,     0,    84,    11,    12,    81,     0,
      93,    89,    92,   107,     0,    20,    74,     1,     5,    59,
      42,    46,    18,     0,   113,    16,    37,     0,    69,    26,
     108,   100,   110,     0,    65,    66,    77,    78,    31,   102,
      86,    82,     0,    85,    90,    94,    14,    15,     0,    22,
     117,   101,     0,    95,    97,     0,    17,     0,    72,    31,
     109,     0,   112,    13,    64,    76,    32,    34,     0,    33,
     104,     0,     0,   103,    75,    71,     0,    23,    24,    99,
     116,     0,   111,    70,     0,     0,   115,     0,     0,    35,
      87,    88,     0,    19,     0,    96,    98,    73,    27,   114,
      30,   105,    25,     0,    28
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -79,   -79,   -79,    68,   -40,   -79,   -58,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -14,   -79,     2,   -33,   -79,
     -79,     1,   -79,   -79,   -79,    -4,   -79,   -79,   -79,   -79,
      -3,    -2,   -30,   -32,   -79,   -79,   -78,   -79,     3,   -79,
     -79,   -79,    33,    24
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    33,    34,    35,    84,    36,    37,    99,    38,   126,
     127,    39,   109,   153,    88,   118,   119,    98,    41,    42,
      43,    44,    45,    46,    77,    78,   134,    47,    48,    49,
      50,    51,    52,    53,    61,    62,   102,   103,   104,   122,
     123,    55,    81,    82
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      59,    63,    40,    54,    60,   -81,    97,    76,    80,    86,
      64,   121,    65,    73,    66,     4,     5,    58,    92,    89,
     111,     7,    67,    91,    96,   -81,     5,    58,    93,    94,
     117,     3,   -81,   137,   113,   -81,    40,    54,    79,    76,
      72,    80,    74,    85,    30,   114,    87,   115,    90,   112,
      91,   117,    56,    83,     2,     3,     4,     5,    58,    57,
     124,   139,    83,    95,   138,    76,     5,    58,    76,    80,
     130,    59,   131,   -99,   142,   101,   -71,   -71,   108,     2,
     132,     4,     5,    58,   106,   107,   120,   143,   140,   141,
     108,   101,   144,   147,   148,   135,   125,   128,   149,   129,
     150,   154,    68,   133,   110,   125,   105,    69,     7,     8,
      70,    10,    11,   101,    13,    71,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,     0,   101,   146,   145,     0,     0,     0,   151,
      -2,     1,   152,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,     0,     0,     0,     0,     0,     0,    31,    -3,
       1,    32,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,     0,     0,     0,     0,     0,     0,    31,     0,     0,
      32,    73,     3,     4,     5,     6,     7,     8,    70,    10,
      11,     0,    13,    71,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      74,     0,    73,     3,     4,     5,     6,     7,     8,    70,
      10,    11,   100,    13,    71,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    74,     0,     0,     0,     0,     0,     0,     0,     0,
      75,     2,     3,     4,     5,     6,     7,     8,    70,    10,
      11,     0,    13,    71,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
       0,     0,     0,    69,     7,     8,    70,    10,    11,    75,
      13,    71,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     136,    69,     7,     8,    70,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,     0,     0,     0,     0,
       0,     0,     0,     0,   116,    73,     3,     4,     5,     6,
       7,     8,    70,    10,    11,     0,    13,    71,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    74,    69,     7,     8,    70,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
       0,    83,     5,     6,     7,     8,    70,    10,    11,     0,
      13,    71,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    69,     7,
       8,    70,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    69,     7,     8,    70,    10,    11,     0,
      13,    71,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30
};

static const yytype_int16 yycheck[] =
{
       2,     4,     0,     0,     3,    13,    64,    40,    40,    49,
      37,    89,    13,     3,    39,     5,     6,     7,    38,     3,
       3,     8,     0,    53,    64,    33,     6,     7,    44,    61,
      88,     4,    40,   111,    34,    43,    34,    34,    40,    72,
      38,    73,    32,    46,    31,    85,    49,    87,    32,    32,
      80,   109,    34,    33,     3,     4,     5,     6,     7,    41,
      39,   119,    33,    62,    33,    98,     6,     7,   101,   101,
      44,    73,    42,    38,    42,    73,    41,    42,    43,     3,
      44,     5,     6,     7,    41,    42,    89,    41,    44,    44,
      43,    89,    42,    36,    33,   109,    98,    99,    44,   101,
      34,    34,    34,   107,    80,   107,    73,     7,     8,     9,
      10,    11,    12,   111,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    -1,   131,   131,    35,    -1,    -1,    -1,   142,
       0,     1,   144,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,     0,
       1,    41,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      41,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    44,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      41,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      -1,    -1,    -1,     7,     8,     9,    10,    11,    12,    41,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      -1,    33,     6,     7,     8,     9,    10,    11,    12,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,     7,     8,     9,    10,    11,    12,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    38,    41,    46,    47,    48,    50,    51,    53,    56,
      62,    63,    64,    65,    66,    67,    68,    72,    73,    74,
      75,    76,    77,    78,    83,    86,    34,    41,     7,    76,
      66,    79,    80,    75,    37,    13,    39,     0,    48,     7,
      10,    15,    62,     3,    32,    41,    63,    69,    70,    76,
      78,    87,    88,    33,    49,    75,    49,    75,    59,     3,
      32,    77,    38,    44,    78,    66,    49,    51,    62,    52,
      44,    62,    81,    82,    83,    87,    41,    42,    43,    57,
      88,     3,    32,    34,    49,    49,    40,    51,    60,    61,
      75,    81,    84,    85,    39,    76,    54,    55,    76,    76,
      44,    42,    44,    70,    71,    60,    44,    81,    33,    51,
      44,    44,    42,    41,    42,    35,    83,    36,    33,    44,
      34,    75,    76,    58,    34
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    46,    47,    47,    48,    48,    48,    48,
      48,    48,    48,    49,    50,    50,    51,    51,    52,    51,
      53,    53,    54,    54,    55,    55,    57,    58,    56,    59,
      56,    60,    60,    60,    61,    61,    62,    62,    63,    63,
      63,    64,    64,    64,    64,    64,    64,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    66,    66,    67,    67,    67,    68,    68,    69,
      69,    70,    71,    70,    72,    72,    73,    73,    73,    74,
      75,    75,    76,    76,    77,    77,    77,    77,    77,    78,
      78,    79,    79,    80,    80,    81,    81,    82,    82,    83,
      83,    83,    84,    84,    85,    85,    86,    86,    87,    87,
      87,    88,    88,    88,    88,    88,    88,    88
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     1,     1,     1,     1,
       1,     2,     2,     2,     3,     3,     2,     3,     0,     5,
       2,     1,     0,     1,     1,     3,     0,     0,     7,     0,
       5,     0,     1,     1,     1,     2,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     2,     2,     1,     1,     1,
       3,     1,     0,     4,     2,     3,     3,     2,     2,     1,
       1,     1,     2,     1,     1,     3,     2,     4,     4,     2,
       3,     0,     1,     1,     2,     1,     3,     1,     3,     2,
       2,     1,     0,     1,     1,     3,     1,     2,     1,     2,
       1,     3,     2,     1,     4,     3,     3,     2
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
        case 11:
#line 190 "./grammar.y" /* yacc.c:1646  */
    {
	    yyerrok;
	}
#line 1570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 194 "./grammar.y" /* yacc.c:1646  */
    {
	    yyerrok;
	}
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 205 "./grammar.y" /* yacc.c:1646  */
    {
	    /* Provide an empty action here so bison will not complain about
	     * incompatible types in the default action it normally would
	     * have generated.
	     */
	}
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 212 "./grammar.y" /* yacc.c:1646  */
    {
	    /* empty */
	}
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 219 "./grammar.y" /* yacc.c:1646  */
    {
#if OPT_LINTLIBRARY
	    if (types_out && want_typedef()) {
		gen_declarations(&(yyvsp[-1].decl_spec), (DeclaratorList *)0);
		flush_varargs();
	    }
#endif
	    free_decl_spec(&(yyvsp[-1].decl_spec));
	    end_typedef();
	}
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 230 "./grammar.y" /* yacc.c:1646  */
    {
	    if (func_params != NULL) {
		set_param_types(func_params, &(yyvsp[-2].decl_spec), &(yyvsp[-1].decl_list));
	    } else {
		gen_declarations(&(yyvsp[-2].decl_spec), &(yyvsp[-1].decl_list));
#if OPT_LINTLIBRARY
		flush_varargs();
#endif
		free_decl_list(&(yyvsp[-1].decl_list));
	    }
	    free_decl_spec(&(yyvsp[-2].decl_spec));
	    end_typedef();
	}
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 244 "./grammar.y" /* yacc.c:1646  */
    {
	    cur_decl_spec_flags = (yyvsp[0].decl_spec).flags;
	    free_decl_spec(&(yyvsp[0].decl_spec));
	}
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 249 "./grammar.y" /* yacc.c:1646  */
    {
	    end_typedef();
	}
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 256 "./grammar.y" /* yacc.c:1646  */
    {
	    begin_typedef();
	}
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 260 "./grammar.y" /* yacc.c:1646  */
    {
	    begin_typedef();
	}
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 272 "./grammar.y" /* yacc.c:1646  */
    {
	    int flags = cur_decl_spec_flags;

	    /* If the typedef is a pointer type, then reset the short type
	     * flags so it does not get promoted.
	     */
	    if (strcmp((yyvsp[0].declarator)->text, (yyvsp[0].declarator)->name) != 0)
		flags &= ~(DS_CHAR | DS_SHORT | DS_FLOAT);
	    new_symbol(typedef_names, (yyvsp[0].declarator)->name, NULL, flags);
	    free_declarator((yyvsp[0].declarator));
	}
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 284 "./grammar.y" /* yacc.c:1646  */
    {
	    int flags = cur_decl_spec_flags;

	    if (strcmp((yyvsp[0].declarator)->text, (yyvsp[0].declarator)->name) != 0)
		flags &= ~(DS_CHAR | DS_SHORT | DS_FLOAT);
	    new_symbol(typedef_names, (yyvsp[0].declarator)->name, NULL, flags);
	    free_declarator((yyvsp[0].declarator));
	}
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 296 "./grammar.y" /* yacc.c:1646  */
    {
	    check_untagged(&(yyvsp[-1].decl_spec));
	    if ((yyvsp[0].declarator)->func_def == FUNC_NONE) {
		yyerror("syntax error");
		YYERROR;
	    }
	    func_params = &((yyvsp[0].declarator)->head->params);
	    func_params->begin_comment = cur_file->begin_comment;
	    func_params->end_comment = cur_file->end_comment;
	}
#line 1707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 307 "./grammar.y" /* yacc.c:1646  */
    {
	    /* If we're converting to K&R and we've got a nominally K&R
	     * function which has a parameter which is ANSI (i.e., a prototyped
	     * function pointer), then we must override the deciphered value of
	     * 'func_def' so that the parameter will be converted.
	     */
	    if (func_style == FUNC_TRADITIONAL
	     && haveAnsiParam()
	     && (yyvsp[-3].declarator)->head->func_def == func_style) {
		(yyvsp[-3].declarator)->head->func_def = FUNC_BOTH;
	    }

	    func_params = NULL;

	    if (cur_file->convert)
		gen_func_definition(&(yyvsp[-4].decl_spec), (yyvsp[-3].declarator));
	    gen_prototype(&(yyvsp[-4].decl_spec), (yyvsp[-3].declarator));
#if OPT_LINTLIBRARY
	    flush_varargs();
#endif
	    free_decl_spec(&(yyvsp[-4].decl_spec));
	    free_declarator((yyvsp[-3].declarator));
	}
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 332 "./grammar.y" /* yacc.c:1646  */
    {
	    if ((yyvsp[0].declarator)->func_def == FUNC_NONE) {
		yyerror("syntax error");
		YYERROR;
	    }
	    func_params = &((yyvsp[0].declarator)->head->params);
	    func_params->begin_comment = cur_file->begin_comment;
	    func_params->end_comment = cur_file->end_comment;
	}
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 342 "./grammar.y" /* yacc.c:1646  */
    {
	    DeclSpec decl_spec;

	    func_params = NULL;

	    new_decl_spec(&decl_spec, dft_decl_spec(), (yyvsp[-4].declarator)->begin, DS_NONE);
	    if (cur_file->convert)
		gen_func_definition(&decl_spec, (yyvsp[-4].declarator));
	    gen_prototype(&decl_spec, (yyvsp[-4].declarator));
#if OPT_LINTLIBRARY
	    flush_varargs();
#endif
	    free_decl_spec(&decl_spec);
	    free_declarator((yyvsp[-4].declarator));
	}
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 373 "./grammar.y" /* yacc.c:1646  */
    {
	    join_decl_specs(&(yyval.decl_spec), &(yyvsp[-1].decl_spec), &(yyvsp[0].decl_spec));
	    free_decl_spec(&(yyvsp[-1].decl_spec));
	    free_decl_spec(&(yyvsp[0].decl_spec));
	}
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 388 "./grammar.y" /* yacc.c:1646  */
    {
	    new_decl_spec(&(yyval.decl_spec), (yyvsp[0].text).text, (yyvsp[0].text).begin, DS_NONE);
	}
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 392 "./grammar.y" /* yacc.c:1646  */
    {
	    new_decl_spec(&(yyval.decl_spec), (yyvsp[0].text).text, (yyvsp[0].text).begin, DS_EXTERN);
	}
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 396 "./grammar.y" /* yacc.c:1646  */
    {
	    new_decl_spec(&(yyval.decl_spec), (yyvsp[0].text).text, (yyvsp[0].text).begin, DS_NONE);
	}
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 400 "./grammar.y" /* yacc.c:1646  */
    {
	    new_decl_spec(&(yyval.decl_spec), (yyvsp[0].text).text, (yyvsp[0].text).begin, DS_STATIC);
	}
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 404 "./grammar.y" /* yacc.c:1646  */
    {
	    new_decl_spec(&(yyval.decl_spec), (yyvsp[0].text).text, (yyvsp[0].text).begin, DS_INLINE);
	}
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 408 "./grammar.y" /* yacc.c:1646  */
    {
	    new_decl_spec(&(yyval.decl_spec), (yyvsp[0].text).text, (yyvsp[0].text).begin, DS_JUNK);
	}
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 415 "./grammar.y" /* yacc.c:1646  */
    {
	    new_decl_spec(&(yyval.decl_spec), (yyvsp[0].text).text, (yyvsp[0].text).begin, DS_CHAR);
	}
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 419 "./grammar.y" /* yacc.c:1646  */
    {
	    new_decl_spec(&(yyval.decl_spec), (yyvsp[0].text).text, (yyvsp[0].text).begin, DS_NONE);
	}
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 423 "./grammar.y" /* yacc.c:1646  */
    {
	    new_decl_spec(&(yyval.decl_spec), (yyvsp[0].text).text, (yyvsp[0].text).begin, DS_FLOAT);
	}
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 427 "./grammar.y" /* yacc.c:1646  */
    {
	    new_decl_spec(&(yyval.decl_spec), (yyvsp[0].text).text, (yyvsp[0].text).begin, DS_NONE);
	}
#line 1859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 431 "./grammar.y" /* yacc.c:1646  */
    {
	    new_decl_spec(&(yyval.decl_spec), (yyvsp[0].text).text, (yyvsp[0].text).begin, DS_NONE);
	}
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 435 "./grammar.y" /* yacc.c:1646  */
    {
	    new_decl_spec(&(yyval.decl_spec), (yyvsp[0].text).text, (yyvsp[0].text).begin, DS_SHORT);
	}
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 439 "./grammar.y" /* yacc.c:1646  */
    {
	    new_decl_spec(&(yyval.decl_spec), (yyvsp[0].text).text, (yyvsp[0].text).begin, DS_NONE);
	}
#line 1883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 443 "./grammar.y" /* yacc.c:1646  */
    {
	    new_decl_spec(&(yyval.decl_spec), (yyvsp[0].text).text, (yyvsp[0].text).begin, DS_NONE);
	}
#line 1891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 447 "./grammar.y" /* yacc.c:1646  */
    {
	    new_decl_spec(&(yyval.decl_spec), (yyvsp[0].text).text, (yyvsp[0].text).begin, DS_NONE);
	}
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 451 "./grammar.y" /* yacc.c:1646  */
    {
	    new_decl_spec(&(yyval.decl_spec), (yyvsp[0].text).text, (yyvsp[0].text).begin, DS_CHAR);
	}
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 455 "./grammar.y" /* yacc.c:1646  */
    {
	    new_decl_spec(&(yyval.decl_spec), (yyvsp[0].text).text, (yyvsp[0].text).begin, DS_NONE);
	}
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 459 "./grammar.y" /* yacc.c:1646  */
    {
	    new_decl_spec(&(yyval.decl_spec), (yyvsp[0].text).text, (yyvsp[0].text).begin, DS_NONE);
	}
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 463 "./grammar.y" /* yacc.c:1646  */
    {
	    Symbol *s;
	    s = find_symbol(typedef_names, (yyvsp[0].text).text);
	    if (s != NULL)
		new_decl_spec(&(yyval.decl_spec), (yyvsp[0].text).text, (yyvsp[0].text).begin, s->flags);
	}
#line 1934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 475 "./grammar.y" /* yacc.c:1646  */
    {
	    new_decl_spec(&(yyval.decl_spec), (yyvsp[0].text).text, (yyvsp[0].text).begin, DS_NONE);
	}
#line 1942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 479 "./grammar.y" /* yacc.c:1646  */
    {
	    /* This rule allows the <pointer> nonterminal to scan #define
	     * names as if they were type modifiers.
	     */
	    Symbol *s;
	    s = find_symbol(define_names, (yyvsp[0].text).text);
	    if (s != NULL)
		new_decl_spec(&(yyval.decl_spec), (yyvsp[0].text).text, (yyvsp[0].text).begin, s->flags);
	}
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 492 "./grammar.y" /* yacc.c:1646  */
    {
	    char *s;
	    if ((s = implied_typedef()) == 0) {
		need_temp(2 + strlen((yyvsp[-2].text).text) + strlen((yyvsp[-1].text).text));
	        (void)sprintf(s = temp_buf, "%s %s", (yyvsp[-2].text).text, (yyvsp[-1].text).text);
	    }
	    new_decl_spec(&(yyval.decl_spec), s, (yyvsp[-2].text).begin, DS_NONE);
	}
#line 1969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 501 "./grammar.y" /* yacc.c:1646  */
    {
	    char *s;
	    if ((s = implied_typedef()) == 0) {
		need_temp(4 + strlen((yyvsp[-1].text).text));
		(void)sprintf(s = temp_buf, "%s {}", (yyvsp[-1].text).text);
	    }
	    new_decl_spec(&(yyval.decl_spec), s, (yyvsp[-1].text).begin, DS_NONE);
	}
#line 1982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 510 "./grammar.y" /* yacc.c:1646  */
    {
	    need_temp(2 + strlen((yyvsp[-1].text).text) + strlen((yyvsp[0].text).text));
	    (void)sprintf(temp_buf, "%s %s", (yyvsp[-1].text).text, (yyvsp[0].text).text);
	    new_decl_spec(&(yyval.decl_spec), temp_buf, (yyvsp[-1].text).begin, DS_NONE);
	}
#line 1992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 519 "./grammar.y" /* yacc.c:1646  */
    {
	    imply_typedef((yyval.text).text);
	}
#line 2000 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 523 "./grammar.y" /* yacc.c:1646  */
    {
	    imply_typedef((yyval.text).text);
	}
#line 2008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 530 "./grammar.y" /* yacc.c:1646  */
    {
	    new_decl_list(&(yyval.decl_list), (yyvsp[0].declarator));
	}
#line 2016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 534 "./grammar.y" /* yacc.c:1646  */
    {
	    add_decl_list(&(yyval.decl_list), &(yyvsp[-2].decl_list), (yyvsp[0].declarator));
	}
#line 2024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 541 "./grammar.y" /* yacc.c:1646  */
    {
	    if ((yyvsp[0].declarator)->func_def != FUNC_NONE && func_params == NULL &&
		func_style == FUNC_TRADITIONAL && cur_file->convert) {
		gen_func_declarator((yyvsp[0].declarator));
		fputs(cur_text(), cur_file->tmp_file);
	    }
	    cur_declarator = (yyval.declarator);
	}
#line 2037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 550 "./grammar.y" /* yacc.c:1646  */
    {
	    if ((yyvsp[-1].declarator)->func_def != FUNC_NONE && func_params == NULL &&
		func_style == FUNC_TRADITIONAL && cur_file->convert) {
		gen_func_declarator((yyvsp[-1].declarator));
		fputs(" =", cur_file->tmp_file);
	    }
	}
#line 2049 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 563 "./grammar.y" /* yacc.c:1646  */
    {
	    free_parameter((yyvsp[-2].parameter));
	}
#line 2057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 570 "./grammar.y" /* yacc.c:1646  */
    {
	    char *s;
	    if ((s = implied_typedef()) == 0) {
		need_temp(6 + strlen((yyvsp[-1].text).text));
		(void)sprintf(s = temp_buf, "enum %s", (yyvsp[-1].text).text);
	    }
	    new_decl_spec(&(yyval.decl_spec), s, (yyvsp[-2].text).begin, DS_NONE);
	}
#line 2070 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 579 "./grammar.y" /* yacc.c:1646  */
    {
	    char *s;
	    if ((s = implied_typedef()) == 0) {
		need_temp(4 + strlen((yyvsp[-1].text).text));
		(void)sprintf(s = temp_buf, "%s {}", (yyvsp[-1].text).text);
	    }
	    new_decl_spec(&(yyval.decl_spec), s, (yyvsp[-1].text).begin, DS_NONE);
	}
#line 2083 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 588 "./grammar.y" /* yacc.c:1646  */
    {
	    need_temp(6 + strlen((yyvsp[0].text).text));
	    (void)sprintf(temp_buf, "enum %s", (yyvsp[0].text).text);
	    new_decl_spec(&(yyval.decl_spec), temp_buf, (yyvsp[-1].text).begin, DS_NONE);
	}
#line 2093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 597 "./grammar.y" /* yacc.c:1646  */
    {
	    imply_typedef("enum");
	    (yyval.text) = (yyvsp[0].text);
	}
#line 2102 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 610 "./grammar.y" /* yacc.c:1646  */
    {
	    (yyval.declarator) = (yyvsp[0].declarator);

	    need_temp(1 + strlen((yyvsp[-1].text).text) + strlen((yyvsp[0].declarator)->text));
	    (void)sprintf(temp_buf, "%s%s", (yyvsp[-1].text).text, (yyval.declarator)->text);

	    free((yyval.declarator)->text);
	    (yyval.declarator)->text = xstrdup(temp_buf);
	    (yyval.declarator)->begin = (yyvsp[-1].text).begin;
	    (yyval.declarator)->pointer = TRUE;
	}
#line 2118 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 626 "./grammar.y" /* yacc.c:1646  */
    {
	    (yyval.declarator) = new_declarator((yyvsp[0].text).text, (yyvsp[0].text).text, (yyvsp[0].text).begin);
	}
#line 2126 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 630 "./grammar.y" /* yacc.c:1646  */
    {
	    (yyval.declarator) = (yyvsp[-1].declarator);

	    need_temp(2 + strlen((yyvsp[-1].declarator)->text));
	    (void)sprintf(temp_buf, "(%s)", (yyval.declarator)->text);

	    free((yyval.declarator)->text);
	    (yyval.declarator)->text = xstrdup(temp_buf);
	    (yyval.declarator)->begin = (yyvsp[-2].text).begin;
	}
#line 2141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 641 "./grammar.y" /* yacc.c:1646  */
    {
	    (yyval.declarator) = (yyvsp[-1].declarator);

	    need_temp(1 + strlen((yyvsp[-1].declarator)->text) + strlen((yyvsp[0].text).text));
	    (void)sprintf(temp_buf, "%s%s", (yyval.declarator)->text, (yyvsp[0].text).text);

	    free((yyval.declarator)->text);
	    (yyval.declarator)->text = xstrdup(temp_buf);
	}
#line 2155 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 651 "./grammar.y" /* yacc.c:1646  */
    {
	    (yyval.declarator) = new_declarator("%s()", (yyvsp[-3].declarator)->name, (yyvsp[-3].declarator)->begin);
	    (yyval.declarator)->params = (yyvsp[-1].param_list);
	    (yyval.declarator)->func_stack = (yyvsp[-3].declarator);
	    (yyval.declarator)->head = ((yyvsp[-3].declarator)->func_stack == NULL) ? (yyval.declarator) : (yyvsp[-3].declarator)->head;
	    (yyval.declarator)->func_def = FUNC_ANSI;
	}
#line 2167 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 659 "./grammar.y" /* yacc.c:1646  */
    {
	    (yyval.declarator) = new_declarator("%s()", (yyvsp[-3].declarator)->name, (yyvsp[-3].declarator)->begin);
	    (yyval.declarator)->params = (yyvsp[-1].param_list);
	    (yyval.declarator)->func_stack = (yyvsp[-3].declarator);
	    (yyval.declarator)->head = ((yyvsp[-3].declarator)->func_stack == NULL) ? (yyval.declarator) : (yyvsp[-3].declarator)->head;
	    (yyval.declarator)->func_def = FUNC_TRADITIONAL;
	}
#line 2179 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 670 "./grammar.y" /* yacc.c:1646  */
    {
	    need_temp(2 + strlen((yyvsp[0].text).text));
	    (void)sprintf((yyval.text).text, "*%.*s", MAX_TEXT_SIZE - 2, (yyvsp[0].text).text);
	    (yyval.text).begin = (yyvsp[-1].text).begin;
	}
#line 2189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 676 "./grammar.y" /* yacc.c:1646  */
    {
	    need_temp(2 + strlen((yyvsp[-1].text).text) + strlen((yyvsp[0].text).text));
	    (void)sprintf((yyval.text).text, "*%.*s%.*s",
			  (MAX_TEXT_SIZE / 2) - 2, (yyvsp[-1].text).text,
			  (MAX_TEXT_SIZE / 2) - 2, (yyvsp[0].text).text);
	    (yyval.text).begin = (yyvsp[-2].text).begin;
	}
#line 2201 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 687 "./grammar.y" /* yacc.c:1646  */
    {
	    strcpy((yyval.text).text, "");
	    (yyval.text).begin = 0L;
	}
#line 2210 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 696 "./grammar.y" /* yacc.c:1646  */
    {
	    need_temp(2 + strlen((yyvsp[0].decl_spec).text));
	    (void)sprintf((yyval.text).text, "%s ", (yyvsp[0].decl_spec).text);
	    (yyval.text).begin = (yyvsp[0].decl_spec).begin;
	    free((yyvsp[0].decl_spec).text);
	}
#line 2221 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 703 "./grammar.y" /* yacc.c:1646  */
    {
	    need_temp(1 + strlen((yyvsp[-1].text).text) + strlen((yyvsp[0].decl_spec).text));
	    (void)sprintf((yyval.text).text, "%.*s%.*s ",
			  (MAX_TEXT_SIZE / 2) - 2, (yyvsp[-1].text).text,
			  (MAX_TEXT_SIZE / 2) - 2, (yyvsp[0].decl_spec).text);
	    (yyval.text).begin = (yyvsp[-1].text).begin;
	    free((yyvsp[0].decl_spec).text);
	}
#line 2234 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 716 "./grammar.y" /* yacc.c:1646  */
    {
	    add_ident_list(&(yyval.param_list), &(yyvsp[-2].param_list), "...");
	}
#line 2242 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 723 "./grammar.y" /* yacc.c:1646  */
    {
	    new_param_list(&(yyval.param_list), (yyvsp[0].parameter));
	}
#line 2250 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 727 "./grammar.y" /* yacc.c:1646  */
    {
	    add_param_list(&(yyval.param_list), &(yyvsp[-2].param_list), (yyvsp[0].parameter));
	}
#line 2258 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 734 "./grammar.y" /* yacc.c:1646  */
    {
	    check_untagged(&(yyvsp[-1].decl_spec));
	    (yyval.parameter) = new_parameter(&(yyvsp[-1].decl_spec), (yyvsp[0].declarator));
	}
#line 2267 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 739 "./grammar.y" /* yacc.c:1646  */
    {
	    check_untagged(&(yyvsp[-1].decl_spec));
	    (yyval.parameter) = new_parameter(&(yyvsp[-1].decl_spec), (yyvsp[0].declarator));
	}
#line 2276 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 744 "./grammar.y" /* yacc.c:1646  */
    {
	    check_untagged(&(yyvsp[0].decl_spec));
	    (yyval.parameter) = new_parameter(&(yyvsp[0].decl_spec), (Declarator *)0);
	}
#line 2285 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 752 "./grammar.y" /* yacc.c:1646  */
    {
	    new_ident_list(&(yyval.param_list));
	}
#line 2293 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 760 "./grammar.y" /* yacc.c:1646  */
    {
	    new_ident_list(&(yyval.param_list));
	    add_ident_list(&(yyval.param_list), &(yyval.param_list), (yyvsp[0].text).text);
	}
#line 2302 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 765 "./grammar.y" /* yacc.c:1646  */
    {
	    add_ident_list(&(yyval.param_list), &(yyvsp[-2].param_list), (yyvsp[0].text).text);
	}
#line 2310 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 772 "./grammar.y" /* yacc.c:1646  */
    {
	    (yyval.text) = (yyvsp[0].text);
	}
#line 2318 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 776 "./grammar.y" /* yacc.c:1646  */
    {
	    need_temp(2 + strlen((yyvsp[0].text).text));
#if OPT_LINTLIBRARY
	    if (lintLibrary()) { /* Lint doesn't grok C++ ref variables */
		(yyval.text) = (yyvsp[0].text);
	    } else
#endif
		(void)sprintf((yyval.text).text, "&%.*s", MAX_TEXT_SIZE - 2, (yyvsp[0].text).text);
	    (yyval.text).begin = (yyvsp[-1].text).begin;
	}
#line 2333 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 790 "./grammar.y" /* yacc.c:1646  */
    {
	    (yyval.declarator) = new_declarator((yyvsp[0].text).text, "", (yyvsp[0].text).begin);
	}
#line 2341 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 794 "./grammar.y" /* yacc.c:1646  */
    {
	    (yyval.declarator) = (yyvsp[0].declarator);

	    need_temp(1 + strlen((yyvsp[-1].text).text) + strlen((yyvsp[0].declarator)->text));
	    (void)sprintf(temp_buf, "%s%s", (yyvsp[-1].text).text, (yyval.declarator)->text);

	    free((yyval.declarator)->text);
	    (yyval.declarator)->text = xstrdup(temp_buf);
	    (yyval.declarator)->begin = (yyvsp[-1].text).begin;
	}
#line 2356 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 809 "./grammar.y" /* yacc.c:1646  */
    {
	    (yyval.declarator) = (yyvsp[-1].declarator);

	    need_temp(3 + strlen((yyvsp[-1].declarator)->text));
	    (void)sprintf(temp_buf, "(%s)", (yyval.declarator)->text);

	    free((yyval.declarator)->text);
	    (yyval.declarator)->text = xstrdup(temp_buf);
	    (yyval.declarator)->begin = (yyvsp[-2].text).begin;
	}
#line 2371 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 820 "./grammar.y" /* yacc.c:1646  */
    {
	    (yyval.declarator) = (yyvsp[-1].declarator);

	    need_temp(1 + strlen((yyvsp[-1].declarator)->text) + strlen((yyvsp[0].text).text));
	    (void)sprintf(temp_buf, "%s%s", (yyval.declarator)->text, (yyvsp[0].text).text);

	    free((yyval.declarator)->text);
	    (yyval.declarator)->text = xstrdup(temp_buf);
	}
#line 2385 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 830 "./grammar.y" /* yacc.c:1646  */
    {
	    (yyval.declarator) = new_declarator((yyvsp[0].text).text, "", (yyvsp[0].text).begin);
	}
#line 2393 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 834 "./grammar.y" /* yacc.c:1646  */
    {
	    (yyval.declarator) = new_declarator("%s()", "", (yyvsp[-3].declarator)->begin);
	    (yyval.declarator)->params = (yyvsp[-1].param_list);
	    (yyval.declarator)->func_stack = (yyvsp[-3].declarator);
	    (yyval.declarator)->head = ((yyvsp[-3].declarator)->func_stack == NULL) ? (yyval.declarator) : (yyvsp[-3].declarator)->head;
	    (yyval.declarator)->func_def = FUNC_ANSI;
	}
#line 2405 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 842 "./grammar.y" /* yacc.c:1646  */
    {
	    (yyval.declarator) = new_declarator("%s()", "", (yyvsp[-2].declarator)->begin);
	    (yyval.declarator)->func_stack = (yyvsp[-2].declarator);
	    (yyval.declarator)->head = ((yyvsp[-2].declarator)->func_stack == NULL) ? (yyval.declarator) : (yyvsp[-2].declarator)->head;
	    (yyval.declarator)->func_def = FUNC_ANSI;
	}
#line 2416 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 849 "./grammar.y" /* yacc.c:1646  */
    {
	    Declarator *d;

	    d = new_declarator("", "", (yyvsp[-2].text).begin);
	    (yyval.declarator) = new_declarator("%s()", "", (yyvsp[-2].text).begin);
	    (yyval.declarator)->params = (yyvsp[-1].param_list);
	    (yyval.declarator)->func_stack = d;
	    (yyval.declarator)->head = (yyval.declarator);
	    (yyval.declarator)->func_def = FUNC_ANSI;
	}
#line 2431 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 860 "./grammar.y" /* yacc.c:1646  */
    {
	    Declarator *d;

	    d = new_declarator("", "", (yyvsp[-1].text).begin);
	    (yyval.declarator) = new_declarator("%s()", "", (yyvsp[-1].text).begin);
	    (yyval.declarator)->func_stack = d;
	    (yyval.declarator)->head = (yyval.declarator);
	    (yyval.declarator)->func_def = FUNC_ANSI;
	}
#line 2445 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2449 "y.tab.c" /* yacc.c:1646  */
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
#line 871 "./grammar.y" /* yacc.c:1906  */



#if defined(HAVE_CONFIG_H)
# include "lex.yy.c"
#else
#if defined(__EMX__) || defined(MSDOS) || defined(OS2) || defined(WIN32) || defined(vms)
# ifdef USE_flex
#  include "lexyy.c"
# else
#  include "lex_yy.c"
# endif
#else
# include "lex.yy.c"
#endif
#endif

static void
yaccError(const char *msg)
{
    func_params = NULL;
    put_error();		/* tell what line we're on, and what file */
    fprintf(stderr, "%s at token '%s'\n", msg, yytext);
}

/* Initialize the table of type qualifier keywords recognized by the lexical
 * analyzer.
 */
void
init_parser(void)
{
    static const char *keywords[] =
    {
	"const",
	"restrict",
	"volatile",
	"interrupt",
#ifdef vms
	"noshare",
	"readonly",
#endif
#if defined(MSDOS) || defined(OS2)
	"__cdecl",
	"__export",
	"__far",
	"__fastcall",
	"__fortran",
	"__huge",
	"__inline",
	"__interrupt",
	"__loadds",
	"__near",
	"__pascal",
	"__saveregs",
	"__segment",
	"__stdcall",
	"__syscall",
	"_cdecl",
	"_cs",
	"_ds",
	"_es",
	"_export",
	"_far",
	"_fastcall",
	"_fortran",
	"_huge",
	"_interrupt",
	"_loadds",
	"_near",
	"_pascal",
	"_saveregs",
	"_seg",
	"_segment",
	"_ss",
	"cdecl",
	"far",
	"huge",
	"near",
	"pascal",
#ifdef OS2
	"__far16",
#endif
#endif
#ifdef __GNUC__
    /* gcc aliases */
	"__builtin_va_arg",
	"__builtin_va_list",
	"__const",
	"__const__",
	"__gnuc_va_list",
	"__inline",
	"__inline__",
	"__restrict",
	"__restrict__",
	"__volatile",
	"__volatile__",
#endif
    };
    unsigned i;

    /* Initialize type qualifier table. */
    type_qualifiers = new_symbol_table();
    for (i = 0; i < sizeof(keywords) / sizeof(keywords[0]); ++i) {
	new_symbol(type_qualifiers, keywords[i], NULL, DS_NONE);
    }
}

/* Process the C source file.  Write function prototypes to the standard
 * output.  Convert function definitions and write the converted source
 * code to a temporary file.
 */
void
process_file(FILE *infile, const char *name)
{
    const char *s;

    if (strlen(name) > 2) {
	s = name + strlen(name) - 2;
	if (*s == '.') {
	    ++s;
	    if (*s == 'l' || *s == 'y')
		BEGIN LEXYACC;
#if defined(MSDOS) || defined(OS2)
	    if (*s == 'L' || *s == 'Y')
		BEGIN LEXYACC;
#endif
	}
    }

    included_files = new_symbol_table();
    typedef_names = new_symbol_table();
    define_names = new_symbol_table();
    inc_depth = -1;
    curly = 0;
    ly_count = 0;
    func_params = NULL;
    yyin = infile;
    include_file(strcpy(base_file, name), func_style != FUNC_NONE);
    if (file_comments) {
#if OPT_LINTLIBRARY
	if (lintLibrary()) {
	    put_blankline(stdout);
	    begin_tracking();
	}
#endif
	put_string(stdout, "/* ");
	put_string(stdout, cur_file_name());
	put_string(stdout, " */\n");
    }
    yyparse();
    free_symbol_table(define_names);
    free_symbol_table(typedef_names);
    free_symbol_table(included_files);
}

#ifdef NO_LEAKS
void
free_parser(void)
{
    free_symbol_table(type_qualifiers);
#ifdef FLEX_SCANNER
    if (yy_current_buffer != 0)
	yy_delete_buffer(yy_current_buffer);
#endif
    if (temp_buf != 0) {
	temp_buf = 0;
	temp_len = 0;
    }
}
#endif
