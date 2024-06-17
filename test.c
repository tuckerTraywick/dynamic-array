#include <stdio.h>
#include "list.h"

typedef int *ListInt;

int main(void) {
    ListInt list = ListCreate(5, sizeof *list);
    printf("count = %zu\n", ListGetCount(list));
    printf("capacity = %zu\n", ListGetCapacity(list));
    
    for (int i = 0; i < 10; ++i) {
        list = ListPrepend(list, &i);
    }

    int item = 54;
    ListInsert(list, 3, &item);
    for (size_t i = 0; i < ListGetCount(list); ++i) {
        printf("list[%li] = %i\n", i, list[i]);
    }

    printf("count = %zu\n", ListGetCount(list));
    printf("capacity = %zu\n", ListGetCapacity(list));
    ListDestroy(list);
    return 0;
}
