// This is a single line comment

/*
This is a multi line
comment
*/

// for perform input/output
#include <iostream>

// #include "first_assignment.h"

using namespace std;

// macros
#define LIMIT 5
#define AREA(l, b) (l*b)

#ifdef LIMIT
  #undef LIMIT
  #define LIMIT 50
#endif

#if LIMIT > 50
  #undef LIMIT
  #define LIMIT 50
#elif LIMIT < 50
  #undef LIMIT
  #define LIMIT 100
#else
  #undef LIMIT
  #define LIMIT 1000
#endif

// #line 10 "testing"

// #ifdef LIMIT
//   #error LIMIT not found!!!
// #endif

// programs to be run before and after main is called.
void func1();
void func2();

void __attribute__((constructor)) func1();
void __attribute__((destructor)) func2();

void func1() {
    cout << "Inside func1()" << endl;
}
  
void func2() {
    cout << "Inside func2()" << endl;
}

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
        *a = *a-1;
    }
}
}

int main() {
  cout << "Hello c++" << endl;

  // cascading a operator
  cout << "helllo" << "world" << endl;

  cout << AREA(3,4) << " " << LIMIT << endl;

  int x{3}, y{4}, z{0};
  int *a=&x, *b=&y;

  cout << fiasgn::Add(a, b) << endl;

  int *result = &z;

  fiasgn::AddVal(a, b, result);

  cout << *result << endl;

  fiasgn::swap(a, b);

  cout << *a << " " << *b << endl;

  fiasgn::Factorial(a, result);

  cout << *result << endl;
  
  return 0;
}