#include <iostream>
#include <vector>
#include <future>
#include <mutex>
using namespace std;

const int minlength = 1000;

mutex m;
int parallelAccumulate(vector<int> &arr, int start, int end) {
    {
        lock_guard<mutex> lg(m);
        cout << "Current thread id "<< std::this_thread::get_id() << "With start: " << start << " and end: " << end << endl;
    }
    if (end-start+1 <= minlength) {
        int result = 0;
        for (int i = start; i <=end; ++i) {
            result += arr[i];
        }
        return result;
    }

    int mid = start + (end-start)/2;

    auto f1 = async(std::launch::any, parallelAccumulate, ref(arr), start, mid-1);
    int sum = parallelAccumulate(arr, mid, end);
    return sum + f1.get();
}

int main() {
    vector<int> arr(10000, 1);
    cout << parallelAccumulate(arr, 0, arr.size()-1) << endl;
}