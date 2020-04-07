
This is mostly an attempt to keep `cproto` up-to-date.  
Ideally, you should be able to clone this repository, and just run `make`.  
If that doesn't work for you, or you found other problems, please create an issue! Thank you.


Below is the original README file.

----

Cproto is a program that generates function prototypes and variable
declarations from C source code.  It can also convert function definitions
between the old style and the ANSI C style.  This conversion overwrites the
original files, so make a backup copy of your files in case something goes
wrong.

The program isn't confused by complex function definitions as much as other
prototype generators because it uses a yacc generated parser.  By ignoring all
the input between braces, I avoided implementing the entire C language grammar.

Cproto is in the public domain, except for the configure script which is
copyrighted by the Free Software Foundation, Inc.

Chin Huang

Thomas Dickey
dickey@invisible-island.net
