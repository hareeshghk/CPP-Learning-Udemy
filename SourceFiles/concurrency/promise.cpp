#include <iostream>
#include <future>

int Counter(std::promise<int> &data) {
    std::future data_future = data.get_future();
    std::cout << "Waiting for int of data" << std::endl;
    int count = data_future.get();
    std::cout << "Received int of data" << std::endl;
    int ans{};
    for (int i = 0; i< count; ++i) {
        ans+=i;
    }
    return ans;;
}

int main() {
    std::promise<int> data;

    std::future<int> summer = std::async(std::launch::any, Counter, std::ref(data));

    std::this_thread::sleep_for(std::chrono::seconds(2));

    // setting value into promise.
    data.set_value(5);


    if (summer.valid()) {
        auto status = summer.wait_for(std::chrono::seconds(1));
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
        int result = summer.get();
        std::cout << "Sum result: " <<  result << std::endl;
    }
    return 0;
}