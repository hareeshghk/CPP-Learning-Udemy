#include <iostream>
#include <thread>
#include <future>

using namespace std;

void printval(std::future<int> &p) {
    cout << "Waiting for value to be set"<< endl;
    cout << "Set value by main is " << p.get() << endl;
}

int main() {
    std::promise<int> p;
    auto f = p.get_future();

    std::packaged_task<void(future<int>&)> task(printval);
    auto f2 = task.get_future();
    thread t1(move(task), ref(f));
    t1.detach();

    this_thread::sleep_for(chrono::milliseconds(1000));
    p.set_value(100);
    f2.get();
    return 0;
}