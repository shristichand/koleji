#include "include/lexer.h"

#ifndef INCLUDED_STDLIB_H
    #include <stdlib.h>
    #define INCLUDED_STDLIB_H
#endif

Lexer *init_lexer(char *src)
{
    //Lexer Initialization
    Lexer *lexer = (Lexer *)calloc(1,sizeof(Lexer));

    lexer->src = src;
    lexer->i   = 0;
    lexer->c   = src[lexer->i];

    return lexer;
}