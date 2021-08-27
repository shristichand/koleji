#ifndef KOL_LEXER_H
    #define KOL_LEXER_H

    typedef struct st_Lexer {

        char *src;
        char c;
        unsigned int i;

    } Lexer;

    Lexer *init_lexer(char *src);
    
#endif