#include <iostream>

template<typename T>
T Max(T a, T b) {
    return a>b?a:b;
}

int main() {
    std::cout << Max(3,4) << std::endl;
    std::cout << Max(5.4, 7.9) << std::endl;
    return 0;
}