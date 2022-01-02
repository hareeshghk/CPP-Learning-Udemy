#include <iostream>

void CreateWindow(const char *title, int length, int width = 30) {
    std::cout << "title: " << title << " length: " <<  length << " width: " << width << std::endl;
}

// Not possible since once defauly arg started for one then all coming next should also have def values.
// void CreateWindow(const char *title ="window", int length, int width = 30) {
//     std::cout << "title: " << title << " length: " <<  length << " width: " << width << std::endl;
// }

// This will result in ambiguious.
// void CreateWindow(int length) {
//     std::cout << "hello" << std::endl;
// }

int main() {
    CreateWindow("window1", 40);
    CreateWindow("window2", 40, 50);
    return 0;
}