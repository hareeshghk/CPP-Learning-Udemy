#include <iostream>

int AddVal(int a, int b) {
    return a+b;
}

// To avoid name mangling use extern C.
extern "C" double AddVal(double a, double b) {
    std::cout << "in extern call" << std::endl;
    return a+b;
}

double AddVal(double a, double b, double c) {
    return a+b;
}

// Not possible to overload inside extern since nammagling avoided with extern c
// extern "C" {
// void AddnPrint(const int &a) {
//     std::cout << "a1:" << a << std::endl;
// }

// void AddnPrint(int &a) {
//     std::cout << "a2:" << a << std::endl;
// }
// }

// cannot overload functions distinguished by return type alone
// void AddVal(double a, double b) {
//     std::cout << a+b << std::endl;
// }

int main() {
    using namespace std;
    int x{4}, y{6};
    cout << AddVal(x, y) << endl;

    double u{1.234}, v{3.45678};
    cout << AddVal(u, v) << endl;

    // AddnPrint(x);

    return 0;
}