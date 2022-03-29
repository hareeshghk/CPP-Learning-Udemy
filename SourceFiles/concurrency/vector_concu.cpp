#include <iostream>
#include <vector>
#include <future>
#include <mutex>

using namespace std;

vector<int> par_vec;
mutex m;

void AddValtoVec(int n) {
    for (int i = 0; i < n ;i++) {
        lock_guard<mutex> lck(m);
        par_vec.push_back(i);
    }
}
int main() {
    auto result1 = async(AddValtoVec, 1000);
    auto result2 = async(AddValtoVec, 1000);

    result1.get();
    result2.get();
    cout << "vec size: " << par_vec.size() << endl;
    return 0;
}