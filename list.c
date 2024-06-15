#include <stddef.h>
#include <stdlib.h>
#include "list.h"

struct List {
    size_t capacity;
    size_t count;
    size_t elementSize;
    char elements[];
};

void *ListCreate(size_t capacity, size_t elementSize) {
    struct List *list = malloc(sizeof *list + capacity*elementSize);
    return &list->elements;
}

void ListDestroy(void *list) {
    free((char*)list - sizeof (struct List));
}
