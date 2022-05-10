/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "Lab.y"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
void yyerror(char *s);
int yylex();
void interpretaCodigo();
void imprimeTablaCodigo();
void imprimeTablaSimbolo();
int genTemp();
int esEntero(int tipo);
void generaCodigo(int op,int a1,int a2,int a3);
int asignarSimbolo(char *lexema, int token);
int localizaSimboloAnadeNum(char *lexema , int token);
char lexema[100];
typedef struct{
        char nombre[100];
        int token;
        double valor;
        int tipo; // 0:sintipo 1: int    2: float    3: double   4: char   5: long     6: bool      7:short
        int noConstante; //0: constante    1: variable
}TipoTS;
typedef struct{
        int op;
        int a1;
        int a2;
        int a3; 
}TipoTC;
TipoTC tablaCodigo[100];
TipoTS tablaSimbolos[100];
int nSim=0;
int cx = -1;
int nVarTemp=1;

int vuelta[100]={0};
int cont_v=0;

int retornos[100]={0};
int numRetorn=0;

int avance[100]={0};
int contAvances=0;

int actualLoop[100]={0};
int numLoop=0;

int esConst=0;

#line 121 "y.tab.c"

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
    WHILE = 258,
    IF = 259,
    ID = 260,
    NUM = 261,
    DO = 262,
    FOR = 263,
    IGUALDAD = 264,
    ELSE = 265,
    ELIF = 266,
    CONTINUE = 267,
    INT = 268,
    LONG = 269,
    SHORT = 270,
    DOUBLE = 271,
    FLOAT = 272,
    CHAR = 273,
    BOOL = 274,
    VERDAD = 275,
    FALSO = 276,
    CONST = 277,
    BITSIZ = 278,
    BITSDE = 279,
    RETURN = 280,
    BREAK = 281,
    PASS = 282,
    INCREMENTO = 283,
    DECREMENTO = 284,
    AUMENTO = 285,
    DISMINUCION = 286,
    MULTI = 287,
    DIVI = 288,
    MOD = 289,
    PRINT = 290,
    COMENTARIOSIMPLE = 291,
    COMENTARIOCOMPLEJO = 292,
    DE_TIPO = 293,
    DESIGUALDAD = 294,
    SCAN = 295,
    NEGACION = 296,
    AND = 297,
    OR = 298,
    NAND = 299,
    XOR = 300,
    NOR = 301,
    COMPMAYOR = 302,
    COMPMENOR = 303,
    COMPMAYORIGUAL = 304,
    COMPMENORIGUAL = 305,
    COMPIGUAL = 306,
    COMPDESIGUAL = 307,
    SALTARF = 308,
    SALTAR = 309,
    COMPAND = 310,
    COMPOR = 311,
    COMPNAND = 312,
    ASIGNAR = 313,
    INCREMENTAR = 314,
    DECREMENTAR = 315,
    COMPXOR = 316,
    COMPNOR = 317,
    DECLARARINT = 318,
    DECLARARDOUBLE = 319,
    DECLARARCHAR = 320,
    DECLARARLONG = 321,
    DECLARARSHORT = 322,
    DECLARARFLOAT = 323,
    DECLARARBOOL = 324,
    MULTIPLICAR = 325,
    DIVIDIR = 326,
    MODULAR = 327,
    SUMAR = 328,
    RESTAR = 329,
    MOVERBDE = 330,
    MOVERBIZ = 331,
    IMPRIMIR = 332,
    DECLARARCONST = 333,
    DECLARARCONSTINT = 334,
    DECLARARCONSTDOUBLE = 335,
    DECLARARCONSTCHAR = 336,
    DECLARARCONSTLONG = 337,
    DECLARARCONSTSHORT = 338,
    DECLARARCONSTFLOAT = 339,
    DECLARARCONSTBOOL = 340,
    SALTARV = 341,
    CONTINUAR = 342,
    PASAR = 343,
    RETORNAR = 344,
    FIN = 345,
    ROMPER = 346,
    RETORNAR_TIPO = 347,
    NEGAR = 348,
    LEER = 349
  };
#endif
/* Tokens.  */
#define WHILE 258
#define IF 259
#define ID 260
#define NUM 261
#define DO 262
#define FOR 263
#define IGUALDAD 264
#define ELSE 265
#define ELIF 266
#define CONTINUE 267
#define INT 268
#define LONG 269
#define SHORT 270
#define DOUBLE 271
#define FLOAT 272
#define CHAR 273
#define BOOL 274
#define VERDAD 275
#define FALSO 276
#define CONST 277
#define BITSIZ 278
#define BITSDE 279
#define RETURN 280
#define BREAK 281
#define PASS 282
#define INCREMENTO 283
#define DECREMENTO 284
#define AUMENTO 285
#define DISMINUCION 286
#define MULTI 287
#define DIVI 288
#define MOD 289
#define PRINT 290
#define COMENTARIOSIMPLE 291
#define COMENTARIOCOMPLEJO 292
#define DE_TIPO 293
#define DESIGUALDAD 294
#define SCAN 295
#define NEGACION 296
#define AND 297
#define OR 298
#define NAND 299
#define XOR 300
#define NOR 301
#define COMPMAYOR 302
#define COMPMENOR 303
#define COMPMAYORIGUAL 304
#define COMPMENORIGUAL 305
#define COMPIGUAL 306
#define COMPDESIGUAL 307
#define SALTARF 308
#define SALTAR 309
#define COMPAND 310
#define COMPOR 311
#define COMPNAND 312
#define ASIGNAR 313
#define INCREMENTAR 314
#define DECREMENTAR 315
#define COMPXOR 316
#define COMPNOR 317
#define DECLARARINT 318
#define DECLARARDOUBLE 319
#define DECLARARCHAR 320
#define DECLARARLONG 321
#define DECLARARSHORT 322
#define DECLARARFLOAT 323
#define DECLARARBOOL 324
#define MULTIPLICAR 325
#define DIVIDIR 326
#define MODULAR 327
#define SUMAR 328
#define RESTAR 329
#define MOVERBDE 330
#define MOVERBIZ 331
#define IMPRIMIR 332
#define DECLARARCONST 333
#define DECLARARCONSTINT 334
#define DECLARARCONSTDOUBLE 335
#define DECLARARCONSTCHAR 336
#define DECLARARCONSTLONG 337
#define DECLARARCONSTSHORT 338
#define DECLARARCONSTFLOAT 339
#define DECLARARCONSTBOOL 340
#define SALTARV 341
#define CONTINUAR 342
#define PASAR 343
#define RETORNAR 344
#define FIN 345
#define ROMPER 346
#define RETORNAR_TIPO 347
#define NEGAR 348
#define LEER 349

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);





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
typedef yytype_uint8 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  64
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   247

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  108
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  175

#define YYUNDEFTOK  2
#define YYMAXUTOK   349


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   107,     2,     2,
      95,    96,   105,   103,     2,   104,     2,   106,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    97,
     102,   100,   101,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    98,     2,    99,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    81,    81,    83,    84,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     102,   103,   105,   107,   109,   109,   111,   113,   113,   113,
     113,   116,   116,   116,   117,   117,   118,   118,   118,   115,
     120,   120,   121,   120,   123,   123,   123,   123,   125,   127,
     127,   135,   135,   143,   143,   149,   149,   150,   150,   152,
     153,   154,   155,   156,   157,   160,   161,   162,   163,   164,
     165,   166,   169,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   186,   187,   188,   190,   195,
     197,   198,   199,   200,   201,   203,   204,   205,   206,   207,
     209,   212,   213,   213,   213,   213,   214,   216,   217
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "WHILE", "IF", "ID", "NUM", "DO", "FOR",
  "IGUALDAD", "ELSE", "ELIF", "CONTINUE", "INT", "LONG", "SHORT", "DOUBLE",
  "FLOAT", "CHAR", "BOOL", "VERDAD", "FALSO", "CONST", "BITSIZ", "BITSDE",
  "RETURN", "BREAK", "PASS", "INCREMENTO", "DECREMENTO", "AUMENTO",
  "DISMINUCION", "MULTI", "DIVI", "MOD", "PRINT", "COMENTARIOSIMPLE",
  "COMENTARIOCOMPLEJO", "DE_TIPO", "DESIGUALDAD", "SCAN", "NEGACION",
  "AND", "OR", "NAND", "XOR", "NOR", "COMPMAYOR", "COMPMENOR",
  "COMPMAYORIGUAL", "COMPMENORIGUAL", "COMPIGUAL", "COMPDESIGUAL",
  "SALTARF", "SALTAR", "COMPAND", "COMPOR", "COMPNAND", "ASIGNAR",
  "INCREMENTAR", "DECREMENTAR", "COMPXOR", "COMPNOR", "DECLARARINT",
  "DECLARARDOUBLE", "DECLARARCHAR", "DECLARARLONG", "DECLARARSHORT",
  "DECLARARFLOAT", "DECLARARBOOL", "MULTIPLICAR", "DIVIDIR", "MODULAR",
  "SUMAR", "RESTAR", "MOVERBDE", "MOVERBIZ", "IMPRIMIR", "DECLARARCONST",
  "DECLARARCONSTINT", "DECLARARCONSTDOUBLE", "DECLARARCONSTCHAR",
  "DECLARARCONSTLONG", "DECLARARCONSTSHORT", "DECLARARCONSTFLOAT",
  "DECLARARCONSTBOOL", "SALTARV", "CONTINUAR", "PASAR", "RETORNAR", "FIN",
  "ROMPER", "RETORNAR_TIPO", "NEGAR", "LEER", "'('", "')'", "';'", "'{'",
  "'}'", "'='", "'>'", "'<'", "'+'", "'-'", "'*'", "'/'", "'%'", "$accept",
  "prog", "listainst", "instr", "comentario", "comentarioSimple",
  "comentarioComplejo", "imprimir", "$@1", "leer", "iterativa_do", "@2",
  "@3", "@4", "iterativa_for", "@5", "@6", "@7", "@8", "@9", "$@10", "@11",
  "@12", "iterativa_while", "@13", "@14", "@15", "condicional", "@16",
  "@17", "$@18", "bloque", "declaracion", "@19", "@20", "asignacion",
  "@21", "@22", "@23", "asignar", "identificador", "expresion", "comp",
  "expr", "term", "op", "factor", "otrofactor", "else", "@24", "@25",
  "$@26", "funcion", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,    40,    41,    59,   123,   125,
      61,    62,    60,    43,    45,    42,    47,    37
};
# endif

#define YYPACT_NINF (-95)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-58)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     148,   -79,   -70,     5,   -95,   -95,   -55,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,    61,   -95,   -95,
     -95,   -46,   -95,   -95,   -35,   -28,   -10,     7,    86,   -95,
     148,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,     9,    20,   -94,   -17,   -95,   -95,   -95,   -95,
       7,    38,    63,    64,    -2,    96,   104,     7,     7,   105,
       7,   -95,    15,    20,   -95,   -95,   -95,     7,     7,     7,
       7,     7,     7,     7,    -3,    -1,     7,     7,   -95,   -95,
     -95,   -95,   -95,     7,     7,     2,   -95,   -95,   -95,   -95,
     -95,   -95,     7,   -95,   -95,   148,   112,    14,    19,   -95,
     -95,   -81,    22,   -72,   -95,   -95,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,     7,   -94,     7,   -94,   -17,   -17,   -95,
      20,   -95,   -95,    21,    24,   -95,    23,    28,   -95,   -95,
     -95,   -94,   -94,    29,    -2,   -95,   -95,     7,     7,   -95,
      -2,   -95,     7,    20,   -95,   -95,   -95,    20,   -95,   -95,
      42,    30,    31,    -2,    32,   -95,   -95,   -95,   -95,     7,
      96,    12,   -95,   -95,    33,    -2,   -95,   -95,   -95,   -95,
      -2,    42,   -95,   -95,   -95
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,   100,    95,    27,     0,    11,    65,    69,
      71,    67,    66,    68,    70,    98,    99,     0,    12,    13,
      14,     0,    22,    23,     0,     0,     0,     0,     0,     2,
       4,    18,    20,    21,    16,    17,     9,    10,     8,    15,
       5,     6,     0,     7,    84,    87,    89,    97,    19,    40,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   100,     0,    72,     1,     3,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,    93,
      90,    91,    94,     0,     0,     0,    60,    61,    62,    63,
      64,    59,     0,    56,    58,     4,     0,    53,     0,    51,
      24,     0,     0,     0,    96,    50,    77,    78,    79,    80,
      81,    82,    83,     0,    74,     0,    75,    85,    86,    88,
      41,    44,    54,     0,     0,    31,     0,     0,   107,    26,
     108,    73,    76,     0,     0,    48,    28,     0,     0,    25,
       0,    45,     0,    32,    52,    42,    46,    29,    33,    43,
     106,     0,     0,     0,     0,    47,    30,    34,   101,     0,
       0,     0,    35,   102,     0,     0,    36,   103,    37,   104,
       0,   106,    38,   105,    39
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -95,   -95,   -22,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -53,   -95,   -95,   -95,   -54,   -95,   -95,   -95,   -95,
     113,   -31,     0,   132,     6,   -95,    48,    73,   -38,   -95,
     -95,   -95,   -95
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    28,    29,    30,    31,    32,    33,    34,   127,    35,
      36,    54,   142,   151,    37,   137,   148,   152,   160,   164,
     168,   170,   174,    38,    84,   133,   149,    39,   134,   146,
     150,    96,    40,   105,   126,    41,    51,    52,    53,    92,
      42,    62,    63,    44,    45,    83,    46,    47,   155,   165,
     169,   171,    48
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      43,    98,    61,     4,    61,     4,    78,    79,    65,    76,
      77,    67,    61,     4,    66,   128,    49,    15,    16,    15,
      16,    67,    76,    77,   130,    50,   100,    15,    16,    67,
      43,    76,    77,   -55,   -57,   -53,   -53,   -53,   -53,   -53,
      55,    68,   -55,   -57,    69,    70,    71,    72,    73,    57,
      85,    68,   153,   154,    69,    70,    71,    72,    73,    68,
      58,   122,    69,    70,    71,    72,    73,    59,    86,    87,
      88,    89,    90,   123,     8,     9,    10,    11,    12,    13,
      14,   141,   117,   118,   120,    60,    64,   145,    80,    81,
      82,    93,    27,    94,    27,    43,    95,   113,   121,   115,
     158,    97,    27,    74,    75,   -53,   162,   144,   163,    99,
      61,   104,   167,    74,    75,   124,   125,   172,   129,   136,
     135,    74,    75,   138,   139,   140,   156,   159,   157,   166,
      56,   119,   102,   173,     0,     0,     0,   143,    91,     0,
       0,     0,   147,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     2,     3,     4,     5,     6,     0,     0,   161,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,     0,     0,    18,    19,    20,     0,     0,     0,     0,
       0,     0,     0,    21,    22,    23,    24,     0,    25,    26,
     101,     0,   103,     0,     0,     0,     0,     0,     0,   106,
     107,   108,   109,   110,   111,   112,   114,   116,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    27,     0,   131,     0,   132
};

static const yytype_int16 yycheck[] =
{
       0,    55,     5,     6,     5,     6,    23,    24,    30,   103,
     104,     9,     5,     6,     5,    96,    95,    20,    21,    20,
      21,     9,   103,   104,    96,    95,    57,    20,    21,     9,
      30,   103,   104,    28,    29,    30,    31,    32,    33,    34,
      95,    39,    28,    29,    42,    43,    44,    45,    46,    95,
      50,    39,    10,    11,    42,    43,    44,    45,    46,    39,
      95,    92,    42,    43,    44,    45,    46,    95,    30,    31,
      32,    33,    34,    95,    13,    14,    15,    16,    17,    18,
      19,   134,    76,    77,    84,    95,     0,   140,   105,   106,
     107,    28,    95,    29,    95,    95,    98,   100,    96,   100,
     153,     5,    95,   101,   102,   100,   160,   138,    96,     5,
       5,    96,   165,   101,   102,     3,    97,   170,    96,    95,
      99,   101,   102,   100,    96,    96,    96,    95,    97,    96,
      17,    83,    59,   171,    -1,    -1,    -1,   137,   100,    -1,
      -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    -1,   159,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    25,    26,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    36,    37,    38,    -1,    40,    41,
      58,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    -1,   113,    -1,   115
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    25,    26,
      27,    35,    36,    37,    38,    40,    41,    95,   109,   110,
     111,   112,   113,   114,   115,   117,   118,   122,   131,   135,
     140,   143,   148,   150,   151,   152,   154,   155,   160,    95,
      95,   144,   145,   146,   119,    95,   148,    95,    95,    95,
      95,     5,   149,   150,     0,   110,     5,     9,    39,    42,
      43,    44,    45,    46,   101,   102,   103,   104,    23,    24,
     105,   106,   107,   153,   132,   150,    30,    31,    32,    33,
      34,   100,   147,    28,    29,    98,   139,     5,   143,     5,
     149,   151,   155,   151,    96,   141,   151,   151,   151,   151,
     151,   151,   151,   100,   151,   100,   151,   152,   152,   154,
     150,    96,   149,   110,     3,    97,   142,   116,    96,    96,
      96,   151,   151,   133,   136,    99,    95,   123,   100,    96,
      96,   139,   120,   150,   149,   139,   137,   150,   124,   134,
     138,   121,   125,    10,    11,   156,    96,    97,   139,    95,
     126,   150,   143,    96,   127,   157,    96,   139,   128,   158,
     129,   159,   139,   156,   130
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   108,   109,   110,   110,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     112,   112,   113,   114,   116,   115,   117,   119,   120,   121,
     118,   123,   124,   125,   126,   127,   128,   129,   130,   122,
     132,   133,   134,   131,   136,   137,   138,   135,   139,   141,
     140,   142,   140,   144,   143,   145,   143,   146,   143,   147,
     147,   147,   147,   147,   147,   148,   148,   148,   148,   148,
     148,   148,   149,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   151,   151,   151,   152,   152,
     153,   153,   153,   153,   153,   154,   154,   154,   154,   154,
     155,   156,   157,   158,   159,   156,   156,   160,   160
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     5,     4,     0,     0,     0,
       9,     0,     0,     0,     0,     0,     0,     0,     0,    17,
       0,     0,     0,     8,     0,     0,     0,     9,     3,     0,
       3,     0,     6,     0,     4,     0,     3,     0,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     3,     3,     4,     3,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     2,     0,     0,     0,     9,     0,     4,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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
  case 2:
#line 81 "Lab.y"
                {generaCodigo(FIN,'-','-','-'); int i=0; for(i=0;i<numRetorn;i++){tablaCodigo[retornos[i]].a1 = cx;} }
#line 1697 "y.tab.c"
    break;

  case 11:
#line 92 "Lab.y"
               {generaCodigo(CONTINUAR,vuelta[cont_v-1],'-','-');}
#line 1703 "y.tab.c"
    break;

  case 12:
#line 93 "Lab.y"
             {generaCodigo(RETORNAR,'?','-','-'); retornos[numRetorn++]=cx;}
#line 1709 "y.tab.c"
    break;

  case 13:
#line 94 "Lab.y"
            {generaCodigo(ROMPER,'?','-','-'); actualLoop[numLoop-1]++; avance[contAvances++]=cx;}
#line 1715 "y.tab.c"
    break;

  case 14:
#line 95 "Lab.y"
           {generaCodigo(PASAR,'-','-','-');}
#line 1721 "y.tab.c"
    break;

  case 24:
#line 109 "Lab.y"
                          {generaCodigo(IMPRIMIR,yyvsp[0],'-','-');}
#line 1727 "y.tab.c"
    break;

  case 26:
#line 111 "Lab.y"
                             {generaCodigo(LEER,yyvsp[-1],'-','-');}
#line 1733 "y.tab.c"
    break;

  case 27:
#line 113 "Lab.y"
         {vuelta[cont_v++]=cx+1; numLoop++; yyval=cx+1;}
#line 1739 "y.tab.c"
    break;

  case 28:
#line 113 "Lab.y"
                                                                       {yyval=cx+1;}
#line 1745 "y.tab.c"
    break;

  case 29:
#line 113 "Lab.y"
                                                                                       {generaCodigo(SALTARV,yyvsp[0],yyvsp[-5],'-'); cont_v--; yyval=cx; int i; for(i=0;i<actualLoop[numLoop-1];i++){tablaCodigo[avance[--contAvances]].a1 = cx +1;} numLoop--;}
#line 1751 "y.tab.c"
    break;

  case 31:
#line 116 "Lab.y"
            {numLoop++; yyval=cx+1;}
#line 1757 "y.tab.c"
    break;

  case 32:
#line 116 "Lab.y"
                                       {generaCodigo(SALTARF,yyvsp[0],'?','-'); yyval=cx;}
#line 1763 "y.tab.c"
    break;

  case 33:
#line 116 "Lab.y"
                                                                                  {generaCodigo(SALTAR,'?','-','-'); yyval=cx;}
#line 1769 "y.tab.c"
    break;

  case 34:
#line 117 "Lab.y"
            {vuelta[cont_v++]=cx+1; yyval=cx+1;}
#line 1775 "y.tab.c"
    break;

  case 35:
#line 117 "Lab.y"
                                                         {generaCodigo(SALTAR,yyvsp[-6],'-','-'); yyval=cx;}
#line 1781 "y.tab.c"
    break;

  case 36:
#line 118 "Lab.y"
            { tablaCodigo[yyvsp[-5]].a1= cx + 1; }
#line 1787 "y.tab.c"
    break;

  case 37:
#line 118 "Lab.y"
                                            {yyval=cx+1;}
#line 1793 "y.tab.c"
    break;

  case 38:
#line 118 "Lab.y"
                                                              {generaCodigo(SALTAR,yyvsp[-6],'-','-'); yyval=cx;}
#line 1799 "y.tab.c"
    break;

  case 39:
#line 118 "Lab.y"
                                                                                                         { tablaCodigo[yyvsp[-10]].a2 = cx +1 ; cont_v--;int i; for(i=0;i<actualLoop[numLoop-1];i++){tablaCodigo[avance[--contAvances]].a1 = cx +1;} numLoop--;}
#line 1805 "y.tab.c"
    break;

  case 40:
#line 120 "Lab.y"
                {vuelta[cont_v++]=cx+1; numLoop++; yyval=cx+1;}
#line 1811 "y.tab.c"
    break;

  case 41:
#line 120 "Lab.y"
                                                                  {generaCodigo(SALTARF,yyvsp[0],'?','-'); yyval=cx;}
#line 1817 "y.tab.c"
    break;

  case 42:
#line 121 "Lab.y"
                   {generaCodigo(SALTAR,yyvsp[-4],'-','-'); yyval=cx;}
#line 1823 "y.tab.c"
    break;

  case 43:
#line 121 "Lab.y"
                                                             { tablaCodigo[yyvsp[-3]].a2 = cx +1 ; cont_v--; int i; for(i=0;i<actualLoop[numLoop-1];i++){tablaCodigo[avance[--contAvances]].a1 = cx +1;} numLoop--;}
#line 1829 "y.tab.c"
    break;

  case 44:
#line 123 "Lab.y"
                      {generaCodigo(SALTARF,yyvsp[-1],'?','-'); yyval=cx;}
#line 1835 "y.tab.c"
    break;

  case 45:
#line 123 "Lab.y"
                                                                        {generaCodigo(SALTARV,yyvsp[-3],'?','-'); yyval=cx;}
#line 1841 "y.tab.c"
    break;

  case 46:
#line 123 "Lab.y"
                                                                                                                   { tablaCodigo[yyvsp[-2]].a2 = cx +1 ; }
#line 1847 "y.tab.c"
    break;

  case 47:
#line 123 "Lab.y"
                                                                                                                                                          { tablaCodigo[yyvsp[-2]].a2 = cx +1 ; }
#line 1853 "y.tab.c"
    break;

  case 49:
#line 127 "Lab.y"
                       {yyval=asignarSimbolo(lexema,ID); }
#line 1859 "y.tab.c"
    break;

  case 50:
#line 127 "Lab.y"
                                                        {if(yyvsp[-2]==1)generaCodigo(DECLARARINT,yyvsp[0],'-','-');
                                                                else if(yyvsp[-2]==2)generaCodigo(DECLARARFLOAT,yyvsp[0],'-','-');
                                                                else if(yyvsp[-2]==3)generaCodigo(DECLARARDOUBLE,yyvsp[0],'-','-');
                                                                else if(yyvsp[-2]==4)generaCodigo(DECLARARCHAR,yyvsp[0],'-','-');
                                                                else if(yyvsp[-2]==5)generaCodigo(DECLARARLONG,yyvsp[0],'-','-');
                                                                else if(yyvsp[-2]==6)generaCodigo(DECLARARBOOL,yyvsp[0],'-','-');
                                                                else if(yyvsp[-2]==7){generaCodigo(DECLARARSHORT,yyvsp[0],'-','-');printf("hola2\n");}}
#line 1871 "y.tab.c"
    break;

  case 51:
#line 135 "Lab.y"
                             {esConst=1;yyval=asignarSimbolo(lexema,ID);esConst=0;}
#line 1877 "y.tab.c"
    break;

  case 52:
#line 135 "Lab.y"
                                                                                               {if(yyvsp[-4]==1)generaCodigo(DECLARARCONSTINT,yyvsp[-2],yyvsp[0],'-');
                                                                else if(yyvsp[-4]==2)generaCodigo(DECLARARCONSTFLOAT,yyvsp[-2],yyvsp[0],'-');
                                                                else if(yyvsp[-4]==3)generaCodigo(DECLARARCONSTDOUBLE,yyvsp[-2],yyvsp[0],'-');
                                                                else if(yyvsp[-4]==4)generaCodigo(DECLARARCONSTCHAR,yyvsp[-2],yyvsp[0],'-');
                                                                else if(yyvsp[-4]==5)generaCodigo(DECLARARCONSTLONG,yyvsp[-2],yyvsp[0],'-');
                                                                else if(yyvsp[-4]==6)generaCodigo(DECLARARCONSTBOOL,yyvsp[-2],yyvsp[0],'-');
                                                                else if(yyvsp[-4]==7)generaCodigo(DECLARARCONSTSHORT,yyvsp[-2],yyvsp[0],'-'); }
#line 1889 "y.tab.c"
    break;

  case 53:
#line 143 "Lab.y"
         {yyval=localizaSimboloAnadeNum(lexema,ID);}
#line 1895 "y.tab.c"
    break;

  case 54:
#line 143 "Lab.y"
                                                                    {if(yyvsp[-1]==1)generaCodigo(ASIGNAR,yyvsp[-2],yyvsp[0],'-');
                                                                else if(yyvsp[-1]==2)generaCodigo(SUMAR,yyvsp[-2],yyvsp[-2],yyvsp[0]);
                                                                else if(yyvsp[-1]==3)generaCodigo(RESTAR,yyvsp[-2],yyvsp[-2],yyvsp[0]);
                                                                else if(yyvsp[-1]==4)generaCodigo(MULTIPLICAR,yyvsp[-2],yyvsp[-2],yyvsp[0]);
                                                                else if(yyvsp[-1]==5)generaCodigo(DIVIDIR,yyvsp[-2],yyvsp[-2],yyvsp[0]);
                                                                else if(yyvsp[-1]==6)generaCodigo(MODULAR,yyvsp[-2],yyvsp[-2],yyvsp[0]);}
#line 1906 "y.tab.c"
    break;

  case 55:
#line 149 "Lab.y"
         {yyval=localizaSimboloAnadeNum(lexema,ID);}
#line 1912 "y.tab.c"
    break;

  case 56:
#line 149 "Lab.y"
                                                             {generaCodigo(INCREMENTAR,yyvsp[-1],'-','-');}
#line 1918 "y.tab.c"
    break;

  case 57:
#line 150 "Lab.y"
         {yyval=localizaSimboloAnadeNum(lexema,ID);}
#line 1924 "y.tab.c"
    break;

  case 58:
#line 150 "Lab.y"
                                                             {generaCodigo(DECREMENTAR,yyvsp[-1],'-','-');}
#line 1930 "y.tab.c"
    break;

  case 59:
#line 152 "Lab.y"
         {yyval=1;}
#line 1936 "y.tab.c"
    break;

  case 60:
#line 153 "Lab.y"
             {yyval=2;}
#line 1942 "y.tab.c"
    break;

  case 61:
#line 154 "Lab.y"
                 {yyval=3;}
#line 1948 "y.tab.c"
    break;

  case 62:
#line 155 "Lab.y"
           {yyval=4;}
#line 1954 "y.tab.c"
    break;

  case 63:
#line 156 "Lab.y"
          {yyval=5;}
#line 1960 "y.tab.c"
    break;

  case 64:
#line 157 "Lab.y"
         {yyval=6;}
#line 1966 "y.tab.c"
    break;

  case 65:
#line 160 "Lab.y"
          {yyval=1;}
#line 1972 "y.tab.c"
    break;

  case 66:
#line 161 "Lab.y"
            {yyval=2;}
#line 1978 "y.tab.c"
    break;

  case 67:
#line 162 "Lab.y"
             {yyval=3;}
#line 1984 "y.tab.c"
    break;

  case 68:
#line 163 "Lab.y"
           {yyval=4;}
#line 1990 "y.tab.c"
    break;

  case 69:
#line 164 "Lab.y"
           {yyval=5;}
#line 1996 "y.tab.c"
    break;

  case 70:
#line 165 "Lab.y"
           {yyval=6;}
#line 2002 "y.tab.c"
    break;

  case 71:
#line 166 "Lab.y"
            {yyval=7; printf("hola1\n");}
#line 2008 "y.tab.c"
    break;

  case 73:
#line 172 "Lab.y"
                         {int i=genTemp(); generaCodigo(COMPMAYORIGUAL,i,yyvsp[-3],yyvsp[0]);yyval=i;}
#line 2014 "y.tab.c"
    break;

  case 74:
#line 173 "Lab.y"
                      {int i=genTemp(); generaCodigo(COMPMAYOR,i,yyvsp[-2],yyvsp[0]);yyval=i;}
#line 2020 "y.tab.c"
    break;

  case 75:
#line 174 "Lab.y"
                      {int i=genTemp(); generaCodigo(COMPMENOR,i,yyvsp[-2],yyvsp[0]);yyval=i;}
#line 2026 "y.tab.c"
    break;

  case 76:
#line 175 "Lab.y"
                          {int i=genTemp(); generaCodigo(COMPMENORIGUAL,i,yyvsp[-3],yyvsp[0]);yyval=i;}
#line 2032 "y.tab.c"
    break;

  case 77:
#line 176 "Lab.y"
                          {int i=genTemp(); generaCodigo(COMPIGUAL,i,yyvsp[-2],yyvsp[0]);yyval=i;}
#line 2038 "y.tab.c"
    break;

  case 78:
#line 177 "Lab.y"
                             {int i=genTemp(); generaCodigo(COMPDESIGUAL,i,yyvsp[-2],yyvsp[0]);yyval=i;}
#line 2044 "y.tab.c"
    break;

  case 79:
#line 178 "Lab.y"
                    {int i=genTemp(); generaCodigo(COMPAND,i,yyvsp[-2],yyvsp[0]);yyval=i;}
#line 2050 "y.tab.c"
    break;

  case 80:
#line 179 "Lab.y"
                   {int i=genTemp(); generaCodigo(COMPOR,i,yyvsp[-2],yyvsp[0]);yyval=i;}
#line 2056 "y.tab.c"
    break;

  case 81:
#line 180 "Lab.y"
                     {int i=genTemp(); generaCodigo(COMPNAND,i,yyvsp[-2],yyvsp[0]);yyval=i;}
#line 2062 "y.tab.c"
    break;

  case 82:
#line 181 "Lab.y"
                    {int i=genTemp(); generaCodigo(COMPXOR,i,yyvsp[-2],yyvsp[0]);yyval=i;}
#line 2068 "y.tab.c"
    break;

  case 83:
#line 182 "Lab.y"
                    {int i=genTemp(); generaCodigo(COMPNOR,i,yyvsp[-2],yyvsp[0]);yyval=i;}
#line 2074 "y.tab.c"
    break;

  case 85:
#line 186 "Lab.y"
                     { int i=genTemp(); generaCodigo(SUMAR,i,yyvsp[-2],yyvsp[0]); yyval=i;}
#line 2080 "y.tab.c"
    break;

  case 86:
#line 187 "Lab.y"
                      { int i=genTemp(); generaCodigo(RESTAR,i,yyvsp[-2],yyvsp[0]); yyval=i;}
#line 2086 "y.tab.c"
    break;

  case 88:
#line 190 "Lab.y"
                      { int i=genTemp(); if(yyvsp[-1]==1) generaCodigo(MULTIPLICAR,i,yyvsp[-2],yyvsp[0]); 
                                    else if(yyvsp[-1]==2) generaCodigo(DIVIDIR,i,yyvsp[-2],yyvsp[0]); 
                                    else if(yyvsp[-1]==3) generaCodigo(MOVERBIZ,i,yyvsp[-2],yyvsp[0]); 
                                    else if(yyvsp[-1]==4) generaCodigo(MOVERBDE,i,yyvsp[-2],yyvsp[0]); 
                                    else if(yyvsp[-1]==5) generaCodigo(MODULAR,i,yyvsp[-2],yyvsp[0]); yyval=i;}
#line 2096 "y.tab.c"
    break;

  case 90:
#line 197 "Lab.y"
         {yyval=1;}
#line 2102 "y.tab.c"
    break;

  case 91:
#line 198 "Lab.y"
          {yyval=2;}
#line 2108 "y.tab.c"
    break;

  case 92:
#line 199 "Lab.y"
             {yyval=3;}
#line 2114 "y.tab.c"
    break;

  case 93:
#line 200 "Lab.y"
             {yyval=4;}
#line 2120 "y.tab.c"
    break;

  case 94:
#line 201 "Lab.y"
         {yyval=5;}
#line 2126 "y.tab.c"
    break;

  case 95:
#line 203 "Lab.y"
          { yyval=localizaSimboloAnadeNum(lexema,NUM);}
#line 2132 "y.tab.c"
    break;

  case 96:
#line 204 "Lab.y"
                        {yyval=yyvsp[-1];}
#line 2138 "y.tab.c"
    break;

  case 98:
#line 206 "Lab.y"
             { yyval=localizaSimboloAnadeNum(lexema,VERDAD);}
#line 2144 "y.tab.c"
    break;

  case 99:
#line 207 "Lab.y"
            { yyval=localizaSimboloAnadeNum(lexema,FALSO);}
#line 2150 "y.tab.c"
    break;

  case 100:
#line 209 "Lab.y"
          { yyval=localizaSimboloAnadeNum(lexema,ID);}
#line 2156 "y.tab.c"
    break;

  case 102:
#line 213 "Lab.y"
                       {generaCodigo(SALTARF,yyvsp[-1],'?','-'); yyval=cx;}
#line 2162 "y.tab.c"
    break;

  case 103:
#line 213 "Lab.y"
                                                                         {generaCodigo(SALTARV,yyvsp[-3],'?','-'); yyval=cx;}
#line 2168 "y.tab.c"
    break;

  case 104:
#line 213 "Lab.y"
                                                                                                                    { tablaCodigo[yyvsp[-2]].a2 = cx +1 ; }
#line 2174 "y.tab.c"
    break;

  case 105:
#line 213 "Lab.y"
                                                                                                                                                           { tablaCodigo[yyvsp[-2]].a2 = cx +1 ; }
#line 2180 "y.tab.c"
    break;

  case 107:
#line 216 "Lab.y"
                           {int i=genTemp(); generaCodigo(RETORNAR_TIPO,i,yyvsp[-1],'-'); yyval=i;}
#line 2186 "y.tab.c"
    break;

  case 108:
#line 217 "Lab.y"
                            {int i=genTemp(); generaCodigo(NEGAR,i,yyvsp[-1],'-'); yyval=i;}
#line 2192 "y.tab.c"
    break;


#line 2196 "y.tab.c"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 218 "Lab.y"


void imprimeTablaCodigo(){
    for(int p=0;p<35;p++)putchar('-');
    printf("\nTabla de Codigos\n");
    for(int p=0;p<35;p++)putchar('-');
    putchar('\n');
    for(int i=0;i<=cx ;i++){
        printf("%2d\t%3d\t%3d\t%3d\t%3d\t\n",
        i, tablaCodigo[i].op,tablaCodigo[i].a1, tablaCodigo[i].a2, tablaCodigo[i].a3);
    }putchar('\n');
}

void imprimeTablaSimbolo(){
    putchar('\n');
    for(int p=0;p<48;p++)putchar('-');
    printf("\nTabla de Simbolos\n");
    for(int p=0;p<48;p++)putchar('-');
    putchar('\n');
    for(int i=0;i<nSim ;i++){
        printf("%2d   %-20s %5d %16.4lf\n",
        i, tablaSimbolos[i].nombre,tablaSimbolos[i].token,tablaSimbolos[i].valor);
    }putchar('\n');
}

int genTemp(){
    int pos;
    char t[10]; 
    sprintf(t,"_T%d",nVarTemp++);
    pos= asignarSimbolo(t,ID);
    return pos;
}

void generaCodigo(int op,int a1,int a2,int a3){
    cx++;
    tablaCodigo[cx].op=op;
    tablaCodigo[cx].a1=a1;
    tablaCodigo[cx].a2=a2;
    tablaCodigo[cx].a3=a3;
}

int esEntero(int tipo){
    if(tipo==1){
        return 1;
    }
    if(tipo==4){
        return 1;
    }
    if(tipo==5){
        return 1;
    }
    if(tipo==6){
        return 1;
    }
    if(tipo==7){
        return 1;
    }return 0;
}

/*codigo C*/
/*análisis léxico*/

void interpretaCodigo(){
    int op,a1,a2,a3,imprimio=0;
    double aux1, aux2;
    for(int i=0;i<=cx ;i++){
        op=tablaCodigo[i].op;
        a1=tablaCodigo[i].a1;
        a2=tablaCodigo[i].a2;
        a3=tablaCodigo[i].a3;
        if (op==ASIGNAR){
            if(tablaSimbolos[a1].noConstante) tablaSimbolos[a1].valor = tablaSimbolos[a2].valor;
            else {
                printf("Error al intentar cambiar una constante\n");
                exit(1);
            }
        }
        if(op==SALTARF){
            if (fabs(tablaSimbolos[a1].valor-0)<=0.0001){
                i=a2-1;
            }
        }
        if(op==SALTARV){
            if (fabs(tablaSimbolos[a1].valor-1)<=0.0001){
                i=a2-1;
            }
        }
        if(op==SALTAR){
            i=a1-1;
        }
        if(op==COMPMENOR){
            if(esEntero(tablaSimbolos[a2].tipo)){
                tablaSimbolos[a1].valor = (int)(tablaSimbolos[a2].valor+0.5) < tablaSimbolos[a3].valor;
            }
            else if(esEntero(tablaSimbolos[a3].tipo)){
                tablaSimbolos[a1].valor = tablaSimbolos[a2].valor < (int)(tablaSimbolos[a3].valor+0.5);
            }
            else if(esEntero(tablaSimbolos[a2].tipo) && esEntero(tablaSimbolos[a3].tipo)){
                tablaSimbolos[a1].valor = (int)(tablaSimbolos[a2].valor+0.5) < (int)(tablaSimbolos[a3].valor+0.5);
            }
            else tablaSimbolos[a1].valor = tablaSimbolos[a2].valor < tablaSimbolos[a3].valor;
        }
        if(op==COMPMAYOR){
            if(esEntero(tablaSimbolos[a2].tipo)){
                tablaSimbolos[a1].valor = (int)(tablaSimbolos[a2].valor+0.5) > tablaSimbolos[a3].valor;
            }
            else if(esEntero(tablaSimbolos[a3].tipo)){
                tablaSimbolos[a1].valor = tablaSimbolos[a2].valor > (int)(tablaSimbolos[a3].valor+0.5);
            }
            else if(esEntero(tablaSimbolos[a2].tipo) && esEntero(tablaSimbolos[a3].tipo)){
                tablaSimbolos[a1].valor = (int)(tablaSimbolos[a2].valor+0.5) > (int)(tablaSimbolos[a3].valor+0.5);
            }
            else tablaSimbolos[a1].valor = tablaSimbolos[a2].valor > tablaSimbolos[a3].valor;
        }
        if(op==COMPMAYORIGUAL){
            if(esEntero(tablaSimbolos[a2].tipo)){
                tablaSimbolos[a1].valor = (int)(tablaSimbolos[a2].valor+0.5) >= tablaSimbolos[a3].valor;
            }
            else if(esEntero(tablaSimbolos[a3].tipo)){
                tablaSimbolos[a1].valor = tablaSimbolos[a2].valor >= (int)(tablaSimbolos[a3].valor+0.5);
            }
            else if(esEntero(tablaSimbolos[a2].tipo) && esEntero(tablaSimbolos[a3].tipo)){
                tablaSimbolos[a1].valor = (int)(tablaSimbolos[a2].valor+0.5) >= (int)(tablaSimbolos[a3].valor+0.5);
            }
            else tablaSimbolos[a1].valor = tablaSimbolos[a2].valor >= tablaSimbolos[a3].valor;
        }
        if(op==COMPMENORIGUAL){
            if(esEntero(tablaSimbolos[a2].tipo)){
                tablaSimbolos[a1].valor = (int)(tablaSimbolos[a2].valor+0.5) <= tablaSimbolos[a3].valor;
            }
            else if(esEntero(tablaSimbolos[a3].tipo)){
                tablaSimbolos[a1].valor = tablaSimbolos[a2].valor <= (int)(tablaSimbolos[a3].valor+0.5);
            }
            else if(esEntero(tablaSimbolos[a2].tipo) && esEntero(tablaSimbolos[a3].tipo)){
                tablaSimbolos[a1].valor = (int)(tablaSimbolos[a2].valor+0.5) <= (int)(tablaSimbolos[a3].valor+0.5);
            }
            else tablaSimbolos[a1].valor = tablaSimbolos[a2].valor <= tablaSimbolos[a3].valor;
        }
        if(op==COMPIGUAL){
            if(esEntero(tablaSimbolos[a2].tipo)){
                tablaSimbolos[a1].valor = (int)(tablaSimbolos[a2].valor+0.5) == tablaSimbolos[a3].valor;
            }
            else if(esEntero(tablaSimbolos[a3].tipo)){
                tablaSimbolos[a1].valor = tablaSimbolos[a2].valor == (int)(tablaSimbolos[a3].valor+0.5);
            }
            else if(esEntero(tablaSimbolos[a2].tipo) && esEntero(tablaSimbolos[a3].tipo)){
                tablaSimbolos[a1].valor = (int)(tablaSimbolos[a2].valor+0.5) == (int)(tablaSimbolos[a3].valor+0.5);
            }
            else tablaSimbolos[a1].valor = tablaSimbolos[a2].valor == tablaSimbolos[a3].valor;
        }
        if(op==COMPDESIGUAL){
            if(esEntero(tablaSimbolos[a2].tipo)){
                tablaSimbolos[a1].valor = (int)(tablaSimbolos[a2].valor+0.5) != tablaSimbolos[a3].valor;
            }
            else if(esEntero(tablaSimbolos[a3].tipo)){
                tablaSimbolos[a1].valor = tablaSimbolos[a2].valor != (int)(tablaSimbolos[a3].valor+0.5);
            }
            else if(esEntero(tablaSimbolos[a2].tipo) && esEntero(tablaSimbolos[a3].tipo)){
                tablaSimbolos[a1].valor = (int)(tablaSimbolos[a2].valor+0.5) != (int)(tablaSimbolos[a3].valor+0.5);
            }
            else tablaSimbolos[a1].valor = tablaSimbolos[a2].valor != tablaSimbolos[a3].valor;
        }
        if(op==COMPAND){
            tablaSimbolos[a1].valor = ((int)(tablaSimbolos[a2].valor+0.5)) && ((int)(tablaSimbolos[a3].valor+0.5)); 
        }
        if(op==COMPOR){
            tablaSimbolos[a1].valor = ((int)(tablaSimbolos[a2].valor+0.5)) || ((int)(tablaSimbolos[a3].valor+0.5)); 
        }
        if(op==COMPNAND){
            tablaSimbolos[a1].valor = !(((int)(tablaSimbolos[a2].valor+0.5)) && ((int)(tablaSimbolos[a3].valor+0.5)));
        }
        if(op==COMPXOR){
            tablaSimbolos[a1].valor = (!((int)(tablaSimbolos[a2].valor+0.5)) && ((int)(tablaSimbolos[a3].valor+0.5))) || (((int)(tablaSimbolos[a2].valor+0.5)) && !((int)(tablaSimbolos[a3].valor+0.5)));
        }
        if(op==COMPNOR){
            tablaSimbolos[a1].valor = !(((int)(tablaSimbolos[a2].valor+0.5)) || ((int)(tablaSimbolos[a3].valor+0.5)));
        }
        if(op==INCREMENTAR){
            if(tablaSimbolos[a1].noConstante) tablaSimbolos[a1].valor = tablaSimbolos[a1].valor + 1;
            else {
                printf("Error al intentar cambiar una constante\n");
                exit(1);
            }
        }
        if(op==DECREMENTO){
            if(tablaSimbolos[a1].noConstante) tablaSimbolos[a1].valor = tablaSimbolos[a1].valor - 1;
            else {
                printf("Error al intentar cambiar una constante\n");
                exit(1);
            } 
        }
        if(op==SUMAR){
            if(tablaSimbolos[a1].noConstante) {
                if(esEntero(tablaSimbolos[a2].tipo)) tablaSimbolos[a2].valor=(int)(tablaSimbolos[a2].valor+0.5);
                if(esEntero(tablaSimbolos[a3].tipo)) tablaSimbolos[a3].valor=(int)(tablaSimbolos[a3].valor+0.5);
            tablaSimbolos[a1].valor = tablaSimbolos[a2].valor + tablaSimbolos[a3].valor; 
            }
            else {
                printf("Error al intentar cambiar una constante %d \n",a1);
                exit(1);
            }
        }
        if(op==RESTAR){
            if(tablaSimbolos[a1].noConstante){
                if(esEntero(tablaSimbolos[a2].tipo)) tablaSimbolos[a2].valor=(int)(tablaSimbolos[a2].valor+0.5);
                if(esEntero(tablaSimbolos[a3].tipo)) tablaSimbolos[a3].valor=(int)(tablaSimbolos[a3].valor+0.5);
                tablaSimbolos[a1].valor = tablaSimbolos[a2].valor - tablaSimbolos[a3].valor;
            }
            else {
                printf("Error al intentar cambiar una constante\n");
                exit(1);
            } 
        }
        if(op==MULTIPLICAR){
            if(tablaSimbolos[a1].noConstante){
                if(esEntero(tablaSimbolos[a2].tipo)) tablaSimbolos[a2].valor=(int)(tablaSimbolos[a2].valor+0.5);
                if(esEntero(tablaSimbolos[a3].tipo)) tablaSimbolos[a3].valor=(int)(tablaSimbolos[a3].valor+0.5);
                tablaSimbolos[a1].valor = tablaSimbolos[a2].valor * tablaSimbolos[a3].valor;
            }
            else {
                printf("Error al intentar cambiar una constante\n");
                exit(1);
            } 
        }
        if(op==DIVIDIR){
            if(tablaSimbolos[a1].noConstante) {
                if(esEntero(tablaSimbolos[a2].tipo)) tablaSimbolos[a2].valor=(int)(tablaSimbolos[a2].valor+0.5);
                if(esEntero(tablaSimbolos[a3].tipo)) tablaSimbolos[a3].valor=(int)(tablaSimbolos[a3].valor+0.5);
                tablaSimbolos[a1].valor = tablaSimbolos[a2].valor / tablaSimbolos[a3].valor;
            }
            else {
                printf("Error al intentar cambiar una constante\n");
                exit(1);
            } 
        }
        if(op==MODULAR){
            aux1 = tablaSimbolos[a2].valor + 0.5;
            aux2 = tablaSimbolos[a3].valor + 0.5;
            if(tablaSimbolos[a1].noConstante) tablaSimbolos[a1].valor = (int)aux1 % (int)aux2;
            else {
                printf("Error al intentar cambiar una constante\n");
                exit(1);
            } 
        }
        if(op==MOVERBIZ){
            int auxbits1=(int)(tablaSimbolos[a2].valor+0.5);
            int auxbits2=(int)(tablaSimbolos[a3].valor+0.5);
            if(tablaSimbolos[a1].noConstante) {
                tablaSimbolos[a1].valor = (double)(auxbits1<<auxbits2);
            }
            else {
                printf("Error al intentar cambiar una constante\n");
                exit(1);
            } 
        }
        if(op==MOVERBDE){
            int auxbits1=(int)(tablaSimbolos[a2].valor+0.5);
            int auxbits2=(int)(tablaSimbolos[a3].valor+0.5);
            if(tablaSimbolos[a1].noConstante) {
                tablaSimbolos[a1].valor = (double)(auxbits1>>auxbits2);
            }
            else {
                printf("Error al intentar cambiar una constante\n");
                exit(1);
            } 
        }
        
        if(op==DECLARARCONSTINT){
            tablaSimbolos[a1].valor = tablaSimbolos[a2].valor;
            tablaSimbolos[a1].noConstante = 0;
            tablaSimbolos[a1].tipo = 1;
        }
        if(op==DECLARARCONSTFLOAT){
            tablaSimbolos[a1].valor = tablaSimbolos[a2].valor;
            tablaSimbolos[a1].noConstante = 0;
            tablaSimbolos[a1].tipo = 2;
        }
        if(op==DECLARARCONSTDOUBLE){
            tablaSimbolos[a1].valor = tablaSimbolos[a2].valor;
            tablaSimbolos[a1].noConstante = 0;
            tablaSimbolos[a1].tipo = 3;
        }        
        if(op==DECLARARCONSTCHAR){
            tablaSimbolos[a1].valor = tablaSimbolos[a2].valor;
            tablaSimbolos[a1].noConstante = 0;
            tablaSimbolos[a1].tipo = 4;
        }
        if(op==DECLARARCONSTLONG){
            tablaSimbolos[a1].valor = tablaSimbolos[a2].valor;
            tablaSimbolos[a1].noConstante = 0;
            tablaSimbolos[a1].tipo = 5;
        }
        if(op==DECLARARCONSTBOOL){
            tablaSimbolos[a1].valor = tablaSimbolos[a2].valor;
            tablaSimbolos[a1].noConstante = 0;
            tablaSimbolos[a1].tipo = 6;
        }
        if(op==DECLARARCONSTSHORT){
            tablaSimbolos[a1].valor = tablaSimbolos[a2].valor;
            tablaSimbolos[a1].noConstante = 0;
            tablaSimbolos[a1].tipo = 7;
        }
        if(op == IMPRIMIR){
            if(!imprimio){
                printf("+-----------------------------------+\n");
                printf("| Terminal                          |\n");
            }imprimio=1;
            if(esEntero(tablaSimbolos[a1].tipo))
                printf("| >  %-30d |\n",(int)tablaSimbolos[a1].valor);
            else printf("| >  %-30lf |\n",tablaSimbolos[a1].valor);
        }
        if(op == CONTINUAR) {
            i = a1 - 1;
        }
        
        if(op==DECLARARINT){
            tablaSimbolos[a1].noConstante = 1;
            tablaSimbolos[a1].tipo = 1;
        }
        if(op==DECLARARFLOAT){
            tablaSimbolos[a1].noConstante = 1;
            tablaSimbolos[a1].tipo = 2;
        }
        if(op==DECLARARDOUBLE){
            tablaSimbolos[a1].noConstante = 1;
            tablaSimbolos[a1].tipo = 3;
        }
        if(op==DECLARARCHAR){
            tablaSimbolos[a1].noConstante = 1;
            tablaSimbolos[a1].tipo = 4;
        }
        if(op==DECLARARLONG){
            tablaSimbolos[a1].noConstante = 1;
            tablaSimbolos[a1].tipo = 5;
        }
        if(op==DECLARARBOOL){
            tablaSimbolos[a1].noConstante = 1;
            tablaSimbolos[a1].tipo = 6;
        }
        if(op==DECLARARSHORT){
            tablaSimbolos[a1].noConstante = 1;
            tablaSimbolos[a1].tipo = 7;
        }
        if(op==RETORNAR){
            i=a1-1;
        }
        if(op==ROMPER){
            i=a1-1;
        }
    }
    if(imprimio) printf("+-----------------------------------+\n");
}

/*localiza el lexema dentro de la tabla de simbolos*/
int asignarSimbolo(char *lexema, int token){
	int i;
	for(i=0;i<nSim ;i++){
        if(!strcmp(tablaSimbolos[i].nombre,lexema)){
            printf("Error al declarar dos veces una misma variable: %s\n",lexema);
            exit(1);
        }
    }
    strcpy(tablaSimbolos[i].nombre,lexema);
    tablaSimbolos[i].valor=0.0;
    tablaSimbolos[i].token=token;
    tablaSimbolos[i].noConstante=!esConst;
    nSim++;
    return nSim-1;
}

int localizaSimboloAnadeNum(char *lexema , int token){ 
    int i;
    for(i=0;i<nSim ;i++){
        if(!strcmp(tablaSimbolos[i].nombre,lexema)){
            return i;
        }
    }
    if(token == NUM ){ 
        strcpy(tablaSimbolos[i].nombre,lexema); 
        tablaSimbolos[i].valor=atof(lexema); 
        tablaSimbolos[i].token=token;  
        tablaSimbolos[i].tipo = 2;
    } 
    if(token == VERDAD ){ 
        strcpy(tablaSimbolos[i].nombre,lexema); 
        tablaSimbolos[i].valor=1; 
        tablaSimbolos[i].token=token;  
        tablaSimbolos[i].tipo = 1;
    } 
    if(token == FALSO ){ 
        strcpy(tablaSimbolos[i].nombre,lexema); 
        tablaSimbolos[i].valor=0; 
        tablaSimbolos[i].token=token;  
        tablaSimbolos[i].tipo = 1;
    } 
    else if(token == ID){ 
        printf("Variable no reconocida: %s\n", lexema);
        exit(1);
    }
    nSim++;
    return nSim-1;
}

int yylex(){
    int i;
    char c;
    
    c=getchar();
    while(c==' ' || c=='\n' || c=='\t'){ 
        c=getchar(); 
        if(c!=' ' && c!='\n' && c!='\t') break;
    }             
    if(c=='#') return 0;
    
    if(isalpha(c)){
        i=0;
        do{
            lexema[i++]=c;
            c=getchar();
        }while(isalnum(c));
        ungetc(c,stdin);
        lexema[i++]='\0';
        if(!strcmp(lexema,"terminamos")) return BREAK;
        if(!strcmp(lexema,"regresemos")) return RETURN;
        if(!strcmp(lexema,"nada")) return PASS;
        if(!strcmp(lexema,"sisi")) return IF;
        if(!strcmp(lexema,"mientras")) return WHILE;
        if(!strcmp(lexema,"enteroAmor")) return INT;
        if(!strcmp(lexema,"realAmor"))return FLOAT;
        if(!strcmp(lexema,"doblementeReal"))return DOUBLE;
        if(!strcmp(lexema,"caracterCorazoncito")) return CHAR;
        if(!strcmp(lexema,"cortaRelacion")) return SHORT;
        if(!strcmp(lexema,"largaDuracion")) return LONG;
        if(!strcmp(lexema,"boolCool")) return BOOL;
        if(!strcmp(lexema,"falsoAmor")) return FALSO;
        if(!strcmp(lexema,"verdaderoSentimiento")) return VERDAD;
        if(!strcmp(lexema,"constanteRechazo"))    return CONST;
        if(!strcmp(lexema,"haz")) return DO;
        if(!strcmp(lexema,"para")) return FOR;
        if(!strcmp(lexema,"osino")) return ELSE;
        if(!strcmp(lexema,"osisi")) return ELIF;
        if(!strcmp(lexema,"volvamos")) return CONTINUE;
        if(!strcmp(lexema,"imprimir")) return PRINT;
        if(!strcmp(lexema,"leer")) return SCAN;
        if(!strcmp(lexema,"deTipo")) return DE_TIPO;
        if(!strcmp(lexema,"jamas")) return NEGACION;
        if(!strcmp(lexema,"yh")) return AND;
        if(!strcmp(lexema,"oh")) return OR;
        if(!strcmp(lexema,"nomas")) return NAND;
        if(!strcmp(lexema,"ellaOyo")) return XOR;
        if(!strcmp(lexema,"nituNiyo")) return NOR;
        return ID;
    }

    if(isdigit(c)){
        i=0;
        do{
            lexema[i++]=c;
            c=getchar();
        }while(isdigit(c) || c=='.');
        ungetc(c,stdin);
        lexema[i++]='\0';
        return NUM;
    } 
    
    if (c=='/'){
        c=getchar();
        if (c=='/'){  
            while(getchar()!='\n');
            return COMENTARIOSIMPLE;                        
        }
        else if (c == '=') {
            return DIVI;
        }
        else{
            ungetc(c,stdin);
            return '/';
        }  
    }
    
    if (c=='@'){
        while(getchar()!='@');
        return COMENTARIOCOMPLEJO;  
    } 

    if (c=='!'){
        c=getchar();
        if (c=='='){  
            return DESIGUALDAD;                        
        }
        else{
            ungetc(c,stdin);
            return '=';
        }  
    }             
               
    if (c=='='){
        c=getchar();
        if (c=='='){  
            return IGUALDAD;                        
        }
        else{
            ungetc(c,stdin);
            return '=';
        }  
    }
                
    if (c=='+'){
        c=getchar();
        if (c=='+'){  
            return INCREMENTO;                        
        }
        else if(c == '='){
            return AUMENTO;
        }
        else{
            ungetc(c,stdin);
            return '+';
        }  
    }
    
    if (c=='-'){
        c=getchar();
        if (c=='-'){  
            return DECREMENTO ;                        
        }
        else if (c == '='){
            return DISMINUCION;
        }
        else{
            ungetc(c,stdin);
            return '-';
        }  
    }
    
    if (c=='*'){
        c=getchar();
        if (c=='='){  
            return MULTI;                        
        }
        else{
            ungetc(c,stdin);
            return '*';
        }
    }     
       	
    if (c=='%'){
        c=getchar();
        if (c=='='){  
            return MOD;                        
        }
        else{
            ungetc(c,stdin);
            return '%';
        }
    } 
    
    if (c=='<'){
        c=getchar();
        if (c=='<'){  
            return BITSIZ;                        
        }
        else{
            ungetc(c,stdin);
            return '<';
        }  
    }
    
    if (c=='>'){
        c=getchar();
        if (c=='>'){  
            return BITSDE;                        
        }
        else{
            ungetc(c,stdin);
            return '>';
        }  
    }
    
    return c;
}

void yyerror(char *s){
	fprintf(stderr,"%s\n",s);
}

int main(){
    if(!yyparse()){
        imprimeTablaSimbolo();
        imprimeTablaCodigo();
        printf("Luego de la interpretacion\n");
        interpretaCodigo();
        imprimeTablaSimbolo(); 
        printf("Cadena válida\n\n");
	}
	else{
        printf("Cadena inválida\n\n");	
	}
    return 0;
}
