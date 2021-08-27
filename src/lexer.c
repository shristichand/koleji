#include "include/lexer.h"

Lexer *init_lexer(char *src)
{
    //Lexer Initialization
    Lexer *lexer = (Lexer *)calloc(1,sizeof(Lexer));

    lexer->src = src;
    lexer->i   = 0;
    lexer->c   = src[lexer->i];

    return lexer;
}