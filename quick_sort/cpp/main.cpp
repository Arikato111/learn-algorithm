#include <iostream>
#include <vector>
#include "sorting.h"

#define minlion 1000000;
#define ten_minlion 10000000;
#define hundred_million 100000000;
#define byte 256;


int ARR_LEN = minlion;

int main() {
  vector<int> arr(ARR_LEN, 0);
  for (int i = 0; i < ARR_LEN; i++) {
    arr[i] = rand() % 256;
  }

  quick_sort(arr);

  // for (int v : arr) {
    // cout << v << ", ";
  // }
  return 0;
}