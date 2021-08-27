#include "include/token.h"

#ifndef INCLUDED_STDLIB_H
    #include <stdlib.h>
    #define INCLUDED_STDLIB_H
#endif

Token *init_token(char *value, int type)
{
    //Token Initialization
    Token *token = (Token *)calloc(1,sizeof(Token));

    token->value = value;
    token->type  = type;

    return token;
}
