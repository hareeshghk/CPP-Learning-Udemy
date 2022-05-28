#include <iostream>
#include <mutex>
#include <condition_variable>
#include <shared_mutex>
#include <thread>

using namespace std;

int main () {
    // mutex
    mutex m;
    // lock is taken and its unique lock
    unique_lock<mutex> ul(m);

    // shared mutex can be used for read and write lock.
    shared_mutex m2;
    shared_lock<shared_mutex> sl(m2);
    shared_lock<shared_mutex> sl2(m2);
    // unique_lock<shared_mutex> ul2(m2);

    this_thread::sleep_for(chrono::milliseconds(1000));

    chrono::time_point<chrono::system_clock> current_time = chrono::system_clock::now();
    cout << current_time.time_since_epoch().count() << endl;
    this_thread::sleep_for(chrono::seconds(2));
    chrono::duration<double> d = chrono::system_clock::now() - current_time;
    cout << d.count() << endl;
    return 0;
}