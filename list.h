#ifndef LIST_H
#define LIST_H

#include <stddef.h>

void *ListCreate(size_t capacity, size_t elementSize);

void ListDestroy(void *list);

#endif // LIST_H
