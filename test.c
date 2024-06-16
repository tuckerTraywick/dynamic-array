#include <stdio.h>
#include "list.h"

typedef int *ListInt;

int main(void) {
    ListInt list = ListCreate(10, sizeof *list);
    ListSetCount(list, 2);
    printf("count = %zu\n", ListGetCount(list));
    printf("capacity = %zu\n", ListGetCapacity(list));
    
    for (int i = 0; i < 10; ++i) {
        list = ListAppend(list, &i);
    }
    for (size_t i = 0; i < 10; ++i) {
        printf("list[%li] = %i\n", i, list[i]);
    }

    printf("count = %zu\n", ListGetCount(list));
    printf("capacity = %zu\n", ListGetCapacity(list));
    ListDestroy(list);
    return 0;
}
