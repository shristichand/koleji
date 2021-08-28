#include "include/io.h"

#ifndef INCLUDED_STDLIB_H
    #include <stdlib.h>
    #define INCLUDED_STDLIB_H
#endif

#ifndef INCLUDED_STDIO_H
    #include <stdio.h>
    #define INCLUDED_STDIO_H
#endif

#ifndef INCLUDED_STRING_H
    #include <string.h>
    #define INCLUDED_STRING_H
#endif

FILE *tryOpening(const char *fileName, char *fileMode)
{
    FILE *fp = fopen(fileName, fileMode);

    if( fp == NULL)
    {
        printf("Cannot open file '%s'",fileName);
        perror("Error :");
        printf("\nExiting...\n");
        exit(1);
    }

    return fp;
}

char *kol_read_file(const char* fileName)
{
    char *line = NULL;
    size_t len;
    ssize_t read;

    FILE *fp = tryOpening(fileName, "r");

    char *buffer = (char *) calloc(1, sizeof(char));
    buffer[0] = '\0';

    while(( read = getline(&line, &len , fp) )!= EOF )
    {
        buffer = (char *) realloc(buffer, (strlen(buffer) +  strlen(line) + 1) * sizeof(char));
        strcat(buffer, line);
    }

    fclose(fp);

    if(line)
        free(line);
    
    return buffer;
}