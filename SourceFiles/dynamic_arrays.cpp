#include <iostream>


int main() {
    std::unique_ptr<int[]> p{new int[5]{1,2,3,4,5}};
    p[0] = 15;
    std::cout << p[0] << std::endl;
    return 0;
}