#include <vector>

using namespace std;

void quick_sort_node(vector<int> &arr, int st, int ed, vector<int> &worker) {
  int k = st - 1;
  int tmp;
  for (int i = st; i < ed; i++) {
    if (arr[i] <= arr[ed - 1]) {
      k += 1;
      tmp = arr[i];
      arr[i] = arr[k];
      arr[k] = tmp;
    }
  }
  int len2 = ed - k - 1;

  if (k > 1) {
    worker.push_back(st);
    worker.push_back(k);
  }
  if (len2 > 1) {
    worker.push_back(k + 1);
    worker.push_back(ed);
  }
}

void quick_sort_linear(vector<int> &arr, vector<int> &worker) {
  while (worker.size()) {
    int w2 = worker[worker.size() - 1];
    worker.pop_back();
    int w1 = worker[worker.size() - 1];
    worker.pop_back();
    if (w1 == w2) continue;
    quick_sort_node(arr, w1, w2, worker);
  }
}

void quick_sort(vector<int> &arr) {
  vector<int> worker;
  worker.push_back(0);
  worker.push_back(arr.size());
  quick_sort_linear(arr, worker);
}
