#ifndef KOL_IO_H
    #define KOL_IO_H

    #ifndef INCLUDED_STDIO_H
        #include <stdio.h>
        #define INCLUDED_STDIO_H
    #endif

    FILE *tryOpening(const char *fileName, char *fileMode);

    char *kol_read_file(const char* fileName);
    
#endif