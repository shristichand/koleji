#include "include/type.h"

#ifndef INCLUDED_STDIO_H
    #include <stdio.h>
    #define INCLUDED_STDIO_H
#endif

#ifndef INCLUDED_STRING_H
    #include <string.h>
    #define INCLUDED_STRING_H
#endif

int typeName_to_int(char *typeName)
{
    int t = 0;
    size_t len = strlen(typeName);

    for(unsigned int i = 0;i < len;i++)
        t += typeName[i];

    return t;
}