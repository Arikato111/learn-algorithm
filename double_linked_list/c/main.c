#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include"result.h"
#include "double_linkedlist.h"

int main(void) {
    doub_linkd arr = DoubLinkd();
    arr.insert_many(&arr, (int[]){0 ,10, 20, 30, 40, 50, 60}, 7); 
    arr.show(&arr);
    result r =arr.pop_index(&arr, 3);
    printf("---------\n");
    arr.show(&arr);
    printf("\tvalue is %d\n", r.value);
    printf("\tlast = %d\n", arr.last->value);
    return 0;
}