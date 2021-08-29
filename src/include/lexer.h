#ifndef KOL_LEXER_H
    #define KOL_LEXER_H

    #include "token.h"

    #ifndef INCLUDED_STDIO_H
        #include <stdio.h>
        #define INCLUDED_STDIO_H
    #endif

    typedef struct st_Lexer {

        char *src;
        size_t src_size;
        char c;
        unsigned int i;

    } Lexer;

    Lexer *init_lexer           (char *src);
    void   lexer_advance        (Lexer *lexer);
    char   lexer_peek           (Lexer *lexer, int offset);
    Token *lexer_advance_with   (Lexer *lexer, Token *token);
    Token *lexer_advance_current(Lexer *lexer, int type);
    void   lexer_skip_whitespace(Lexer *lexer);
    Token *lexer_parse_id       (Lexer *lexer);
    Token *lexer_parse_number   (Lexer *lexer);
    Token *lexer_next_token     (Lexer *lexer);

#endif