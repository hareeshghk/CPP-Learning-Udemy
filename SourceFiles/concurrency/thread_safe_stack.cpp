#include <iostream>
#include <thread>
#include <mutex>
#include <stack>

using namespace std;

mutex mt;

template<typename T>
class MyStack {
    stack<T> st;
    mutex m;
public:
    // MyStack();
    void push(const T &val) {
        lock_guard<mutex> t(m);
        st.push(val);
        cout << "Pushing val: " << val << " Size is " << st.size() << endl;
    }

    bool pop() {
        lock_guard<mutex> t(m);
        bool pop_success = false;
        if (!st.empty()) {
            cout << "Popping element: " << st.top() << endl;
            st.pop();
            pop_success = true;
        }
        return pop_success;
    }

    T top() {
        lock_guard<mutex> t(m);
        return st.top();
    }

    bool empty() {
        lock_guard<mutex> t(m);
        return st.empty();
    }

    int size() {
        lock_guard<mutex> t(m);
        return st.size();
    }
};

void push10numbers(MyStack<int> &st) {
    for (int i = 0; i < 100; ++i) {
        st.push(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void pop10numbers(MyStack<int> &st) {
    for (int i = 0; i < 100; ++i) {
        st.pop();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

int main() {
    MyStack<int> st;
    thread t1(push10numbers, ref(st));
    thread t2(pop10numbers, ref(st));
    t1.join();
    t2.join();
    cout << "Size at the end: " << st.size() << endl;
    return 0;
}