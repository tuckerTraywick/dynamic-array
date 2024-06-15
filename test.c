#include <stdio.h>
#include "list.h"

typedef int *ListInt;

int main(void) {
    ListInt list = ListCreate(10, sizeof *list);
    ListDestroy(list);
    return 0;
}
