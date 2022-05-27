#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <vector>

using namespace std;

class ReadWriteLock {
    mutex m;
    condition_variable cv;
    int readers, writers;
public:
    ReadWriteLock() {
        readers = 0;
        writers = 0;
    }

    void acquire_read_lock() {
        unique_lock<mutex> ul(m);
        cv.wait(ul, [this](){return writers == 0;});
        ++readers;
    }

    void release_read_lock() {
        unique_lock<mutex> ul(m);
        --readers;
        if (readers == 0) cv.notify_all();
    }

    void acquire_write_lock() {
        unique_lock<mutex> ul(m);
        cv.wait(ul, [this]() {return readers == 0 && writers == 0;});
        ++writers;
    }

    void release_write_lock() {
        unique_lock<mutex> ul(m);
        --writers;
        cv.notify_all();
    }
};

ReadWriteLock rw;
vector<int> store;

void Producer() {
    for (int i = 0; i < 10; i++) {
        store.push_back(i);
        this_thread::sleep_for(chrono::milliseconds(2000));
    }
}

int main() {
    auto current_time = chrono::steady_clock::now();
    this_thread::sleep_for(chrono::seconds(5));
    auto diffrence_in_seconds = std::chrono::duration_cast<chrono::seconds>(chrono::steady_clock::now()-current_time);
    cout << diffrence_in_seconds.count() << endl;
    return 0;
}