#include <iostream>
#include <chrono>
#include <random>
#include <thread>
#include <future>

using namespace std;

const long long vec_len = 100000000;
const long long first = 25000000;
const long long second = 50000000;
const long long third = 75000000;
const long long fourth = 100000000;

void Summer(promise<long long> &&p, const vector<int>&vals, long long start, long long end) {
    long long localsum = 0;
    for (long long i = start; i < end; ++i) {
        localsum += vals[i];
    }
    p.set_value(localsum);
}

int main() {
    vector<int> randomVals;
    randomVals.resize(vec_len);

    std::random_device seed;
    std::mt19937 engine(seed());
    std::uniform_int_distribution<> uniformDist(1, 10);

    for (long long i = 0; i < vec_len; ++i) {
        randomVals[i] = uniformDist(engine);
    }

    long long sum = 0;

    std::promise<long long> p1,p2,p3,p4;

    std::future<long long> f1,f2,f3,f4;
    f1 = p1.get_future();
    f2 = p2.get_future();
    f3 = p3.get_future();
    f4 = p4.get_future();

    const auto start_time = std::chrono::steady_clock::now();
    thread t1(Summer, move(p1), cref(randomVals), 0, first);
    thread t2(Summer, move(p2), cref(randomVals), first, second);
    thread t3(Summer, move(p3), cref(randomVals), second, third);
    thread t4(Summer, move(p4), cref(randomVals), third, fourth);

    sum += f1.get() + f2.get()+f3.get()+f4.get();
    t1.join();t2.join();t3.join();t4.join();

    const std::chrono::duration<double> dur = std::chrono::steady_clock::now() - start_time;
    cout << "Duration for sum: "<< dur.count() << " and sum is: " << sum << endl;
    return 0;
}