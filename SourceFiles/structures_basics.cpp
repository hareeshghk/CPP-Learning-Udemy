#include <iostream>

// struct is same as class in c++
// only diffrence is struct values are public by default while
// class objects are private by default.
struct Point {
    int x;
    int y;
};


void DrawLine(const Point &start, const Point &end) {
    using namespace std;
    cout << start.x << start.y << endl;
    cout << end.x << end.y << endl;
    return;
}

int main() {
    Point a,b;
    a.x = 5;
    a.y = 6;

    b.x = b.y = 7;

    DrawLine(a, b);
    return 0;
}
