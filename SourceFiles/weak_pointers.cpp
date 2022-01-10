#include <iostream>

using namespace std;

class Printer {
    weak_ptr<int> wp_int {};
public:
    void setPtr(const shared_ptr<int> &p) {
        wp_int = p;
    }

    void Print() {
        if (wp_int.expired()) {
            cout << "pointer expired" << endl;
            return;
        }
        auto sp = wp_int.lock();
        cout << *sp << endl;
        cout << "Use count: " << sp.use_count() << endl;
    }
};

int main() {
    Printer prn;
    int val;
    cin >> val;
    shared_ptr<int> p{new int{val}};
    prn.setPtr(p);

    if (*p > 10) {
        p = nullptr;
    }
    prn.Print();
    return 0;
}