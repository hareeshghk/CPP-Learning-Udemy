#include <iostream>

// macros will have bugs when input is given as expressions.
// SQUARE(val +1) because macro works as text substitution (val+1*val+1)
#define SQUARE(x) x*x

// Function call will be expanded to body when its called because of
// inline key word. This will avoid overheard of jumping to this line num and
// putting details on stack.
// inline is just a request to complier and it may ignore request
// based on some conditions. check udemycourse.
inline int square(int x) {
    return x*x;
}

int main() {
    const int &x {5};
    int y {5};
    // Macro will fail.
    std::cout << SQUARE(x + 1) << std::endl;
    std::cout << square(x + 1) << std::endl;
    return 0;
}