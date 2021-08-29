#include "include/kol.h"
#include "include/lexer.h"
#include "include/parser.h"
#include "include/token.h"
#include "include/AST.h"
#include "include/FASM.h"
#include "include/io.h"

#ifndef INCLUDED_STDIO_H
    #include <stdio.h>
    #define INCLUDED_STDIO_H
#endif

#ifndef INCLUDED_STDLIB_H
    #include <stdlib.h>
    #define INCLUDED_STDLIB_H
#endif

void kol_compile(char *src)
{
    Lexer *lexer = init_lexer(src);
    Parser *parser = init_parser(lexer);
    AST *root = parser_parse(parser);


    printf("%p",root);
    char *fasm = asm_f(root);

    printf("\n%s\n",fasm);
}

void kol_compile_file(const char* fileName)
{
    char *src  = kol_read_file(fileName);
    kol_compile(src);
    free(src);
}