#include <iostream>
#include <string>
#include <thread>

int main() {
    std::string input;
    while (true) {
        std::getline(std::cin, input);
        if (input == "exit") break; // 如果收到"exit"消息，则退出循环
        std::cout << "Process " << std::this_thread::get_id() << ": " << input << std::endl;
    }
    return 0;
}
