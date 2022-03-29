#include <iostream>
#include <vector>

using namespace std;

void myfunc(vector<int> &&arr) {
    for (int i=0;i<arr.size();i++) {
        cout << arr[i] << endl;
    }
    return;
}

int main() {
    vector arr {3,4,5,6};
    myfunc(move(arr));
    return 0;
}