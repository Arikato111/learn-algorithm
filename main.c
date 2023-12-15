#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "result.h"
#include "linkedlist.h"

int main() {
    struct linked arr = Linked();
    arr.insert_many(&arr, (int[]){0, 10, 20, 30, 40, 50, 60}, 7);
    arr.show(&arr);
    printf("-----\n");
    printf("len = %d\n", arr.len(&arr));
    return 0;
}