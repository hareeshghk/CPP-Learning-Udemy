#include <iostream>

void Add(int a, int b, int &result) {
    result = a + b;
}

void Factorial(int a, int &result) {
    result = 1;
    while (a != 0) {
        result *= a;
        a--;
    }
}

void swap(int &a, int &b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

int main() {
    int x{3}, y{4};
    int result{0};

    std::cout << result << std::endl;

    Add(x, y, result);

    std::cout << result << std::endl;

    Factorial(x, result);

    std::cout << result << std::endl;

    swap(x, y);

    std::cout << x << " " << y << std::endl;

    // initializing reference.
    int &result_ref{result};

    std::cout << "result_ref:" << result_ref << "\n";

    result = 15;

    std::cout << "result_ref:" << result_ref << "\n";

    result_ref = 20;

    std::cout << "result:" << result << "\n";
    return 0;
}