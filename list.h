#ifndef LIST_H
#define LIST_H

#include <stddef.h>

#ifndef LIST_GROWTH_FACTOR
	#define LIST_GROWTH_FACTOR 2
#endif

void *ListCreate(size_t capacity, size_t elementSize);

void ListDestroy(void *list);

size_t ListGetCapacity(void *list);

void *ListSetCapacity(void *list, size_t capacity);

size_t ListGetCount(void *list);

void *ListSetCount(void *list, size_t count);

size_t ListGetElementSize(void *list);

void *ListInsert(void *list, size_t index, void *element);

void *ListAppend(void *list, void *element);

void *ListPrepend(void *list, void *element);

#endif // LIST_H
