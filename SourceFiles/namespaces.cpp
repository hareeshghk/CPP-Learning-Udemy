#include <iostream>

#include "namespaces.h"

// using namespace std;
// using std::cout;
// std::cout << "hello" << std::endl;

namespace Avg {
    float Calculate(const float &x, const float &y) {
        return (x + y)/2;
    }
} // namespace Avg

namespace Sum {
    float Calculate(const float &x, const float &y) {
        return x + y;
    }
} // namespace Sum

float Calculate(const float &x, const float &y) {
    return x * y;
}

int main() {
    using std::cout;
    using std::endl;

    cout << Calculate(3.6, 8.987) << endl;
    cout << Avg::Calculate(3.6, 8.987) << endl;
    cout << Sum::Calculate(3.6, 8.987) << endl;

    Print("At the end");
    return 0;
}