#include <iostream>

void PrintVal(const int *ptr) {
    using namespace std;
    if (ptr != nullptr)
        cout << *ptr << endl;
    // ptr declared as const so this can't happen.
    // *ptr = 500;
}

void PrintRef(const int &ptr) {
    using namespace std;
    cout << ptr << endl;
}

int main() {
    using namespace std;
    
    int x {5};

    const int y {x};

    cout << y << endl;

    // not possible since y is const int.
    // y = 10;
    
    // this wont change y as its not a reference.
    x = 10;

    cout << y << endl;


    //pointer with const val.
    const int *a {&y};

    cout << *a << endl;

    a = &x;

    cout << *a << endl;

    //const pointer with const val.
    const int *const b {&y};

    cout << *b << endl;

    // not possible since pointer is also const.
    // b = &y;

    cout << *b << endl;

    PrintVal(&x);

    cout << x << endl;

    int z = 25;
    // send z by refernce and dont allow to change inside func.
    // for that to happens send to func which accepts const and ref.
    PrintRef(z);

    // not possible since ref should be initialized with l value unless it is const.
    // int &w{30};

    return 0;
}