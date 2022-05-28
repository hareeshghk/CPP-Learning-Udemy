#include <iostream>
#include <future>
#include <memory>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

using namespace std;

template <typename T>
class thread_safe_queue {
    queue<T> q;
    mutex m;
public:
    int size() {
        unique_lock<mutex> ul(m);
        return q.size();
    }

    void enque(T element) {
        unique_lock<mutex> ul(m);
        q.push(element);
    }

    bool deque(T& f) {
        unique_lock<mutex> ul(m);
        if (q.size() == 0) return false;
        f = move(q.front());
        q.pop();
        return true;
    }
};

class ThreadPool {
    int num_threads;
    bool shutdown;
    vector<thread> worker_threads;
    thread_safe_queue<function<void()>> task_list;
    mutex m;
    condition_variable cv;
public:
    ThreadPool(int num_threads) {
        this->num_threads = num_threads;
        shutdown = false;
        worker_threads = vector<thread>(num_threads);
    }

    void init() {
        for (int i = 0; i < num_threads; ++i) {
            worker_threads[i] = thread(&ThreadPool::worker_func, this);
        }
    }

    template <typename T, typename ...Args>
    auto submit(T&& f, Args&& ...args) -> future<decltype(f(args...))> {

        // std::function<decltype(f(args...))()> func = std::bind(forward<T>(f), forward<Args>(args)...);
        std::function<decltype(f(args...))()> func = std::bind(f, args...);
        auto task1 = make_shared<packaged_task<decltype(f(args...))()>>(func);
        auto wrapper_func = [task1]() {
            (*task1)();
        };
        task_list.enque(wrapper_func);
        cv.notify_one();
        return task1->get_future();
    }

    void Shutdown() {
        shutdown = true;
        cv.notify_all();
        for (int i = 0; i < num_threads; ++i) {
            if (worker_threads[i].joinable()) worker_threads[i].join();
        }
    }

    void worker_func() {
        while (!shutdown) {
            function<void()> f;
            bool deque;
            {
                unique_lock<mutex> ul(m);
                // cv.wait(ul, [this](){return (task_list.size() > 0 || shutdown);});
                cv.wait_for(ul, chrono::seconds(10), [this](){return (task_list.size() > 0 || shutdown);});
                if (shutdown) break;
                deque = task_list.deque(f);
            }
            
            if (deque) {
                f();
            }
        }
    }
};

void first(string s) {
    this_thread::sleep_for(chrono::seconds(1));
    cout << "I am First " << s << endl;
}

void second() {
    this_thread::sleep_for(chrono::seconds(1));
    cout << "I am second" << endl;
}

void third() {
    this_thread::sleep_for(chrono::seconds(1));
    cout << "I am third" << endl;
}

void fourth() {
    this_thread::sleep_for(chrono::seconds(1));
    cout << "I am fourth" << endl;
}

int main() {
    ThreadPool pool(3);
    pool.init();
    pool.submit(first, "hello");
    pool.submit(second);
    pool.submit(third);
    auto f = pool.submit(fourth);
    f.get();
    pool.Shutdown();
    return 0;
}