#include <iostream>
#include "bst.h"

using namespace std;

int main () {
    BinarySTree bi;
    bi.insert(10);
    bi.insert(20);
    bi.insert(50);
    bi.insert(40);
    bi.insert(2);
    bi.insert(3);
    bi.print();
    return 0;
}