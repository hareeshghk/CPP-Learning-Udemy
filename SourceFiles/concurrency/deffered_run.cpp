#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

using namespace std;

class deffered_run {
    mutex m;
    condition_variable cv;
    int val =5;
public:
    void runAfter(int x, chrono::duration<chrono::seconds> d) {
        unique_lock<mutex> ul(m);
        cv.wait_for(ul, d, [this](){return val==4;});
        cout << val << endl;
    }
};

int main() {
    deffered_run df;
    thread(&deffered_run::runAfter, &df, 10, chrono::duration<chrono::seconds>(5s));
    return 0;
}