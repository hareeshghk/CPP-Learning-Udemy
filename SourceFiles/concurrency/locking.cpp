#include <iostream>
#include <mutex>
#include <vector>
#include <thread>

using namespace std;

int result;
mutex m;

void fillVector(int count) {
    for (int i = 0; i < count; ++i) {
        lock_guard<mutex> lck(m);
        // m.lock();
        result = result + 1;
        // m.unlock();
    }
}

int main() {
    thread t1(fillVector, 10000);
    thread t2(fillVector, 10000);

    if (t1.joinable()) t1.join();
    if(t2.joinable()) t2.join();

    cout << "Actual size: " << result << " Expected size: " << 20000 << endl;
    return 0;
}