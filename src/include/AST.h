#ifndef KOL_AST_H
    #define KOL_AST_H

    #include "list.h"

    typedef struct st_AST{

        enum enum_AST{
            AST_COMPOUND,
            AST_FUNC_DEF,
            AST_ASSIGNMENT,
            AST_DEF_TYPE,
            AST_VARIABLE,
            AST_INT,
            AST_SATATEMENT,
            AST_CALL,
            AST_NO_OPERATION,
        } type;

        List *children;
        char *name;
        int intValue;
        struct st_AST *value;
        int data_type;

    } AST;

    AST *init_ast(int type);
    
#endif