#include <iostream>
#include <future>
#include <thread>
#include <chrono>

// 模拟一个耗时的I/O操作
std::string async_io_operation(const std::string& input) {
    std::this_thread::sleep_for(std::chrono::seconds(2)); // 模拟耗时操作
    return input + " has been processed.";
}

int main() {
    // 启动异步任务
    std::future<std::string> result_future = std::async(std::launch::async, async_io_operation, "Hello");

    // 在主线程中做其他事情
    std::cout << "Doing other work in main thread...\n";

    // 获取异步任务的结果
    std::string result = result_future.get();

    // 输出结果
    std::cout << "Result from async operation: " << result << "\n";

    return 0;
}
