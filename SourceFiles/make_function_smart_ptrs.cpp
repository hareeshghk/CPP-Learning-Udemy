#include <iostream>

using namespace std;

class Point {
    int x,y;
public:
    Point(int a, int b) : x(a),y(b) {
    }

    void ShowPoint() {
        cout << "x: " << x << ", y: " << y << endl;
    }
};

int main() {
    // not needed of new.
    // std::unique_ptr<int> p {new int{5}};
    {
        auto p = std::make_unique<int>(5);

        auto p1 = std::make_unique<Point>(3,4);

        p1->ShowPoint();
    }

    {
        auto p = std::make_shared<int>(5);

        auto p1 = std::make_shared<Point>(3,4);

        p1->ShowPoint();
    }

    return 0;
}