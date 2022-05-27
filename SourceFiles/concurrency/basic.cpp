#include <iostream>
#include <list>
#include <thread>
#include <unistd.h>
using namespace std;
list<int> g_Data;
const int SIZE = 50000000;

void Download() {
    cout << "[Downloader] Started Download"<<endl;
    for (int i = 0; i < SIZE; ++i) {
        g_Data.push_back(i);
    }
    cout << "[Downloader] Completed Download"<<endl;
}

class Tester {
public:
    void print(int x) {
        cout << x << endl;
    }
};

int main() {
    cout << "[main]User started an operation" << endl;
    std::thread thDownloader(Download);
    cout << "[main]User started another operation" << endl;
    // a detached thread can't be added back to joinable
    // if thread object gets detroyed then thread also destroyed.
    // thDownloader.detach();
    // wait for child thread to complete.
    if (thDownloader.joinable()) {
        cout << "thDownloader thread is joinalble" << endl;
        thDownloader.join();
    }

    sleep(1);

    Tester tester;

    thread tk = thread(&Tester::print, &tester, 5);
    tk.join();
    return 0;
}