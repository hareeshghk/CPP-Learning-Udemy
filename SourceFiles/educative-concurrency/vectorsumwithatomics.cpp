#include <atomic>
#include <iostream>
#include <chrono>
#include <random>

using namespace std;

const long long vec_len = 1000000000;

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

    cout << "Is sum lock free: " << sum.is_lock_free() << endl;

    auto start_time = std::chrono::steady_clock::now();
    // normal summatiom.
    for (long long i = 0; i < vec_len; ++i) {
        sum += randomVals[i];
    }
    std::chrono::duration<double> dur = std::chrono::steady_clock::now() - start_time;
    cout << "Sum: " << sum << " And it took time: "  << dur.count() << endl;

    start_time = std::chrono::steady_clock::now();
    sum = 0;
    // using fetch add.
    for (long long i = 0; i < vec_len; ++i) {
        sum.fetch_add(randomVals[i]);
    }
    dur = std::chrono::steady_clock::now() - start_time;
    cout << "Sum: " << sum << " And it took time: "  << dur.count() << endl;
    return 0;
}