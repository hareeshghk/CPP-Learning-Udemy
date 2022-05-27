#include <iostream>

using namespace std;

class Logger {
    int count;
    static Logger *logger;
    Logger() {
        count = 0;
    }
public:
    static Logger* GetInstance() {
        if (logger == nullptr) {
            logger = new Logger;
        }
        return logger;
    }

    void PrintMessage(string s) {
        ++count;
        cout << "String " << s << " came at count " << count << endl;
    }
};

Logger* Logger::logger = nullptr;

int main() {
    auto logger = Logger::GetInstance();
    logger->PrintMessage("Hello");
    auto logger2 = Logger::GetInstance();
    logger2->PrintMessage("World");
    return 0;
}