#ifndef KOL_TOKEN_H
    #define KOL_TOKEN_H

    typedef struct st_Token {
        
        char *value;

        enum enum_token{
            TK_ID,
            TK_EQUALS,  
            TK_LPAREN,
            TK_RPAREN,
            TK_LBRACE,
            TK_RBRACE,
            TK_COLON,
            TK_COMMA,
            TK_LT,
            TK_GT,
            TK_INT,
            TK_TILED,
            TK_SEMICOLON,
            TK_EOF,
        } type;

    } Token;

    Token *init_token(char *value, int type);

    const char *token_type_to_string(int type);

    char *token_to_string(Token *token);

#endif