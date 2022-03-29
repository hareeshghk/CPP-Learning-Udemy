#include <iostream>
#include <thread>

using namespace std;

class semaphore {
    int maxcount;
    int curcount;
public:
    semaphore(int parallel_reads) {
        maxcount = parallel_reads;
        curcount = parallel_reads;
    }

    void acquireSemaphore(thread::id tid) {
        while (curcount <= 0) {
            cout << "waiting for semaphore for thread: " << tid << endl;
            this_thread::sleep_for(chrono::milliseconds(10));
        }
        curcount--;
    }

    void releaseSemaphore() {
        curcount++;
    }
};

void doer(shared_ptr<semaphore> &sem) {
    auto currenttid = this_thread::get_id();
    sem->acquireSemaphore(currenttid);
    cout << "acquired lock in doer with thread id: " << currenttid << endl;
    this_thread::sleep_for(chrono::milliseconds(50));
    sem->releaseSemaphore();
}

int main() {
    auto sem = make_shared<semaphore>(3);

    thread t[15];
    for (int i  = 0; i<15; ++i) {
        t[i] = thread(doer, ref(sem));
    }

    for (int i  = 0; i<15; ++i) {
        t[i].join();
    }
    return 0;
}