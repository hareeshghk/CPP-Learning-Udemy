#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <chrono>

using namespace std;

condition_variable cv;
mutex m;
int totalDistance, distanceCovered;

void Driver() {
    cout << std::this_thread::get_id() << " Started Driving" << endl;
    while (distanceCovered < totalDistance) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        ++distanceCovered;
    }
    cout << std::this_thread::get_id() << " Driver: reached destination" << endl;
    // notify passenger.
    cv.notify_one();
    return;
}

void Passenger() {
    std::unique_lock<mutex> u1(m);
    cv.wait(u1, []{
        cout << std::this_thread::get_id() <<  " Passenger: Not yet Reached going to sleep" << endl;
        return distanceCovered == totalDistance;
        });
    cout << "Passenger: I am awake now" << endl;
    return;
}

int main() {
    totalDistance = 10;
    distanceCovered = 0;
    thread t1(Driver);
    thread t2(Passenger);
    if (t1.joinable()) t1.join();
    if (t2.joinable()) t2.join();
    return 0;
}