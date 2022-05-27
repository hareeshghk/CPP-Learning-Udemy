#include <iostream>
#include <thread>

using namespace std;

class semaphore {
    int maxcount;
    int curcount;
    mutex m;
    condition_variable cv;
public:
    semaphore(int parallel_reads) {
        maxcount = parallel_reads;
        curcount = parallel_reads;
    }

    void acquireSemaphore(thread::id tid) {
        unique_lock<mutex> ul(m);
        cv.wait(ul, [this, tid](){
            cout << "waiting for semaphore for thread: " << tid << endl;
            return curcount > 0;
        });
        curcount--;
    }

    void releaseSemaphore() {
        unique_lock<mutex> ul(m);
        ++curcount;
        cv.notify_one();
    }
};

void doer(shared_ptr<semaphore> &sem) {
    auto currenttid = this_thread::get_id();
    sem->acquireSemaphore(currenttid);
    // cout << "acquired lock in doer with thread id: " << currenttid << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));
    sem->releaseSemaphore();
}

int main() {
    auto sem = make_shared<semaphore>(1);

    thread t[15];
    for (int i  = 0; i<15; ++i) {
        t[i] = thread(doer, ref(sem));
    }

    for (int i  = 0; i<15; ++i) {
        t[i].join();
    }
    return 0;
}