%p 3000

%{

/* $Id: lex.l,v 4.23 2014/01/01 16:01:46 tom Exp $
 *
 * Lexical analyzer for C function prototype generator
 *
 *	This is designed to parse lexically at the top level (e.g., of extern
 *	objects such as procedures).  The corresponding yacc-grammar expects
 *	that curly-braces (for function bodies) are recognized as a single
 *	token, BRACES.  Similarly, square-brackets and their contents are
 *	passed back as BRACKETS.
 *
 *	Assignments at the top level are data-initialization statements.
 *	These are returned as INITIALIZER.
 *
 *	The logic here recognizes tokens inside curly-braces, but does not
 *	pass them back to the grammar.
 *
 * Apollo extensions:
 *	"&" is ignored when creating lint-libraries, because we ignore
 *	expressions of all kinds.  Note that function-prototypes may use "&" to
 *	denote reference-parameters.  By ignoring that as well, we make the
 *	output compatible with lint (kludge).
 *
 *	Similarly, ignore "std_$call", since it is not compatible with lint.
 *
 *	CPP_INLINE handles a special case of the Apollo CC 6.7 compiler that
 *	uses inline attribute declarations, e.g.
 *
 *		int	foo #attribute[aligned(1)];
 *
 *	In CC 6.8 this behavior is hidden by a macro.
 *
 * VAX/VMS extensions:
 *	Treat the keywords 'globalref', etc., as 'extern'.
 *
 *	The keywords 'noshare' and 'readonly' are type-qualifiers.
 *
 * GCC extensions:
 *	The keywords '__attribute__', '__inline', '__inline__', '__signed',
 *	'__signed__'. and '__extension__'
 */

#include "headlex.h"

%}

WS		[ \t]
LETTER		[A-Za-z$_]
DIGIT		[0-9]
ID		{LETTER}({LETTER}|{DIGIT})*
QUOTE		[\"\']

%s CPP1 INIT1 INIT2 CURLY LEXYACC ASM CPP_INLINE
%%

\n			{ save_text(); cur_file->line_num++;
			    cur_declarator = NULL; }

"/*"			{ save_text(); get_comment(); }
"//".*$ 		save_text();

<INITIAL>"&"		{ save_text(); return '&'; /* C++ ref-variable? */ }

<LEXYACC>^"%%"		{ save_text(); if (++ly_count >= 2) BEGIN INITIAL; }
<LEXYACC>^"%{"		{ save_text(); BEGIN INITIAL; }
<LEXYACC>{QUOTE}	get_quoted();
<LEXYACC>.		save_text();
<INITIAL>^"%}"		{ save_text(); BEGIN LEXYACC; }

<INITIAL>#{WS}* 	{ save_text(); startCpp(0); }
<INITIAL>"??="{WS}* 	{ save_text(); startCpp(0); }

<CPP1>attribute		{ BEGIN CPP_INLINE; /* apollo */}
<CPP1>options		{ BEGIN CPP_INLINE; /* apollo */}
<CPP_INLINE>[^;]*	finishCpp();

<CPP1>define{WS}+{ID}	{
			    char *name;
			    char *value;

			    save_text();

			    *(name = (char *) xmalloc((size_t) (yyleng + 1))) = '\0';
			    sscanf(yytext, "define %s", name);

			    get_cpp_directive(1);

			    *(value = (char *) xmalloc(1 + strlen(temp_buf))) = '\0';
			    sscanf(temp_buf, "%s", value);

			    new_symbol(define_names, name, value, DS_NONE);

			    free(name);
			    free(value);
			}

<CPP1>include{WS}*	{
			    save_text();

			    get_cpp_directive(1);

			    if (temp_buf[0] != '"' && temp_buf[0] != '<') {
				Symbol *sym = find_symbol(define_names, temp_buf);
				if (sym != NULL && sym->value != NULL) {
				    need_temp(strlen(sym->value));
				    strcpy(temp_buf, sym->value);
				} else {
				    temp_buf[0] = '\0';
				}
			    }
			    if (temp_buf[0] != '\0')
				do_include(temp_buf);
			}

<CPP1>line{WS}+[0-9]+{WS}+\".*$  {
			    save_text();

			    parsing_file_name((unsigned) yyleng);
			    sscanf(yytext, "line %u \"%[^\"]\"",
					   &cur_file->line_num,
					   cur_file->file_name);

			    cur_file->line_num--;
			    track_in();
			    finishCpp();
			}
<CPP1>[0-9]+{WS}+\".*$  {
			    save_text();

			    parsing_file_name((unsigned) yyleng);
			    sscanf(yytext, "%u \"%[^\"]\"",
					   &cur_file->line_num,
					   cur_file->file_name);

			    cur_file->line_num--;
			    track_in();
			    finishCpp();
			}
<CPP1>[0-9]+.*$ 	{
			    save_text();
			    sscanf(yytext, "%u ", &cur_file->line_num);
			    cur_file->line_num--;
			    track_in();
			    finishCpp();
			}

<CPP1>. 		{ save_text(); get_cpp_directive(0); }

<INITIAL>"("		{ save_text_offset(); return '('; }
<INITIAL>")"		{
			    save_text();
			    if (cur_file->convert)
				cur_file->begin_comment =
				 ftell(cur_file->tmp_file);
			    return ')';
			}
<INITIAL>"*"		{ save_text_offset(); return '*'; }
<INITIAL>[,;]		{
			    save_text();
			    if (cur_file->convert)
				cur_file->begin_comment =
				 ftell(cur_file->tmp_file);
			    return yytext[0];
			}
<INITIAL>"..."		{ save_text(); return T_ELLIPSIS; }
<INITIAL>\"		{
			    get_quoted();
			    return T_STRING_LITERAL;
			}

<INITIAL>"__asm__"	{ save_text(); BEGIN ASM; return T_ASM; }
<INITIAL>asm		{ save_text(); BEGIN ASM; return T_ASM; }
<ASM>"("		{ ++asm_level; save_text(); }
<ASM>")"		{ --asm_level; save_text(); if (asm_level <= 0) { asm_level = 0; BEGIN INITIAL; return T_ASMARG; } }
<ASM>{QUOTE} 		get_quoted();
<ASM>. 			save_text();

<INITIAL>__?based[^(]*\([^)]*\)	{ save_text_offset(); return T_TYPE_QUALIFIER; }

<INITIAL>auto		{ save_text_offset(); return T_AUTO; }
<INITIAL>extern 	{ save_text_offset(); return T_EXTERN; }
<INITIAL>register	{ save_text_offset(); return T_REGISTER; }
<INITIAL>static 	{ save_text_offset(); return T_STATIC; }
<INITIAL>typedef	{ save_text_offset(); return T_TYPEDEF; }
<INITIAL>inline 	{ save_text_offset(); return T_INLINE; }

<INITIAL>_Bool		{ save_text_offset(); return T_Bool; }
<INITIAL>_Complex	{ save_text_offset(); return T_Complex; }
<INITIAL>_Imaginary	{ save_text_offset(); return T_Imaginary; }

<INITIAL>char		{ save_text_offset(); return T_CHAR; }
<INITIAL>double 	{ save_text_offset(); return T_DOUBLE; }
<INITIAL>float		{ save_text_offset(); return T_FLOAT; }
<INITIAL>int		{ save_text_offset(); return T_INT; }
<INITIAL>void		{ save_text_offset(); return T_VOID; }
<INITIAL>long		{ save_text_offset(); return T_LONG; }
<INITIAL>short		{ save_text_offset(); return T_SHORT; }
<INITIAL>signed 	{ save_text_offset(); return T_SIGNED; }
<INITIAL>unsigned	{ save_text_offset(); return T_UNSIGNED; }

<INITIAL>enum		{ save_text_offset(); return T_ENUM; }
<INITIAL>struct 	{ save_text_offset(); return T_STRUCT; }
<INITIAL>union		{ save_text_offset(); return T_UNION; }
<INITIAL>va_dcl		{ save_text_offset(); return T_VA_DCL; }

<INITIAL>__signed 	{ save_text_offset(); return T_SIGNED; }
<INITIAL>__signed__ 	{ save_text_offset(); return T_SIGNED; }
<INITIAL>__inline 	{ save_text_offset(); return T_INLINE; }
<INITIAL>__inline__ 	{ save_text_offset(); return T_INLINE; }
<INITIAL>__extension__ 	{ save_text_offset(); return T_EXTENSION; }
<INITIAL>__attribute__	{ gcc_attribute(); }

<INITIAL>globalvalue	{ vms_extern; }
<INITIAL>globalref	{ vms_extern; }
<INITIAL>globaldef	{ vms_extern; }

<INITIAL>"std_$call"	{ apollo_keyword; }
<INITIAL>"__attribute"	{ apollo_special; }

<INITIAL>{ID}		{ is_IDENTIFIER }

<INITIAL>\[[^\]]*\]	{
			    /* This can't handle the case where a comment
			     * containing a ] appears between the brackets.
			     */
			    save_text_offset();
			    update_line_num();
			    return T_BRACKETS;
			}
<INITIAL>"??("[^?]*"??)"	{
			    save_text_offset();
			    update_line_num();
			    return T_BRACKETS;
			}

<INITIAL>"="		{ save_text(); BEGIN INIT1; return '='; }
<INIT1>"{"		{ save_text(); curly = 1; BEGIN INIT2; }
<INIT1>[,;]		{
			    unput(yytext[yyleng-1]);
			    BEGIN INITIAL;
			    return T_INITIALIZER;
			}
<INIT1>{QUOTE}		get_quoted();
<INIT1>.		save_text();

<INIT2>"{"		{ save_text(); ++curly; }
<INIT2>"}"		{
			    save_text();
			    if (--curly == 0) {
				BEGIN INITIAL;
				return T_INITIALIZER;
			    }
			}
<INIT2>{QUOTE}		get_quoted();
<INIT2>.		save_text();

<INITIAL>"{"		{
			    save_text();
			    curly = 1;
			    return_val =
			    returned_at = FALSE;
			    BEGIN CURLY;
			    return T_LBRACE;
			}
<CURLY>"{"		{ save_text(); ++curly; }
<CURLY>"}"		{
			    save_text();
			    if (--curly == 0) {
				BEGIN INITIAL;
				return T_MATCHRBRACE;
			    }
			}
<CURLY>{QUOTE}		get_quoted();
<CURLY>"return"		{ save_text(); returned_at = TRUE; }
<CURLY>";"		{ save_text(); returned_at = FALSE; }
<CURLY>#{WS}* 		{ save_text(); startCpp(1); }
<CURLY>"??="{WS}* 	{ save_text(); startCpp(1); }
<CURLY>.		{ save_text(); return_val |= returned_at; }

[ \r\t\f]+		save_text();
.			{
			    save_text();
			    put_error();
			    fprintf(stderr, "bad character '%c'\n", yytext[0]);
			}
%%

void startCpp(int level)
{
    save_cpp = level;
    in_cpp = TRUE;
    BEGIN CPP1;
}

void finishCpp(void)
{
    in_cpp = FALSE;
    if(save_cpp)
        BEGIN CURLY;
    else
        BEGIN INITIAL;
}

#include "inc.liblex.c"

