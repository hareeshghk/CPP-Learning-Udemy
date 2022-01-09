#include <iostream>
#include "integer.h"

class IntPtr {
    Integer *m_p;
public:
    IntPtr (Integer *p) {
        m_p = p;
    }
    ~IntPtr() {
        if (m_p != nullptr) delete m_p;
    }
    Integer *operator->() {
        return m_p; 
    }

    Integer & operator *() {
        return *m_p;
    }
};

// print integer obj in cout.
// std::ostream & operator<< (std::ostream &out, Integer obj) {
//     // cout << "custom print" << endl;
//     out << obj.getValue();
//     return out;
// }

int main() {
    IntPtr val (new Integer(5));
    val->setValue(10);
    std::cout << (*val) << std::endl;
    *val = 15;
    std::cout << (*val) << std::endl;

    return 0;
}