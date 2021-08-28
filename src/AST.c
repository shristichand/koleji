#include "include/AST.h"

#ifndef INCLUDED_STDLIB_H
    #include <stdlib.h>
    #define INCLUDED_STDLIB_H
#endif

AST *init_ast(int type)
{
    AST *ast = (AST *) calloc(1, sizeof(AST));

    ast->type = type;

    if(type == AST_COMPOUND)
        ast->children = init_list(sizeof(AST *));

    return ast;
}