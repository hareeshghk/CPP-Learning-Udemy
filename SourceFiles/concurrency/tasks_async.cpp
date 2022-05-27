#include <iostream>
#include <thread>
#include <future>
#include <chrono>

using namespace std;

int sum(int x, int y) {
    return x+y;
}

int main() {
    std::packaged_task<int(int,int)> task1(sum);
    auto f1 = task1.get_future();
    // we can call task directlyt as task1(7,8) and val wil be in future.
    thread t1(move(task1), 5, 7);
    t1.detach();
    cout << "Sum: " << f1.get() << endl;

    chrono::time_point s = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::milliseconds>(s.time_since_epoch()).count() << endl;
    cout << chrono::duration_cast<chrono::milliseconds>(s.time_since_epoch()).count() + 10 << endl;
    return 0;
}