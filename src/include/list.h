#ifndef KOL_LIST_H
    #define KOL_LIST_H

    #ifndef INCLUDED_STDIO_H
        #include <stdio.h>
        #define INCLUDED_STDIO_H
    #endif

    typedef struct st_List{

        void **items;
        size_t size;
        size_t item_size;

    } List;
    
    List *init_list(size_t item_size);

    void list_push(List *list, void *item);

#endif