#include <iostream>

class Distance {
    long double m_kilometers;
public:
    Distance(const long double &km) {
        m_kilometers = km;
    }

    long double getDist() {
        return m_kilometers;
    }
};

Distance operator "" _mi(long double val) {
    return Distance(val * 1.6);
}

Distance operator "" _meters(long double val) {
    return Distance(val/1000);
}

int main() {
    using namespace std;

    Distance d1 {32.0_mi};
    cout << d1.getDist() << endl;

    Distance d2 {1790.0_meters};
    cout << d2.getDist() << endl;

    return 0;
}