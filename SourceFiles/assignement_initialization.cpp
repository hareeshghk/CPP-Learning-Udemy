#include <iostream>
#include "integer.h"

using namespace std;

class Product {
    Integer m_id;
public:
    Product(const Integer &id):m_id(id) {
        cout << "Product()" << endl;
    }
    ~Product() {
        cout << "~Product()" << endl;
    }
};

int main() {
    Product p(10);
    return 0;
}