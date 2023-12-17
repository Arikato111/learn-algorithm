#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "result.h"
#include "linkedlist.h"

int main() {
    linked arr = Linked();
    for(int i = 0; i < 100; i++) {
        arr.insert(&arr, rand() % 100);
    }
    arr.insert(&arr, 90);
    show(&arr);
    printf("--------find-------\n");
    for(int i = 0; i < 10; i++) {
        result fi = get(&arr, i);
        if(!fi.is_error)
            printf("arr[%d] = %d\n", i, fi.value);
        else printf("%d out of range\n", i);
    }
    return 0;
}