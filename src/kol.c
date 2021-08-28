#include "include/kol.h"
#include "include/lexer.h"
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
    Token *token = 0;

    while( (token = lexer_next_token(lexer)) != TK_EOF)
    {
        printf("TOKEN (%s) = (%d)\n", token->value, token->type);
    }
}

void kol_compile_file(const char* fileName)
{
    char *src  = kol_read_file(fileName);
    kol_compile(src);
    free(src);
}