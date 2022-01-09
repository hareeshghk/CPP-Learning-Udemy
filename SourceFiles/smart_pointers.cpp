#include <iostream>
#include <memory>

#include "integer.h"

using namespace std;

void processUniq(unique_ptr<Integer> temp) {
    cout << temp->getValue() << endl;
    return;
}

void UniquePtr() {
    unique_ptr<Integer> uniq(new Integer(10));
    // move is necessary here. and copy constructor is deleted in unique_ptr.
    processUniq(move(uniq));
    return;
}

void processShared(shared_ptr<Integer> temp) {
    cout << "ptr address: " << temp << endl;
    cout << "shared ptr usecount: " << temp.use_count() << endl;
    cout << temp->getValue() << endl;
    return;
}

void SharedPtr() {
    shared_ptr<Integer> shared(new Integer(11));
    shared->setValue(20);
    cout << "shared ptr usecount: " << shared.use_count() << endl;
    cout << "ptr address: " << shared << endl;
    processShared(move(shared));
    cout << "shared ptr usecount: " << shared.use_count() << endl;

    if (shared == nullptr) cout << "hello" << endl;
    return;
}

int main() {
    UniquePtr();
    SharedPtr();
    return 0;
}