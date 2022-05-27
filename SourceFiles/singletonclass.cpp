#include <iostream>
#include <mutex>
#include <string>
#include <thread>

using namespace std;

class singleton{
    static singleton *singleton_;
    static mutex mutex_;
protected:
    singleton(const string &value) {
        value_ = value;
    }
    string value_;
public:
    static singleton* GetInstance(const string &value);
    string getValue() const {
        return value_;
    }
    singleton(singleton &t) = delete;
    singleton operator =(const singleton &s) = delete;
};

singleton *singleton::singleton_ = nullptr;
mutex singleton::mutex_;

singleton *singleton::GetInstance(const string &value) {
    lock_guard<mutex> lock(mutex_);
    if (!singleton_) {
        singleton_ = new singleton(value);
    }
    return singleton_;
}

void ThredFoo() {
    // std::this_thread::sleep(chrono::milliseconds(1000));
    singleton* singleton = singleton::GetInstance("FOO");
    cout << singleton->getValue() << endl;
}

void ThredBar() {
    // std::this_thread::sleep(chrono::milliseconds(1000));
    singleton* singleton = singleton::GetInstance("BAR");
    cout << singleton->getValue() << endl;
}

int main() {
    thread t1(ThredBar);
    thread t2(ThredFoo);
    t1.join();
    t2.join();
    return 0;
}