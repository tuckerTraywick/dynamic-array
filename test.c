#include <stdio.h>
#include "list.h"

typedef int *ListInt;

int main(void) {
    ListInt list = ListCreate(5, sizeof *list);
    printf("count = %zu\n", ListGetCount(list));
    printf("capacity = %zu\n\n", ListGetCapacity(list));
    
    for (int i = 0; i < 10; ++i) {
        list = ListPushBack(list, &i);
    }

    int element = 0;
    list = ListPopFront(list, 1, &element);
    printf("popped %i\n", element);
    for (size_t i = 0; i < ListGetCount(list); ++i) {
        printf("list[%li] = %i\n", i, list[i]);
    }

    printf("\ncount = %zu\n", ListGetCount(list));
    printf("capacity = %zu\n", ListGetCapacity(list));
    ListDestroy(list);
    return 0;
}
