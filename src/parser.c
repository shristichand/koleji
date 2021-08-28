#include "include/parser.h"
#include "include/type.h"

#ifndef INCLUDED_STDIO_H
    #include <stdio.h>
    #define INCLUDED_STDIO_H
#endif

#ifndef INCLUDED_STDLIB_H
    #include <stdlib.h>
    #define INCLUDED_STDLIB_H
#endif

Parser *init_parser(Lexer *lexer)
{
    Parser *parser = (Parser *)calloc(1, sizeof(Parser));

    parser->lexer = lexer;
    parser->token = lexer_next_token(lexer);

    return parser;
}

Token *parser_eat(Parser *parser, int type)
{
    printf("\nParsing %s\n",token_to_string(parser->token));
    if(parser->token->type != type)
    {
        printf("[Parser] :: Unidentified Token %s.\n",token_to_string(parser->token));
        printf("Insted, expected '%s'\n",token_type_to_string(type));
        exit(1);
    }
    printf("Parsed %s\n",token_to_string(parser->token));

    parser->token = lexer_next_token(parser->lexer);

    return parser->token;
}

AST *parser_parse(Parser *parser)
{
    return parser_parse_compound(parser);
}

AST *parser_parse_id(Parser* parser)
{
    char *value = parser->token->value;
    parser_eat(parser, TK_ID);

    if(parser->token->type == TK_EQUALS)
    {
        parser_eat(parser, TK_EQUALS);
        AST *ast = init_ast(AST_ASSIGNMENT);
        ast->name = value;
        ast->value = parser_parse_exp(parser);
        return ast;
    }

    AST *ast = init_ast(AST_VARIABLE);
    ast->name = value;

    if(parser->token->type == TK_COLON)
    {
        parser_eat(parser, TK_COLON);

        while(parser->token->type == TK_ID)
        {
            ast->data_type = typeName_to_int(parser->token->value);
            parser_eat(parser, TK_ID);

            if(parser->token->type == TK_LT)
            {
                parser_eat(parser, TK_LT);
                ast->data_type += typeName_to_int(parser->token->value);
                parser_eat(parser, TK_ID);
                parser_eat(parser, TK_GT);
            }
        }
    }

    return ast;
}

AST *parser_parse_block(Parser *parser)
{
    parser_eat(parser, TK_LBRACE);

    AST *ast = init_ast(AST_COMPOUND);

    while(parser->token->type != TK_RBRACE)
    {
        list_push(ast->children, parser_parse_exp(parser));

        if(parser->token->type == TK_SEMICOLON)
            parser_eat(parser, TK_SEMICOLON);
    }

    parser_eat(parser, TK_RBRACE);

    return ast;
}

// if parenthesis initialize this.
AST *parser_parse_list(Parser *parser)
{
    parser_eat(parser, TK_LPAREN);
    AST *compound = init_ast(AST_COMPOUND);
    list_push(compound->children, parser_parse_exp(parser));

    while(parser->token->type == TK_COMMA)
    {
        parser_eat(parser, TK_COMMA);
        list_push(compound->children, parser_parse_exp(parser));
    }

    parser_eat(parser, TK_RPAREN);

    if(parser->token->type == TK_COLON)
    {
        parser_eat(parser, TK_COLON);

        while(parser->token->type == TK_ID)
        {
            compound->data_type = typeName_to_int(parser->token->value);
            parser_eat(parser, TK_ID);

            if(parser->token->type == TK_LT)
            {
                parser_eat(parser, TK_LT);
                compound->data_type += typeName_to_int(parser->token->value);
                parser_eat(parser, TK_ID);
                parser_eat(parser, TK_GT);
            }
        }
    }

    if(parser->token->type == TK_TILED)
    {
        parser_eat(parser, TK_TILED);
        compound->type = AST_FUNC_DEF;
        compound->value = parser_parse_block(parser);
    }

    return compound;
}

AST *parser_parse_int(Parser *parser)
{
    //printf("Called");
    int value = atoi(parser->token->value);
    printf("\n%d\n",value);
    parser_eat(parser, TK_INT);

    AST *ast = init_ast(AST_INT);
    ast->intValue = value;

    return ast;
}

AST *parser_parse_exp(Parser *parser)
{
    switch(parser->token->type)
    {
        case TK_ID:     return parser_parse_id(parser);
        case TK_LPAREN: return parser_parse_list(parser);
        case TK_INT   : return parser_parse_int(parser);

        default:
             printf("[Parser] :: Unidentified Token %s\n",token_to_string(parser->token)), exit(1);
    }
}

AST *parser_parse_compound(Parser *parser)
{
    AST *compound = init_ast(AST_COMPOUND);

    while(parser->token->type != TK_EOF)
    {
        list_push(compound->children, parser_parse_exp(parser));
    }
    return compound;
}