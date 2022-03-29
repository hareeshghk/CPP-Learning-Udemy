#include <iostream>
#include <chrono>
#include <random>
#include <mutex>

using namespace std;

constexpr long long vec_len = 100000000;

int main() {
    vector<int> randomVals;
    randomVals.resize(vec_len);

    std::random_device seed;
    std::mt19937 engine(seed());
    std::uniform_int_distribution<> uniformDist(1, 10);

    for (long long i = 0; i < vec_len; ++i) {
        randomVals[i] = uniformDist(engine);
    }

    const auto start_time = std::chrono::steady_clock::now();

    std::mutex mymutex;

    long long s = 0;
    for (long long i =0; i < vec_len; ++i) {
        // unnecessary locking can cause lot of time.
        // In experiment it took 5 times more time.
        // std::lock_guard<mutex> lck(mymutex);
        s += randomVals[i];
    }

    // Instead of for loop I can use stl accumualate
    // cout << accumulate(randomVals.begin(), randomVals.end(), 0) << endl;

    const std::chrono::duration<double> dur =
        std::chrono::steady_clock::now() - start_time;

    cout << "Time taken for summation: " << dur.count() << endl;
    cout << "result: " << s << endl;
    return 0;
}