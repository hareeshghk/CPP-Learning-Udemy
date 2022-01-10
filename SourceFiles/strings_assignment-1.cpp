#include <iostream>
#include <string>

using namespace std;

string ToUpper(const string &str) {
    string uppercased;
    for (auto ch:str) {
        uppercased += toupper(ch);
    }
    return uppercased;
}

string ToLower(const string &str) {
    string lowercased;
    for (auto ch:str) {
        lowercased += tolower(ch);
    }
    return lowercased;
}

int main() {
    string a = "ggyuGYGHJVGH567B%CHG";

    cout << ToUpper(a) << endl;

    cout << ToLower(a) << endl;

    return 0;
}