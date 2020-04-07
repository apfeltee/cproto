
/*
 * THIS FILE IS INCLUDED BY "grammar.y"!
 * do not add to build chain.
 * it's put into a separate file to make file navigation a bit easier.
 * TODO: the current setup is, at *best*, destined to break at some point...
 *       this file, lex.l, grammar.y, need to be chained better.
 */

#if defined(HAVE_CONFIG_H)
    #include "lex.yy.c"
#else
    #if defined(__EMX__) || defined(MSDOS) || defined(OS2) || defined(WIN32) || defined(vms)
        #ifdef USE_flex
            #include "lexyy.c"
        #else
            #include "lex_yy.c"
        #endif
    #else
        #include "lex.yy.c"
    #endif
#endif

static const char* keywords[] =
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
    "_Noreturn",
#endif
};

static void yaccError(const char* msg)
{
    func_params = NULL;
    put_error(); /* tell what line we're on, and what file */
    fprintf(stderr, "%s at token '%s'\n", msg, yytext);
}

/* Initialize the table of type qualifier keywords recognized by the lexical
 * analyzer.
 */
void init_parser(void)
{

    unsigned i;

    /* Initialize type qualifier table. */
    type_qualifiers = new_symbol_table();
    for(i = 0; i < sizeof(keywords) / sizeof(keywords[0]); ++i)
    {
        new_symbol(type_qualifiers, keywords[i], NULL, DS_NONE);
    }
}

/* Process the C source file.  Write function prototypes to the standard
 * output.  Convert function definitions and write the converted source
 * code to a temporary file.
 */
void process_file(FILE* infile, const char* name)
{
    const char* s;

    if(strlen(name) > 2)
    {
        s = name + strlen(name) - 2;
        if(*s == '.')
        {
            ++s;
            if(*s == 'l' || *s == 'y')
                BEGIN LEXYACC;
#if defined(MSDOS) || defined(OS2)
            if(*s == 'L' || *s == 'Y')
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
    if(file_comments)
    {
        if(lintLibrary())
        {
            put_blankline(stdout);
            begin_tracking();
        }
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
void free_parser(void)
{
    free_symbol_table(type_qualifiers);
    #ifdef FLEX_SCANNER
    if(yy_current_buffer != 0)
        yy_delete_buffer(yy_current_buffer);
    #endif
    if(temp_buf != 0)
    {
        temp_buf = 0;
        temp_len = 0;
    }
}
#endif
