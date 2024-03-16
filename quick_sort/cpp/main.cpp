#include <iostream>
#include <vector>

#include "sorting.h"

#define minlion 1000000;
#define ten_minlion 10000000;
#define hundred_million 100000000;
#define byte 256;

int ARR_LEN = hundred_million;

int main() {
  vector<int> arr(ARR_LEN, 0);
  for (int i = 0; i < ARR_LEN; i++) {
    // เพิ่มช่วงการสุ่มข้อมูล เพื่อลดข้อมูลซ้ำ (ยิ่งมีข้อมูลซ้ำเยอะ ยิ่งทำให้เรียงได้ช้าลง)
    arr[i] = rand() % 4294967295;
  }

  quick_sort(arr);

  // for (int v : arr) {
  // cout << v << ", ";
  // }
  return 0;
}