#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include"result.h"
#include "double_linkedlist.h"

int main(void) {
    doub_linkd arr = DoubLinkd();
    insert_many(&arr, (int[]){50, 20}, 2); 
    show(&arr);
    printf("arr length = %d\n", arr.head->next->prev->value);
    return 0;
}