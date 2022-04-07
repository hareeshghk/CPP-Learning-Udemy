#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <memory>


using namespace std;

template<typename T>
class thread_safe_queue {
    queue<shared_ptr<T>> q;
    mutex m;
    condition_variable cv;
public:
    void push(T &val) {
        lock_guard<mutex> lg(m);
        q.push(make_shared<T>(val));
        cv.notify_one();
    }

    shared_ptr<T> pop() {
        lock_guard<mutex> lg(m);
        if (q.empty()) {
            return nullptr;
        }
        shared_ptr<T> res(q.front());
        q.pop();
        return res;
    }

    int size() {
        lock_guard<mutex> lg(m);
        return q.size();
    }

    bool empty() {
        lock_guard<mutex> lg(m);
        return q.empty();
    }

    shared_ptr<T> wait_pop() {
        unique_lock<mutex> ul(m);
        cv.wait(ul, [this] () {
            return !q.empty();
        });
        auto res(q.front());
        q.pop();
        return res;
    }
};

void Waitforpop(thread_safe_queue<int> &q) {
    auto val = q.wait_pop();
    cout << "wait popped val " << *(val.get()) << endl;
}

void pushVals(thread_safe_queue<int> &q) {
    for (int i = 0; i < 5; i++) {
        q.push(i);
        std::this_thread::sleep_for(chrono::milliseconds(1));
        auto val = q.pop();
        if (val == nullptr) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "Popped value : " << *(val.get()) << endl;
        }
    }
}

int main() {
    thread_safe_queue<int> q;
    thread waitpop(Waitforpop, ref(q));
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    thread pushval(pushVals, ref(q));
    waitpop.join();
    pushval.join();
    return 0;
}