#include <iostream>
#include <string>

using namespace std;

int main() {
    string first;
    string last;

    getline(cin, first);
    getline(cin, last);

    auto fullname = first+last;

    //size
    cout << "fullname size: " << fullname.length() << endl;
    cout << "fullname: " << fullname << endl;


    // insert at a point.
    fullname.insert(8, "INSERT");
    cout << fullname << endl;

    // erase at a point.
    fullname.erase(6, 6);
    cout << fullname << endl;

    // finding a substring.
    auto pos = fullname.find("hello", 0);
    if (pos != string::npos) {
        cout << "sub string found at point: " << pos << endl;
    }

    //to use it as raw string like in c.
    printf("%s\n", fullname.c_str());

    // clearing a string.
    // fullname.erase(); you can use this also
    fullname.clear();

    return 0;
}