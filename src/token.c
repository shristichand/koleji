#include "include/token.h"

#ifndef INCLUDED_STDLIB_H
    #include <stdlib.h>
    #define INCLUDED_STDLIB_H
#endif

#ifndef INCLUDED_STRING_H
    #include <string.h>
    #define INCLUDED_STRING_H
#endif

#ifndef INCLUDED_STDIO_H
    #include <stdio.h>
    #define INCLUDED_STDIO_H
#endif

Token *init_token(char *value, int type)
{
    //Token Initialization
    Token *token = (Token *)calloc(1,sizeof(Token));

    token->value = value;
    token->type  = type;

    return token;
}

static const char *token_type_to_string(int type)
{
    switch(type)
    {
        case TK_ID       : return "TK_ID"; 
        case TK_EQUALS   : return "TK_EQUALS";
        case TK_LPAREN   : return "TK_LPAREN";
        case TK_RPAREN   : return "TK_RPAREN";
        case TK_LBARCE   : return "TK_LBARCE";
        case TK_RBRACE   : return "TK_RBARCE";
        case TK_COLON    : return "TK_COLON";
        case TK_COMMA    : return "TK_COMMA";
        case TK_LT       : return "TK_LT";
        case TK_GT       : return "TK_GT";
        case TK_INT      : return "TK_INT";
        case TK_RARROW   : return "TK_RARROW";
        case TK_SEMICOLON: return "TK_SEMICOLON";
        case TK_EOF      : return "TK_EOF";
    }

    return "TK_UNDEFINED";
}

char *token_to_string(Token *token)
{
    const char *type_string = token_type_to_string(token->type);
    const char *template    = "<type='%s', int_type='%d', value='%s'>\n";

    char *string = (char *) calloc( strlen(type_string) + strlen(template) + 8, sizeof(char));
    sprintf(string, template, type_string, token->type, token->value);

    return string;
}