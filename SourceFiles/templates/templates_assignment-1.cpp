#include <iostream>

template<typename T>
T Add(T x, T y) {
    return x + y;
}

template<typename T>
T ArraySum(T *pArr, T arrSize) {
    T sum = 0;
    for (T i = 0; i < arrSize; i++) {
        sum += pArr[i];
    }
    return sum;
}

template<typename T>
T Max(T *pArr, T arrSize) {
    T maxVal = pArr[0];
    for (T i = 1; i< arrSize; ++i) {
        maxVal = (pArr[i]>maxVal?pArr[i]:maxVal);
    }
    return maxVal;
}

template<typename T>
std::pair<T, T> MinMax(T *pArr, T arrSize) {
    T minVal = pArr[0];
    T maxVal = pArr[0];

    for (T i = 1; i< arrSize; ++i) {
        minVal = (pArr[i] < minVal?pArr[i]:minVal);
        maxVal = (pArr[i] > maxVal?pArr[i]:maxVal);
    }
    return std::make_pair(minVal, maxVal);
}

using namespace std;

int main() {
    auto arr = new int[10]{1,2,3,4,5,6,7,8,9,10};
    cout << Add(3,5) << endl;
    cout << ArraySum(arr, 10) << endl;
    cout << Max(arr, 10) << endl;
    auto x = MinMax(arr, 10);
    cout << x.first << " " << x.second << endl;
    delete []arr;
    return 0;
}