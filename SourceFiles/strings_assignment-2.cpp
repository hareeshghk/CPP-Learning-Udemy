#include <iostream>
#include <string>

enum class Case {SENSITIVE, INSENSITIVE};

bool compareChars(char ch1, char ch2, Case searchCase) {
    if (searchCase == Case::SENSITIVE) {
        return ch1 == ch2;
    }
    return tolower(ch1) == tolower(ch2);
}

size_t Find(const std::string &source, const std::string &search_string,
    Case searchCase = Case::INSENSITIVE, size_t offset = 0 ) {
    //Implementation

    int source_length = source.length();
    for (int itr = offset;itr<source_length;itr++) {
        int search_itr = 0, itr2 = itr;
        if (compareChars(source[itr2],search_string[search_itr], searchCase)) {
            int leng = search_string.length();
            while(search_itr < leng && itr2 < source_length &&
                compareChars(source[itr2],search_string[search_itr], searchCase)) {
                search_itr++;
                itr2++;
            }
            if (leng == search_itr) return itr;
        }
    }
    return std::string::npos;
 
    /*
     return position of the first character 
     of the substring, else std::string::npos
     */
}

int main() {
    std::string source = "helLoWOrld";
    std::cout << Find(source, "oworl") << std::endl;
    std::cout << Find(source, "oworld", Case::SENSITIVE, 3) << std::endl;
    std::cout << Find(source, "oworld", Case::SENSITIVE, 8) << std::endl;
    return 0;
}