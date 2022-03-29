#include <iostream>

using namespace std;

// simar to int sum(int x, int y) noexcept(true) {
// this means it can't throw exceptions so compiler can avoid creating stack
// unwinding code.
int sum(int x, int y) noexcept {
    return x+y;
}

class Test {
    int val_;
public:
    Test(int val):val_(val) {
        cout << "Test()" << val << endl;
        if (val==2) {
            // non standard exception.
            //   throw "hello";
            throw std::runtime_error("testing");
        }
    }
    ~Test() {
        cout << "~Test()" << val_<< endl;
    }
};

void callfun() {
    Test t1(1);
    Test t(2);
}
int main() {
    Test t2(3);
    try {
        callfun();
    } catch (std::exception &ex) {
        cout << ex.what() << endl;
    } catch(...) {
        cout << "non standard exception" << endl;
    }
    return 0;
}