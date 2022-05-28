#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <future>
#include <queue>
#include <memory>

using namespace std;

mutex mtx;
class thread_safe_queue {
    queue<int> q;
    mutex m;
    condition_variable pushcv, popcv;
    int capacity;
    queue<shared_ptr<promise<bool>>> waitingpops, waitingpushes;
public:
    thread_safe_queue(int c) {
        this->capacity = c;
    }

    shared_ptr<future<bool>> push(int element) {
        unique_lock<mutex> ul(m);
        shared_ptr<future<bool>> f = nullptr;
        if (q.size() < capacity) {
            q.push(element);
            if (waitingpops.size() > 0) {
                auto p =  waitingpops.front();
                waitingpops.pop();
                p->set_value(true);
            }
        } else {
            auto curpromis = make_shared<promise<bool>>();
            f = make_shared<future<bool>>(curpromis->get_future());
            waitingpushes.push(curpromis);
        }
        return f;
    }

    pair<int, shared_ptr<future<bool>>> pop() {
        unique_lock<mutex> ul(m);
        shared_ptr<future<bool>> f = nullptr;
        if (q.size() != 0) {
            int val = q.front();
            q.pop();
            if (waitingpushes.size() > 0) {
                auto p =  waitingpushes.front();
                waitingpushes.pop();
                p->set_value(true);
            }
            return make_pair(val, f);
        } else {
            auto curpromis = make_shared<promise<bool>>();
            f = make_shared<future<bool>>(curpromis->get_future());
            waitingpops.push(curpromis);
            return make_pair(-1, f);
        }
    }
};

void Producer(thread_safe_queue &th, int offset) {
    for (int i = 0; i < 5; ++i) {
        shared_ptr<future<bool>> f;
        do {
            f = th.push(offset+i);
        } while (f != nullptr && f->get());
        this_thread::sleep_for(chrono::milliseconds(2000));
    }
}

void Consumer(thread_safe_queue &th) {
    for (int i = 0; i < 5; ++i) {
        shared_ptr<future<bool>> f;
        int val;
        do {
            tie(val, f) = th.pop();
        } while (f != nullptr && f->get());
        unique_lock<mutex> ul(mtx);
        cout << "consumer " << this_thread::get_id() << " " << val << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
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