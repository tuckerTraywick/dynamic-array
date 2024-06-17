#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

#define max(a, b) ((a) >= (b)) ? (a) : (b)

#define getList(elements) ((struct List*)(elements) - 1)

struct List {
    size_t capacity;
    size_t count;
    size_t elementSize;
	char elements[];
};

static void *getElement(struct List *list, size_t index) {
    return (void*)(list->elements + index*list->elementSize);
}

static void setElement(struct List *list, size_t index, void *value) {
    memcpy(list->elements + index*list->elementSize, value, list->elementSize);
}

void *ListCreate(size_t capacity, size_t elementSize) {
    struct List *list = malloc(sizeof *list + capacity*elementSize);
    *list = (struct List){
        .capacity = capacity,
        .count = 0,
        .elementSize = elementSize,
    };
    return &list->elements;
}

void ListDestroy(void *list) {
    free(getList(list));
}

size_t ListGetCapacity(void *list) {
    return getList(list)->capacity;
}

void *ListSetCapacity(void *list, size_t capacity) {
    struct List *l = getList(list);
    if (capacity >= l->capacity*LIST_GROWTH_FACTOR) {
        l->capacity = capacity;
        l = realloc(l, sizeof *l + l->capacity*l->elementSize);
    } else if (l->capacity > l->count && capacity <= l->capacity/LIST_GROWTH_FACTOR) {
        l->capacity = max(l->count, capacity);
        l = realloc(l, sizeof *l + l->capacity*l->elementSize);
    }
    return l + 1;
}

size_t ListGetCount(void *list) {
    return getList(list)->count;
}

void *ListSetCount(void *list, size_t count) {
    list = ListSetCapacity(list, count);
    struct List *l = getList(list);
    l->count = count;
    return list;
}

size_t ListGetElementSize(void *list) {
    return getList(list)->elementSize;
}

void *ListInsert(void *list, size_t index, void *element) {
    struct List *l = getList(list);
    if (l->count == l->capacity) {
        l->capacity *= LIST_GROWTH_FACTOR;
        l = realloc(l, sizeof *l + l->capacity*l->elementSize);
    }

    if (index < l->count) {
        memmove(
            l->elements + (index + 1)*l->elementSize,
            l->elements + index*l->elementSize,
            l->count*l->elementSize
        );
    }
    setElement(l, index, element);
    ++l->count;
    return l + 1;
}

void *ListAppend(void *list, void *element) {
    return ListInsert(list, ListGetCount(list), element);
}

void *ListPrepend(void *list, void *element) {
    return ListInsert(list, 0, element);
}

#undef min
