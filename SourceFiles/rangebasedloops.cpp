#include <iostream>

int main() {
    using namespace std;
    auto list = {1, 2, 3, 4, 5};
    for (const auto & val : list) {
        cout << val << " " << "\n";
    }

    for (const auto &item : {1,2,3,4,5}) {
        cout << item << " ";
    }
    cout << endl;

    // psedo code on how range for loop works.
    auto &&range = list;
    auto start = begin(list);
    auto final = end(list);

    for (;start != final; ++start) {
        cout << *start << " ";
    }
    cout << endl;
    return 0;
}