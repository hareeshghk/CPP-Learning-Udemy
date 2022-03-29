#include <atomic>
// #include <mutex>
#include <thread>
#include <iostream>

using namespace std;

class spinlock {
    std::atomic_flag f;
public:
    spinlock() : f(false) {
    }
    void lock() {
        while (f.test_and_set(std::memory_order_acquire));
    }

    void unlock() {
        f.clear(std::memory_order_release);
    }
};

spinlock s;

void func() {
    s.lock();
    cout << "In critical secion for thread: " << std::this_thread::get_id() << endl;
    s.unlock();
}

int main() {
    thread t1(func);
    thread t2(func);
    t1.join();t2.join();
    return 0;
}