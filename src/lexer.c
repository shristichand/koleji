#include "include/lexer.h"
#include "include/macros.h"

#ifndef INCLUDED_STDLIB_H
    #include <stdlib.h>
    #define INCLUDED_STDLIB_H
#endif

#ifndef INCLUDED_STRING_H
    #include <string.h>
    #define INCLUDED_STRING_H
#endif

#ifndef INCLUDED_CTYPE_H
    #include <ctype.h>
    #define INCLUDED_CTYPE_H
#endif

Lexer *init_lexer(char *src)
{
    //Lexer Initialization
    Lexer *lexer    = (Lexer *)calloc(1,sizeof(Lexer));

    lexer->src      = src;
    lexer->src_size = strlen(src);
    lexer->i        = 0;
    lexer->c        = src[lexer->i];  // src = lexer->src

    return lexer;
}

void lexer_advance(Lexer *lexer)
{
    if( (lexer->i < lexer->src_size) && (lexer->c != '\0') )
    {
        lexer->i ++;
        lexer->c = lexer->src[lexer->i];
    }
}

char lexer_peek(Lexer *lexer, int offset)
{
    return lexer->src[MIN( (lexer->i + offset), lexer->src_size)];
}

Token *lexer_advance_with(Lexer *lexer, Token *token)
{
    lexer_advance(lexer);
    return token;
}

Token *lexer_advance_current(Lexer *lexer, int type)
{
    char *value = (char *)calloc(2, sizeof(char));
    value[0]    = lexer->c;
    value[1]    = '\0';

    Token *token = init_token(value, type);
    lexer_advance(lexer);

    return token;
}

void lexer_skip_whitespace(Lexer *lexer)
{
    while(lexer->c == 10 || lexer->c == 13 || lexer->c == ' ' || lexer->c == '\t')
        lexer_advance(lexer);
}

Token *lexer_parse_id(Lexer *lexer)
{
    char *value = (char *)calloc(1,sizeof(char));

    while(isalpha(lexer->c))
    {
        value = realloc(value, (strlen(value) + 2) * sizeof(char));
        strcat(value, (char []){lexer->c, 0});
        lexer_advance(lexer);
    }

    return init_token(value, TK_ID);
}

Token *lexer_parse_number(Lexer *lexer)
{
    char *value = (char *)calloc(1,sizeof(char));

    while(isalpha(lexer->c))
    {
        value = realloc(value, (strlen(value) + 2) * sizeof(char));
        strcat(value, (char []){lexer->c, 0});
        lexer_advance(lexer);
    }

    return init_token(value, TK_INT);
}

Token *lexer_next_token(Lexer *lexer)
{
    while(lexer->c != TK_EOF)
    {
        lexer_skip_whitespace(lexer);

        if(isalnum(lexer->c))
            return lexer_advance_with(lexer, lexer_parse_id(lexer));

        if(isdigit(lexer->c))
            return lexer_advance_with(lexer, lexer_parse_number(lexer));

        switch(lexer->c)
        {
            case '=':{
                if(lexer_peek(lexer, 1) == '>')
                    return lexer_advance_with(lexer, init_token("=>", TK_RARROW));
                return lexer_advance_with(lexer, init_token("=", TK_EQUALS));
            } break;

            case '(': return lexer_advance_current(lexer, TK_LPAREN);
            case ')': return lexer_advance_current(lexer, TK_RPAREN);
            case '<': return lexer_advance_current(lexer, TK_LT);
            case '>': return lexer_advance_current(lexer, TK_GT);
            case '{': return lexer_advance_current(lexer, TK_LBARCE);
            case '}': return lexer_advance_current(lexer, TK_RBRACE);
            case ':': return lexer_advance_current(lexer, TK_COLON);
            case ',': return lexer_advance_current(lexer, TK_COMMA);
            case ';': return lexer_advance_current(lexer, TK_SEMICOLON);
            case '\0': break;


            default:{
                printf("[Lexer] :: Unidentified Token %c.\n",lexer->c);
                exit(1);
            } break;
        }
    }
    return init_token(0, TK_EOF);
}