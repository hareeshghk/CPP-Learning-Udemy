#include <iostream>

using namespace std;

// enum Color{RED, GREEN, YELLOW};
// the above one is global, to make it scoped use below one.
enum class Color1 {RED, GREEN, YELLOW}; // default are intergers and allocates 0,1,2 respectively.

enum class Color2 : char{RED = 'r', GREEN = 'g', YELLOW = 'y'};

enum class Color3 : long{RED = 1000, GREEN, YELLOW}; // next values will be 1001, 1002.


void Print(Color1 color) {
    if (color == Color1::RED) {
        cout << "RED" << endl;
    } else if (color == Color1::GREEN) {
        cout << "GREEN" << endl;
    } else if (color == Color1::YELLOW) {
        cout << "YELLOW" << endl;
    } else {
        cout << "Unknown" << endl;
    }
    return;
}

int main() {
    Color1 c1 {Color1::RED};
    Color2 c2 = static_cast<Color2>('y');
    Color3 c3 = static_cast<Color3>(1001);
    auto c4 {static_cast<Color1>(5)};
    Print(c1);
    Print(c4);
    return 0;
}