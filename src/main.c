#include "include/kol.h"
#include "include/main.h"

#ifndef INCLUDED_STDIO_H
    #include <stdio.h>
    #define INCLUDED_STDIO_H
#endif

int main(int argc, char *argv[])
{
    if(argc<2)
    {
        printf("No input file Specified...\n");
        return 1;
    }

    return 0;
}