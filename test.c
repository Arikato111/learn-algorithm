#include <stdio.h>

struct person {
    int age;
    void (*show_name) ();
};

void show_name(int i,struct person *this) {
    printf("age = %d\n", this->age);
}

struct person Person() {
   struct person p; 
   p.show_name = &show_name;
   p.age = 10;
   return p;
}

int main() {
    struct person p =Person();
    p.show_name(10);
    return 0;
}