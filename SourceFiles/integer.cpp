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

int Integer::getValue() const{
    return *p_int;
}

void Integer::setValue(const int &value) {
    *p_int = value;
}

Integer::Integer(const Integer &obj) {
    cout << "copy constructor invoked" << endl;
    p_int = new int(*obj.p_int);
}

Integer Integer::operator+ (const Integer& obj) const {
    Integer temp;
    *temp.p_int = *this->p_int + *obj.p_int;
    return temp;
}

// global sum operator.
// Integer operator+ (Integer a, Integer b) {
//     cout << "in global sum operator" << endl;
//     return Integer(a.getValue() + b.getValue());
// }

Integer & Integer::operator= (const Integer& obj) {
    cout << "In assignment operator" << endl;
    // if is for handling self assignment case.
    if (this != &obj) {
        delete p_int;
        p_int = new int(obj.getValue());
    }
    return *this;
}

Integer & Integer::operator++ () {
    ++(*p_int);
    cout << "in pre increment operator" << endl;
    return *this;
}

Integer Integer::operator++ (int) {
    Integer temp(*this);
    ++(*p_int);
    cout << "in post increment operator" << endl;
    return temp;
}

bool Integer::operator== (const Integer &obj) const {
    cout << "In comparison operator" << endl;
    return (this->getValue() == obj.getValue());
}

Integer::Integer(Integer &&obj) {
    cout << "move constructor" << endl;
    p_int = obj.p_int;
    obj.p_int = nullptr;
}

Integer & Integer::operator= (Integer &&obj) {
    cout << "move operator" << endl;
    if (this != &obj) {
        delete p_int;
        p_int = obj.p_int;
        obj.p_int = nullptr;
    }
    return *this;
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

    cout << "starting overload" << endl;

    Integer ov1(5), ov2(6);
    
    Integer ov3 = ov1 + ov2;

    cout << (++ov3).getValue() << endl;

    cout << (ov3++).getValue() << endl;

    cout << ov3.getValue() << endl;

    cout << (ov3 == ov1) << endl;

    ov3 = ov1;

    cout << (ov3 == ov1) << endl;

    auto ov4(move(ov2));
    cout << ov4.getValue() << endl;

    ov4 = move(ov1);
    cout << ov4.getValue() << endl;

    return 0;
}