#include <iostream>

union Test {
    int x;
    char ch;
    double d;
    // we can intialize only one variable in constructor.
    Test():ch{'a'}{
        std::cout << "Test()" << std::endl;
    }
    ~Test(){
        std::cout << "~Test()" << std::endl;
    }
};

int main(){
    using namespace std;
    cout << "size of Test: " << sizeof(Test) << endl;
    Test t;
    cout << t.ch << endl;
    cout << t.x << endl;
    cout << t.d << endl;

    // by setting d other variable values will be garbaze.
    t.d = 100.567;
    cout << t.ch << endl;
    cout << t.x << endl;
    cout << t.d << endl;

    return 0;
}