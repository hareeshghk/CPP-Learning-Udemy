#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    unordered_set<string> string_set;

    auto inserted = string_set.insert("hello");

    cout << "hello : " << inserted.second << endl;

    inserted = string_set.insert("hello");

    cout << "hello : " << inserted.second << endl;

    return 0;
}