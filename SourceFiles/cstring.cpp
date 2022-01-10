#include <iostream>
#include <cstring>

char * CombineCstrings(const char * pfirst, const char * plast) {
    auto fullname = new char[strlen(pfirst)+strlen(plast)+1];
    strcpy(fullname, pfirst);
    strcat(fullname, plast);
    return fullname;
}

int main() {
    char firstname[10], lastname[10];
    std::cin.getline(firstname, 10);
    std::cin.getline(lastname, 10);

    auto fullname = CombineCstrings(firstname, lastname);
    std::cout << fullname << std::endl;
    delete[] fullname;
    return 0;
}