#ifndef KOL_TOKEN_H
    #define KOL_TOKEN_H

    typedef struct st_Token {
        
        char *value;

        enum enum_token{
            TK_ID,
            TK_EQUALS,  
            TK_LPAREN,
            TK_RPAREN,
            TK_LBARCE,
            TK_RBRACE,
            TK_COLON,
            TK_COMMA,
            TK_LT,
            TK_GT,
            TK_INT,
            TK_LARROW,
            TK_RARROW,
            TK_SEMICOLON,
            TK_EOF,
        } type;

    } Token;

    Token *init_token(char *value, int type);

#endif