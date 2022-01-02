#include <iostream>

void Print(int count, char ch){
    for (int i=0;i<count;i++) {
        std::cout << ch;
    }
    std::cout << std::endl;
}

void EndMessage() {
    std::cout << "Program End: " << std::endl;
}

int main() {
    atexit(EndMessage);
    Print(5, '#');

    // return type (*function pointer name) (arguments comma separated) = address of original func.
    // ampersent in optional.
    void (*ptf1) (int, char) = &Print;
    void (*ptf2) (int, char) = Print;

    // while calling you can avoid astrick.
    (*ptf1) (6, '@');
    ptf1 (6, '!');

    (*ptf2) (7, '@');
    ptf2 (7, '!');

    return 0;
}