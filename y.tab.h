/* A Bison parser, made by GNU Bison 3.5.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
