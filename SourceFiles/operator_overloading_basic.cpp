//syntac for operator
// <ret> operator <#> (<arguments)
// ret is return type and # is the operator we want to overload
//

#include <iostream>

class Overload {
  int val_;
public:
  Overload(const int& t) {
      std::cout << "In constructor with t: " << t << std::endl;
      val_ = t;
  }
  int getVal() {
      return val_;
  }
  Overload operator + (const Overload &obj) const;
};

Overload Overload::operator+ (const Overload &obj) const {
    using namespace std;
    cout << "in overload sum operator" << endl;
    return Overload(this->val_ + obj.val_);
}

int main() {
    Overload obj1(4);
    Overload obj2(5);

    obj1 = obj1 + obj2;
    std::cout << "sum of objects: " << obj1.getVal() << std::endl;
    return 0;
}
