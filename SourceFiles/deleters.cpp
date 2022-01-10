#include <iostream>
#include <memory>

using namespace std;

// can be class or struct.
class Free {
public:
    void operator()(int* p) {
        cout << "class free()" << endl;
        free(p);
    }
};

// deleter can be function.
void MemFree(int *p) {
    cout << "function free()" << endl;
    free(p);
    return;
}

int main() {
    // custom deleter for sgared ptr.
    // shared_ptr<int> s_p {reinterpret_cast<int*>(malloc(4*sizeof(int))), Free{}};
    shared_ptr<int> s_p {reinterpret_cast<int*>(malloc(4*sizeof(int))), MemFree};
    *s_p = 100;
    cout << *s_p << endl;

    // custom deletor for unique ptr.
    // unique_ptr<int, Free> u_p {reinterpret_cast<int*>(malloc(4*sizeof(int))), Free{}};
    unique_ptr<int, void (*)(int*)> u_p {reinterpret_cast<int*>(malloc(4*sizeof(int))), MemFree};

    *u_p = 500;
    cout << *u_p << endl;

    return 0;
}