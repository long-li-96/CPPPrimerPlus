#include <boost/process.hpp>
#include <vector>
#include <iostream>
#include <string>


/*
使用boost.process库实现多进程
*/
class ProcessPool {
public:
    // 构造函数，创建指定数量的子进程
    ProcessPool(size_t size, const std::string& program) {
        for (size_t i = 0; i < size; ++i) { // 循环创建子进程
            boost::process::ipstream in; // 父进程的输入流，用于读取子进程的标准输出（重定向）
            boost::process::opstream out; // 父进程的输出流，用于写入子进程的标准输入（重定向）
            /*
            创建子进程,执行program，将子进程的输入流重定向到父进程的输出流，子进程的输出流重定向到父进程的输入流，可以同时指定可执行文件的路径、命令行参数、重定向选项和环境变量
            */
            boost::process::child c(program, boost::process::std_out > in, boost::process::std_in < out); 
            /*
            在这个上下文中，in 和 out 是流对象，用于父进程与子进程之间的通信。
            in 是一个输入流对象，用于从子进程读取数据。在创建子进程时，它被重定向到子进程的标准输出。因此，当子进程写入其标准输出时，父进程可以通过 in 读取这些数据。
            out 是一个输出流对象，用于向子进程写入数据。在创建子进程时，它被重定向到子进程的标准输入。因此，当父进程写入 out 时，数据会被发送到子进程的标准输入。
            在这个代码中，"父进程" 是指运行 ProcessPool 类的进程。这个进程创建并管理了一组子进程，并通过 in 和 out 与它们通信。"子进程" 是指由 ProcessPool 创建的进程，它们通过 boost::process::child 对象表示，并与父进程通过重定向的标准输入/输出进行通信。
            */
            children.emplace_back(std::move(c), std::move(in), std::move(out)); // 将子进程添加到进程池
        }
    }

    // 析构函数，终止所有子进程
    ~ProcessPool() {
        for (auto& child : children) {
            child.process.terminate(); // 终止子进程
        }
    }

    // 向进程池中的每个进程发送一个消息
    void broadcast(const std::string& message) {
        for (auto& child : children) {
            child.out << message << std::endl; // 向子进程的输入流写入消息
        }
    }

    // 从进程池中的每个进程接收一个响应
    void receiveResponses() {
        for (auto& child : children) {
            std::string response;
            std::getline(child.in, response); // 从子进程的输出流读取响应
            std::cout << "Received: " << response << std::endl; // 打印响应
        }
    }

private:
    // 子进程结构体，包括进程对象和与进程通信的流
    struct ChildProcess {
        boost::process::child process; // 子进程对象
        boost::process::ipstream in; // 子进程的输入流
        boost::process::opstream out; // 子进程的输出流
        
        ChildProcess(boost::process::child&& p, boost::process::ipstream&& i, boost::process::opstream&& o)
            : process(std::move(p)), in(std::move(i)), out(std::move(o)) {} // 构造函数
    };

    std::vector<ChildProcess> children; // 子进程容器
};

int main() {
    ProcessPool pool(4, "/path/to/your/program"); // 创建包含4个进程的进程池

    pool.broadcast("Hello, world!"); // 向每个进程发送消息

    pool.receiveResponses(); // 接收每个进程的响应

    return 0;
}
