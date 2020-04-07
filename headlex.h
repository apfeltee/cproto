
#pragma once

#define result(nn)              \
    count();                    \
    if(!brackets && unnested()) \
    return (nn)

#define is_IDENTIFIER   \
    save_text_offset(); \
    return type_of_name(yytext);

#ifdef apollo
    #define apollo_keyword
    #define apollo_special absorb_special()
#else
    #define apollo_keyword is_IDENTIFIER
    #define apollo_special is_IDENTIFIER
#endif

#ifdef vms
    #define vms_extern      \
        save_text_offset(); \
        return (T_EXTERN);
    #define vms_keyword save_text_offset();
#else /* unix */
    #define vms_extern is_IDENTIFIER
    #define vms_keyword is_IDENTIFIER
#endif /* vms/unix */

char* varargs_str; /* save printflike/scanflike text */
int varargs_num; /* code to save "VARARGS" */
int debug_trace; /* true if we trace token-level stuff */
char base_file[BUFSIZ]; /* top-level file name */

static int asm_level; /* parenthesis level for "asm" parsing */
static int save_cpp; /* true if cpp-text within curly braces */
static int in_cpp; /* true while we are within cpp-text */
static int curly; /* number of curly brace nesting levels */
static int ly_count; /* number of occurances of %% */

#ifdef FLEX_SCANNER
/* flex scanner state */
static YY_BUFFER_STATE* buffer_stack;

    #ifdef __cplusplus
        #define LexInput() yyinput()
    #endif

#endif /* FLEX_SCANNER */

#ifndef LexInput
    #define LexInput() input()
#endif

static unsigned inc_limit; /* stack size */
static int inc_depth; /* include nesting level */
static IncludeStack* inc_stack; /* stack of included files */
static SymbolTable* included_files; /* files already included */

int type_of_name(char* name);
void startCpp(int level);
void finishCpp(void);

void absorb_special(void);
void gcc_attribute(void);
void update_line_num(void);
void save_text(void);
void save_text_offset(void);
void get_quoted(void);
void get_comment(void);
void get_cpp_directive(int copy);
void parsing_file_name(unsigned need);
void do_include(char* f);
void include_file(char* name, int convert);
void put_file(FILE* outf);
void put_quoted(int c);
int decipher_comment(char* keyword, int len);
