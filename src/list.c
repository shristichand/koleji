#include "include/list.h"

#ifndef INCLUDED_STDLIB_H
    #include <stdlib.h>
    #define INCLUDED_STDLIB_H
#endif

List *init_list(size_t item_size)
{
    List *list = (List *) calloc(1, sizeof(List));

    list->size = 0;
    list->item_size = item_size;
    list->items = 0;

    return list;
}

void list_push(List *list, void *item)
{
    list->size ++;

    if(!list->items)
        list->items = (void *) calloc(1, list->item_size);
    else
        list->items = (void *) realloc(list->items, (list->size * list->item_size));
    
    list->items[list->size-1] = item;
}