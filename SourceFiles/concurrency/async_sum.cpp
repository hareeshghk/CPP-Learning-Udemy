#include <iostream>
#include <future>

using namespace std;

int sum(int x, int y) {
    return x+y;
}

void otherfunc() {
    cout << "Called other func" << endl;
}

int main() {
    int x= 3, y=4;
    // auto f1 = async(sum, x, y);
    // launch policy deferred means it gets run on main thread when
    // future.get called.
    std::future<int> f1 = async(std::launch::async, sum, x, y);
    cout << f1.get() << endl;
    return 0;
}