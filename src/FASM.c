#include "include/FASM.h"

#ifndef INCLUDED_STDIO_H
    #include <stdio.h>
    #define INCLUDED_STDIO_H
#endif

#ifndef INCLUDED_STDLIB_H
    #include <stdlib.h>
    #define INCLUDED_STDLIB_H
#endif

#ifndef INCLUDED_STRING_H
    #include <string.h>
    #define INCLUDED_STRING_H
#endif

char *asm_f_compound(AST *ast)
{
    char *value = (char *) calloc(1,sizeof(char));

    for(size_t i = 0; i < ast->children->size; i++)
    {
        AST *child_ast = (AST *) ast->children->items[i];
        char *next_value = asm_f(child_ast);
        value = realloc(value, (strlen(next_value) + 1) * sizeof(char));
        strcat(value,next_value);
    }

    return value;
}
char *asm_f_assignment(AST *ast)
{
    return "CALLED ASSIGNMENT\n";
}
char *asm_f_variable(AST *ast)
{
    return "CALLED VARIABLE\n";
}
char *asm_f_int(AST *ast)
{
    return "CALLED INTEGER\n";
}
char *asm_f_call(AST *ast)
{
    return "FUNCTION CALL\n";
}

char *asm_f(AST *ast)
{
    char *value      = (char *) calloc(1,sizeof(char));
    char *next_value = 0;

    switch(ast->type)
    {
        case AST_COMPOUND:   next_value = asm_f_compound  (ast); break;
        case AST_ASSIGNMENT: next_value = asm_f_assignment(ast); break;
        case AST_VARIABLE:   next_value = asm_f_variable  (ast); break;
        case AST_INT:        next_value = asm_f_int       (ast); break;
        case AST_CALL:       next_value = asm_f_call      (ast); break;

        default: {
            printf("[FASM] :: No Frontend for AST of type %s.\n",ast->name);
            exit(1);
        }; 
    }

    value = realloc(value, (strlen(next_value) + 1) * sizeof(char) );
    strcat(value, next_value);

    return value;
}