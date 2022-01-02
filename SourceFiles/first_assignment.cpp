#include <iostream>
#include "first_assignment.h"

namespace fiasgn {
int Add(int *a, int *b) {
    return *a + *b;
}

void AddVal(int *a, int *b, int *result) {
    *result = *a + *b;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Factorial(int *a, int *result) {
    *result = 1;
    while (*a != 0) {
        *result *= *a;
        *a--;
    }
}
}