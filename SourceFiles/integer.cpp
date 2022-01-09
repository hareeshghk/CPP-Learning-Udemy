#include <iostream>
#include "integer.h"

using namespace std;

Integer::Integer() {
    p_int = new int(0);
}

Integer::Integer(const int &value) {
    p_int = new int(value);
}

Integer::~Integer() {
    delete p_int;
}

int Integer::getValue() {
    return *p_int;
}

void Integer::setValue(const int &value) {
    *p_int = value;
}

Integer::Integer(const Integer &obj) {
    cout << "copy constructor invoked" << endl;
    p_int = new int(*obj.p_int);
}

int main() {
    Integer i1(10);
    cout << i1.getValue() << endl;

    // int *p = new int(5);
    //
    // this is shallow copy
    // int *p1 = p
    //
    // Deep copy
    // int *p2 = new int(*p);

    auto i2 = i1;

    Integer i3(i1);

    // const Integer i4(15);
    // cout << i4.getValue() << endl;

    return 0;
}