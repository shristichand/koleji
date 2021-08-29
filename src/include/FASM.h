#ifndef KOL_FASM_H
    #define KOL_FASM_H

    #include "AST.h"

    char *asm_f_compound  (AST *ast);
    char *asm_f_assignment(AST *ast);
    char *asm_f_variable  (AST *ast);
    char *asm_f_int       (AST *ast);
    char *asm_f_call      (AST *ast);
    char *asm_f           (AST *ast);

#endif