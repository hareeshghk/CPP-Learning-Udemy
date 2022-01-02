#include <iostream>

using namespace std;

int main() {
    int num;
    cout << "Input number:";
    cin >> num;
    cout << "Your numbef is: " << num << endl;

    // This is to capture empty line after giving number.
    getchar();
    char buf[512];

    cout << "Input name: ";
    cin.getline(buf, 64, '\n');
    cout << "Your name is: " << buf << endl;

    cout << "Input name: ";
    cin >> buf;
    cout << "Your name is: " << buf << endl;

    bool x;
    cin >> x;
    cout << x << endl;

    float xx;
    cin >> xx;
    cout << xx << endl;
    return 0;
}