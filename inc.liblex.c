/*
* THIS FILE IS INCLUDED BY "lex.l"!
* do not add to build chain.
* it's put into a separate file to make file navigation a bit easier.
* TODO: the current setup is, at *best*, destined to break at some point...
*       this file, lex.l, grammar.y, need to be chained better.
*/

static struct
{
    int varText;
    int varargs;
    int externs;
    int preproz;
} cmtVal;


/*
 * This recognizes some of the special attribute macros defined by gcc:
 *	noreturn
 *	format(printf,n,m)
 *	format(scanf,n,m)
 * and uses that information to construct equivalent lint-library text.
 * (It's a distinct piece of code from the 'absorb_special()' function to
 * avoid spurious matches with non-gcc compilers).
 */
void gcc_attribute(void)
{
    int c, num1, num2;
    int nest = 0;
    unsigned len = 0;
    char bfr[BUFSIZ];

    while((c = LexInput()) > 0)
    {
        if(len < sizeof(bfr) - 1 && !isspace(c))
            bfr[len++] = (char)c;
        if(c == '(')
            nest++;
        else if(c == ')')
        {
            if(--nest <= 0)
                break;
        }
    }
    bfr[len] = '\0';
    if(!strcmp(bfr, "((noreturn))"))
    {
        exitlike_func = true;
    }
    else if(sscanf(bfr, "((format(printf,%d,%d)))", &num1, &num2) == 2)
    {
        (void)sprintf(bfr, "PRINTFLIKE%d", varargs_num = num1);
        varargs_str = xstrdup(bfr);
    }
    else if(sscanf(bfr, "((format(scanf,%d,%d)))", &num1, &num2) == 2)
    {
        (void)sprintf(bfr, "SCANFLIKE%d", varargs_num = num1);
        varargs_str = xstrdup(bfr);
    }
}

/* Decode the current token according to the type-of-name
 */
int type_of_name(char* name)
{
    if(find_symbol(type_qualifiers, name) != NULL)
        return T_TYPE_QUALIFIER;
    else if(find_symbol(typedef_names, name) != NULL)
        return T_TYPEDEF_NAME;
    else if(find_symbol(define_names, name) != NULL)
        return T_DEFINE_NAME;
    else
        return T_IDENTIFIER;
}

boolean is_typedef_name(char* name)
{
    return (boolean)(find_symbol(typedef_names, name) != NULL);
}

/* If the matched text contains any new line characters, then update the
 * current line number.
 */
void update_line_num(void)
{
    char* p = yytext;
    while(*p != '\0')
    {
        if(*p++ == '\n')
            cur_file->line_num++;
    }
}

/* Save the matched text in the temporary file.
 */
void save_text(void)
{
    if(!in_cpp)
        copy_typedef(yytext);
    if(cur_file->convert)
    {
        fputs(yytext, cur_file->tmp_file);
    }
}

/* Record the current position in the temporary file and write the matched text
 * to the file.
 */
void save_text_offset(void)
{
    (void)strcpy(yylval.text.text, yytext);
    copy_typedef(yytext);
    if(cur_file->convert)
    {
        yylval.text.begin = ftell(cur_file->tmp_file);
        fputs(yytext, cur_file->tmp_file);
    }
    else
        yylval.text.begin = 0;
}

/* Decipher comments that are useful for lint (and making lint-libraries)
 */


int decipher_comment(char* keyword, int len)
{
    if(len != 0)
    {
        int value;
        keyword[len] = '\0';

        /* these are recognized by some lint-programs */
        if(!strcmp(keyword, "VARARGS"))
        {
            cmtVal.varargs = -1;
        }
        else if(sscanf(keyword, "VARARGS%d", &value) == 1)
        {
            cmtVal.varargs = value;
        }
        else if(!strcmp(keyword, "PRINTFLIKE"))
        {
            cmtVal.varargs = 1;
            cmtVal.varText = true;
        }
        else if(sscanf(keyword, "PRINTFLIKE%d", &value) == 1)
        {
            cmtVal.varargs = value;
            cmtVal.varText = true;
        }
        else if(!strcmp(keyword, "SCANFLIKE"))
        {
            cmtVal.varargs = 2;
            cmtVal.varText = true;
        }
        else if(sscanf(keyword, "SCANFLIKE%d", &value) == 1)
        {
            cmtVal.varargs = value;
            cmtVal.varText = true;
            /* these are extensions added to simplify library-generation */
        }
        else if(!strcmp(keyword, "LINT_EXTERN"))
        {
            cmtVal.externs = MAX_INC_DEPTH;
        }
        else if(sscanf(keyword, "LINT_EXTERN%d", &value) == 1)
        {
            cmtVal.externs = value;
        }
        else if(!strcmp(keyword, "LINT_PREPRO"))
        {
            cmtVal.preproz = -1; /* the whole comment */
        }
        else if(sscanf(keyword, "LINT_PREPRO%d", &value) == 1)
        {
            cmtVal.preproz = value;
        }
        else if(!strcmp(keyword, "LINT_SHADOWED"))
        {
            lint_shadowed = true;
        }
    }
    return 0;
}

void put_quoted(int c)
{
    /* Modifying 'yytext[]' doesn't work well with FLEX, which simply
     * maintains 'yytext' as a pointer into its input buffer.  LEX copies
     * characters into the 'yytext[]' array.
     */
#if defined(FLEX_SCANNER) || !defined(YYLMAX)
    if(c != 0)
    {
        static char temp[2];
        temp[0] = (char)c;
        /* save_text */
        if(!in_cpp)
            copy_typedef(temp);
        if(cur_file->convert)
        {
            fputs(temp, cur_file->tmp_file);
        }
        /* update_line_num */
        if(c == '\n')
            cur_file->line_num++;
    }
#else /* this works fine on LEX (e.g., on SunOS 4.x) */

    if((c == 0) || (yyleng + 1 >= YYLMAX))
    {
        save_text();
        update_line_num();
        yyleng = 0;
    }
    if(c != 0)
    {
        yytext[yyleng++] = c;
        yytext[yyleng] = 0;
    }
#endif /* LEX/FLEX */
}

/*
 * Scan past the characters in a backslash sequence
 */
/* Scan past quoted string.  Note that some strings may overflow 'yytext[]', so
 * we don't try to eat them in the lexical rules.
 */
void get_quoted(void)
{
    int delim = *yytext;
    int c;

#if defined(FLEX_SCANNER) || !defined(YYLMAX)
    put_quoted(delim);
#endif
    while((c = LexInput()) != 0)
    {
        if(c == '\\')
        {
            put_quoted(c);
            if((c = LexInput()) == 0)
                break;
            put_quoted(c);
        }
        else
        {
            put_quoted(c);
            if(c == delim)
                break;
            if(c == '\n')
            { /* recover from unbalanced */
                put_error();
                fprintf(stderr, "unbalanced quote character '%c'\n", delim);
                break;
            }
        }
    }
    put_quoted(0);
}

/* Scan to end of comment.
 */
void get_comment(void)
{
    int c, lastc = '\0';

    unsigned len = 0;
    char keyword[BUFSIZ];

    keyword[len] = '\0';
    cmtVal.varText = 0;
    cmtVal.varargs = 0;
    cmtVal.externs = -1;
    cmtVal.preproz = 0;

    while((c = LexInput()) != 0)
    {
        if(cur_file->convert)
            fputc(c, cur_file->tmp_file);

        if(!(isalnum(c) || c == '_' || c == '$'))
        {
            int flag = cmtVal.preproz;
            len = (unsigned)decipher_comment(keyword, (int)len);
            if(flag != cmtVal.preproz)
                lastc = '\0';
        }
        else if(len + 1 < sizeof(keyword))
        {
            keyword[len++] = (char)c;
        }

        switch(c)
        {
            case '\n':
                cur_file->line_num++;
                if(cmtVal.preproz != 0 && lastc != '\0')
                    fputc(lastc, stdout);
                if(cmtVal.preproz > 0) /* if negative, we pass everything */
                    cmtVal.preproz -= 1;
                break;
            case '/':
                if(lastc == '*')
                {
                    if(cur_file->convert)
                    {
                        if(func_params && cur_declarator)
                        {
                            cur_declarator->begin_comment = cur_file->begin_comment;
                            cur_file->begin_comment = ftell(cur_file->tmp_file);
                            cur_declarator->end_comment = cur_file->begin_comment;
                            cur_declarator = NULL;
                        }
                        else
                        {
                            cur_file->end_comment = ftell(cur_file->tmp_file);
                        }
                    }
                    (void)decipher_comment(keyword, (int)len);
                    if(cmtVal.varargs != 0)
                    {
                        if((varargs_num = cmtVal.varargs) != 0 && cmtVal.varText != 0)
                        {
                            if(varargs_str != 0)
                                free(varargs_str);
                            varargs_str = xstrdup(keyword);
                        }
                    }
                    if(cmtVal.externs >= 0)
                        extern_in = (unsigned)cmtVal.externs;
                    if(cmtVal.preproz != 0)
                        fputc('\n', stdout);
                    return;
                }
                /* FALLTHRU */
            default:
                if(cmtVal.preproz != 0 && lastc != '\0')
                    fputc(lastc, stdout);
                break;
        }
        lastc = c;
    }
}

/* Scan rest of preprocessor directive.  If copy is true, then store the text
 * in temp_buf.
 */
void get_cpp_directive(int copy)
{
    unsigned used = 0;
    char c, lastc[4];

    lastc[0] = lastc[1] = lastc[2] = lastc[3] = '\0';
    if(copy)
    {
        need_temp((size_t)2);
        *temp_buf = '\0';
    }

    while((c = (char)LexInput()) != 0)
    {
        if(cur_file->convert)
            fputc(c, cur_file->tmp_file);

        switch(c)
        {
            case '\n':
                cur_file->line_num++;
                if(lastc[2] != '\\' && strcmp(lastc, "?\?/") != 0)
                {
                    finishCpp();
                    return;
                }
                break;
            case '*':
                if(lastc[2] == '/')
                    get_comment();
                break;
        }
        lastc[0] = lastc[1];
        lastc[1] = lastc[2];
        lastc[2] = c;

        if(copy)
        {
            if(used + 2 >= temp_len)
                need_temp(temp_len + MAX_TEXT_SIZE);
            temp_buf[used++] = c;
            temp_buf[used] = '\0';
        }
    }
}

/*
 * Ensure that the filename buffer is large enough to hold yytext, e.g., if
 * the sscanf gave the whole buffer.
 */
void parsing_file_name(unsigned need)
{
    need += 2;
    if(cur_file->len_file_name < need)
    {
        cur_file->len_file_name += need;
        cur_file->file_name = (char*)xrealloc(cur_file->file_name, cur_file->len_file_name);
    }
    cur_file->file_name[0] = 0;
}

/* Return a pointer to the current file name.
 */
char* cur_file_name(void)
{
    return cur_file->file_name;
}

/* Return the current line number.
 */
unsigned cur_line_num(void)
{
    return cur_file->line_num;
}

/* Return the current temporary output file.
 */
FILE* cur_tmp_file(void)
{
    return cur_file->tmp_file;
}

/* Set the modify flag for the current file.
 */
void cur_file_changed(void)
{
    cur_file->changed = true;
}

/* Return the temporary file offset of beginning of the current comment.
 */
long cur_begin_comment(void)
{
    return cur_file->begin_comment;
}

/* Return the text of the current lexical token.
 */
char* cur_text(void)
{
    return yytext;
}

#if !HAVE_TMPFILE
/*
 * tmpfile() - return a FILE* for a temporary file that will be
 * removed automatically when the program exits.
 *
 * Not all systems have the ANSI tmpfile() function yet...
 *
 * David W. Sanderson (dws@cs.wisc.edu)
 *
 * note - this was in version 3.10 from 1993 - TD
 */
FILE* tmpfile(void)
{
    char* name;
    char* tmpdir;
    FILE* f;

    if((tmpdir = getenv("TMPDIR")) == (char*)0)
    {
        tmpdir = "/tmp";
    }
    name = xmalloc(strlen(tmpdir) + 20);
    sprintf(name, "%s/TfXXXXXX", tmpdir);
    call_mktemp(name);

    if((f = fopen(name, "w+")) != 0)
    {
        if(unlink(name) == -1)
        {
            fclose(f);
            f = 0;
        }
    }
    free(name);
    return f;
}
#endif /* !HAVE_TMPFILE */

/* Push a file onto the include stack.	The stream yyin must already
 * point to the file.
 * @name filename
 * @convert if true, convert function definitions
 */
void include_file(char* name, int convert)
{
    if(++inc_depth >= (int)inc_limit)
    {
        unsigned need = (inc_limit | 31) + 1;
#ifdef FLEX_SCANNER
        buffer_stack = type_realloc(YY_BUFFER_STATE, buffer_stack, need);
#endif
        inc_stack = type_realloc(IncludeStack, inc_stack, need);
        while(inc_limit < need)
        {
#ifdef FLEX_SCANNER
            buffer_stack[inc_limit] = 0;
#endif
            memset(inc_stack + inc_limit, 0, sizeof(*inc_stack));
            ++inc_limit;
        }
    }

    cur_file = inc_stack + inc_depth;
    cur_file->file = yyin;
    cur_file->base_name = xstrdup(name);
    cur_file->len_file_name = strlen(name) + MAX_TEXT_SIZE;
    cur_file->file_name = strcpy((char*)xmalloc(cur_file->len_file_name), name);
    cur_file->line_num = 1;
    cur_file->convert = (boolean)convert;
    cur_file->changed = false;

#ifdef FLEX_SCANNER
    buffer_stack[inc_depth] = yy_create_buffer(yyin, YY_BUF_SIZE);
    yy_switch_to_buffer(buffer_stack[inc_depth]);
#endif

    if(convert)
    {
        cur_file->begin_comment = cur_file->end_comment = 0;
        cur_file->tmp_file = tmpfile();
        if(cur_file->tmp_file == NULL)
        {
            fprintf(stderr, "%s: cannot create temporary file\n", progname);
            cur_file->convert = false;
        }
    }
}

#define BLOCK_SIZE 2048

/* Copy converted C source from the temporary file to the output stream.
 */
void put_file(FILE* outf)
{
    char block[BLOCK_SIZE];
    long filesize;
    size_t nread, count;

    filesize = ftell(cur_file->tmp_file);
    fseek(cur_file->tmp_file, 0L, 0);
    while(filesize > 0)
    {
        count = (filesize < BLOCK_SIZE) ? (size_t)filesize : BLOCK_SIZE;
        nread = fread(block, sizeof(char), count, cur_file->tmp_file);
        if(nread == 0)
            break;
        fwrite(block, sizeof(char), nread, outf);
        filesize -= (long)nread;
    }
}

/* Remove the top of the include stack.
 */
void pop_file(int closed)
{
    FILE* outf;

    if(!closed && (yyin != stdin))
        fclose(yyin);

    if(cur_file->convert)
    {
        if(yyin == stdin)
        {
            put_file(stdout);
        }
        else if(cur_file->changed)
        {
            if((outf = fopen(cur_file->base_name, "w")) != NULL)
            {
                put_file(outf);
                fclose(outf);
            }
            else
            {
                fprintf(stderr, "%s: cannot create file %s\n", progname, cur_file->base_name);
            }
        }

        fclose(cur_file->tmp_file);
    }
    free(cur_file->base_name);
    free(cur_file->file_name);

#ifdef FLEX_SCANNER
    yy_delete_buffer(YY_CURRENT_BUFFER);
#endif

    if(--inc_depth >= 0)
    {
        cur_file = inc_stack + inc_depth;
        yyin = cur_file->file;

#ifdef FLEX_SCANNER
        yy_switch_to_buffer(buffer_stack[inc_depth]);
#endif
    }
}

/* Process include directive.
 */
void do_include(char* file_spec) /* path surrounded by "" or <> */
{
    unsigned stdinc; /* 1 = path surrounded by <> */
    char* file;
    char* path;
    char match, *s;
    unsigned i;
    unsigned n;
    FILE* fp;

    if(file_spec[0] == '"')
    {
        match = '"';
        stdinc = 0;
    }
    else if(file_spec[0] == '<')
    {
        match = '>';
        stdinc = 1;
    }
    else
    {
        return;
    }
    s = (strchr)(file_spec + 1, match);
    n = (s != NULL) ? (unsigned)(s - file_spec - 1) : 0;
    file = xstrdup(file_spec + 1);
    file[n] = '\0';

    /* Do nothing if the file was already included. */
    path = (char*)xmalloc(strlen(file) + 3);
    sprintf(path, stdinc ? "<%s>" : "\"%s\"", file);
    if(find_symbol(included_files, path) == NULL)
    {
        new_symbol(included_files, path, NULL, DS_NONE);

        for(i = (unsigned)(stdinc != 0); i < num_inc_dir; ++i)
        {
            if(strlen(inc_dir[i]) == 0 || !strcmp(inc_dir[i], CURRENT_DIR))
            {
                strcpy(path, file);
            }
            else
            {
                path = (char*)xrealloc(path, strlen(file) + strlen(inc_dir[i]) + 2);
                sprintf(path, "%s/%s", inc_dir[i], file);
            }
            if((fp = fopen(path, "r")) != NULL)
            {
                yyin = fp;
                include_file(path, func_style != FUNC_NONE && !stdinc);
                free(file);
                free(path);
                return;
            }
        }

        if(!quiet)
        {
            put_error();
            fprintf(stderr, "cannot read file %s\n", file_spec);
        }
    }
    free(file);
    free(path);
}

/* When the end of the current input file is reached, pop a
 * nested include file.
 */
int yywrap(void)
{
    if(inc_depth > 0)
    {
        pop_file(false);
        return 0;
    }
    else
    {
        return 1;
    }
}

#ifdef NO_LEAKS
void free_lexer(void)
{
    if(inc_limit != 0)
    {
    #ifdef FLEX_SCANNER
        free(buffer_stack);
    #endif
        free(inc_stack);
    }
}
#endif
