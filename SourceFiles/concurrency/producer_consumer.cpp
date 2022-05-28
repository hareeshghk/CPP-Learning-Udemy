#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

using namespace std;

class thread_safe_queue {
    queue<int> q;
    mutex m;
    condition_variable pushcv, popcv;
    int capacity;
public:
    thread_safe_queue(int c) {
        this->capacity = c;
    }

    void push(int element) {
        unique_lock<mutex> ul(m);
        pushcv.wait(ul, [this](){return q.size() < capacity;});
        q.push(element);
        popcv.notify_one();
    }

    int pop() {
        unique_lock<mutex> ul(m);
        popcv.wait(ul, [this](){return q.size() != 0;});
        int val = q.front();
        q.pop();
        pushcv.notify_one();
        return val;
    }
};

void Producer(thread_safe_queue &th, int offset) {
    for (int i = 0; i < 5; ++i) {
        th.push(offset+i);
        this_thread::sleep_for(chrono::seconds(1));
    }
}

void Consumer(thread_safe_queue &th) {
    for (int i = 0; i < 5; ++i) {
        cout << th.pop() << endl;
    }
}

int main() {
    vector<thread> producers(5), consumers(5);
    thread_safe_queue th(5);
    for (int i = 0; i < 5; ++i) {
        producers[i] = thread(Producer, ref(th), i*100);
    }

    for (int i = 0; i < 5; ++i) {
        consumers[i] = thread(Consumer, ref(th));
    }

    for (int i = 0; i < 5; ++i) {
        producers[i].join();
        consumers[i].join();
    }
    return 0;
}