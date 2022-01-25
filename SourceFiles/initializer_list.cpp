#include <iostream>
#include <initializer_list>

class Bag {
    int arr[10];
    int cur_size{};
public:
    void Add(int value) {
        assert(cur_size < 10);
        arr[cur_size++] = value;
    }

    void Remove() {
        cur_size--;
    }

    int getSize() {
        return cur_size;
    }

    Bag(std::initializer_list<int> values) {
        assert(values.size() <= 10);
        for (auto it = values.begin(); it != values.end(); ++it) {
            Add(*it);
        }
    }

    // operator for accessing elements like in an array.
    int operator [](int index) {
        assert(index < cur_size);
        return arr[index];
    }
};

void Print(Bag b) {
    for (int i=0;i<b.getSize();i++) {
        std::cout << b[i] << std::endl;
    }
    return;
}

int main() {
    // arr will be of type initializer list.
    auto arr = {1,2,3,4,5};
    // std::initializer_list<int> arr = {1,2,3,4,5};


    // object which works like array of other objects.
    Bag b = {1,2,3,4,5};
    Print(b);
    return 0;
}