#include <iostream>

using namespace std;

int main() {
    // copy initialization.
    // This should be avoided for userdefined objects.
    int a1 = 1;
    char d1[8] = {"hello"};
    char d2[8] = {'h', 'e', 'l', 'l', 'o'}; // also called aggregate intialization

    // value initialization.
    int a2{5};
    int a3{}; // will be initalized with default value of type
    char d3[8]{"hello"};
    char d4[8]{'h', 'e', 'l', 'l', 'o'};

    // direct intialization.
    // intializing with values directly, its present in both
    // copy and value initialization.
    int a4{5};
    int a5(5);

    return 0;
}