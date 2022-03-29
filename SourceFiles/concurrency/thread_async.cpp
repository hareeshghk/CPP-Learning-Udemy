#include <iostream>
#include <thread> // for using threads
#include <future> // for async usgae
void Downloader(int count) {
    std::cout << "[Downloader]: Starting download" << std::endl;
    std::cout << "Current thread id: " << std::this_thread::get_id() << std::endl;
    for (int i = 0; i < count; ++i) {
        // sleep for 300 milliseconds second before printing.
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        std::cout << i << std::endl;
    }
    std::cout << "[Downloader]: Finished download" << std::endl;
}
int Summer(int count) {
    std::cout << "[Downloader]: Starting Count" << std::endl;
    std::cout << "Current thread id: " << std::this_thread::get_id() << std::endl;
    int ans{};
    for (int i = 0; i < count; ++i) {
        ans += i;
        // sleep for 300 milliseconds second before printing.
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        std::cout << ".";
    }
    std::cout << std::endl;
    std::cout << "[Downloader]: Finished Counting" << std::endl;
    return ans;
}
int main() {
    std::cout << "[main]: Started main" << std::endl;
    std::cout << "Num cores avialable: " << std::thread::hardware_concurrency() << std::endl;

    // Downloader in thread
    std::thread t1(Downloader, 5);
    std::cout << "[main]: Called Downloader thread" << std::endl;
    std::cout << "Downloader thread id: " << t1.get_id() << std::endl;

    if (t1.joinable()) t1.join();

    // Downloader in asyc call.
    std::future<void> result = std::async(Downloader, 5);
    result.get(); /// for waiting task to be completed by main thread.

    // sum through a thread;
    // std::future<int> resultsum1 = std::async(Summer, 5);
    // if (resultsum1.valid())
    //     std::cout << resultsum1.get() << std::endl;

    // thread is scheduled at future time. when get called on this then it
    // will be called for sure.
    // std::future<int> resultsum1 = std::async(std::launch::deferred, Summer, 5);
    // if (resultsum1.valid())
    //     std::cout << resultsum1.get() << std::endl;

    // async launch type will create separate thread for it to run, if no thread
    // available then exception will be raised.
    // std::future<int> resultsum1 = std::async(std::launch::async, Summer, 5);
    // if (resultsum1.valid())
    //     std::cout << resultsum1.get() << std::endl;


    // using wait and wait_for wait_util on futture object because get and wait
    // blocks main thread.
    std::future<int> resultsum1 = std::async(std::launch::async, Summer, 5);
    if (resultsum1.valid()) {
        auto status = resultsum1.wait_for(std::chrono::seconds(4));
        // auto status = resultsum1.wait_until(std::chrono::system_clock::now() + std::chrono::seconds(1));
        switch (status) {
        case std::future_status::deferred:
            std::cout << "thread is defreed so its run synchrously, wait not needed" << std::endl;
            break;
        case std::future_status::ready:
            std::cout << "furture is read with result" << std::endl;
            break;
        case std::future_status::timeout:
            std::cout << "future still running" << std::endl;
            break;
        default:
            break;
        }
        std::cout << resultsum1.get() << std::endl;
    }
    return 0;
}