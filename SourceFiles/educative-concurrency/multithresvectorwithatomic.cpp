#include <atomic>
#include <iostream>
#include <chrono>
#include <random>
#include <thread>

using namespace std;

const long long vec_len = 100000000;
const long long first = 25000000;
const long long second = 50000000;
const long long third = 75000000;
const long long fourth = 100000000;

void Summer(atomic<long long> &sum, const vector<int>&vals, long long start, long long end) {
    for (long long i = start; i < end; ++i) {
        sum.fetch_add(vals[i], std::memory_order_relaxed);
    }
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

    std::atomic<long long> sum = 0;
    const auto start_time = std::chrono::steady_clock::now();
    thread t1(Summer, ref(sum), cref(randomVals), 0, first);
    thread t2(Summer, ref(sum), cref(randomVals), first, second);
    thread t3(Summer, ref(sum), cref(randomVals), second, third);
    thread t4(Summer, ref(sum), cref(randomVals), third, fourth);
    t1.join();t2.join();t3.join();t4.join();

    const std::chrono::duration<double> dur = std::chrono::steady_clock::now() - start_time;
    cout << "Duration for sum: "<< dur.count() << " and sum is: " << sum << endl;
    return 0;
}