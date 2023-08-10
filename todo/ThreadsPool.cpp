// C++11 线程池实现-消费者生产者，线程池：消费者，任务队列：生产者
/*
主线程：

主线程是程序启动时自动创建的线程。
它通常负责执行程序的主要控制流程，例如初始化，创建其他线程，等待其他线程完成，以及执行一些主要的逻辑。
在许多情况下，主线程也负责与用户交互，例如在GUI应用程序中。
主线程通常是程序中第一个启动和最后一个结束的线程。

工作线程：
工作线程是主线程或其他工作线程创建的线程，用于执行特定的并行任务。
在线程池的上下文中，工作线程通常是预先创建并等待执行任务的线程。
工作线程可以用于执行CPU密集型任务，如数学计算，或I/O密集型任务，如从文件或网络读取数据。
工作线程通常在完成任务后不会立即结束，而是返回到线程池等待下一个任务。
在你提供的线程池代码中：

主线程是创建线程池、添加任务、等待任务完成并销毁线程池的线程。主线程控制整个程序的流程。
工作线程是线程池中的线程，它们等待并执行主线程添加到任务队列中的任务。工作线程在执行任务时是并行的，可以同时处理多个任务。
通过这种方式，主线程可以继续执行其他任务，而工作线程并行处理耗时的任务。这允许更有效地利用多核处理器，并可以提高程序的响应性和吞吐量。
*/

/*
"上下文"（context）通常指的是执行线程或进程的当前状态。这个状态包括了许多信息，使得操作系统能够在适当的时候暂停该线程或进程，并在以后的某个时候恢复执行。
当操作系统决定将CPU从一个线程切换到另一个线程时（称为上下文切换），它必须保存当前线程的上下文，并恢复下一个线程的上下文。这样，当线程再次被调度执行时，它将从上次停止的地方继续执行，就像从未被中断一样。
上下文切换是一项复杂且耗时的操作，因为涉及许多数据的保存和恢复。在高度并发的系统中，频繁的上下文切换可能会成为性能瓶颈。
*/

#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <memory>
#include <future> // 提供std::future模板类，用于获取异步操作结果

class ThreadPool {
public:
    // 构造函数，初始化指定数量的工作线程
    ThreadPool(size_t threads);

    // 析构函数，停止所有线程
    ~ThreadPool();

    // 将新任务添加到线程池
    // 允许将任意类型和参数的可调用对象添加到线程池的任务队列中，并返回一个 std::future，可以使用这个 future的get()来获取任务的结果（或等待任务完成）。
    template<class F, class... Args> // F为可调用对象，参数包Args,
    auto enqueue(F&& f, Args&&... args) // F&& f右值引用，可绑定到左值或右值的可调用对象
        -> std::future<typename std::result_of<F(Args...)>::type>; // 尾置返回类型为std::future
        // future类型由F函数使用Args...参数调用的结果类型决定，std::result_of<functor>::type在不实际调用functor的情况获取返回类型，可以换成更好的invoke_result更好处理函数指针

private:
    // 工作线程列表
    std::vector<std::thread> workers;

    // 任务队列
    /* std::function是C++标准库中的一个模板类，
    它可以用来封装所有可调用的目标，如普通函数、lambda表达式、函数对象（重载了operator()的结构体或类）、以及带有operator()的类的实例等。*/
    std::queue<std::function<void()>> tasks; // 队列元素为没有参数的返回类型void的函数对象

    // 用于保护任务队列的互斥锁，确保在任何时刻只有一个线程能够访问任务队列
    std::mutex queue_mutex;

    // 条件变量，用于通知工作线程有新任务可用
    std::condition_variable condition;

    // 线程池停止标志
    bool stop;
};

// 构造函数实现
ThreadPool::ThreadPool(size_t threads) : stop(false) {
    // 创建指定数量的工作线程
    for(size_t i = 0; i < threads; ++i)
        // vector.emplace_back(函数符),在容器末尾直接用构造参数构造一个新元素，避免了不必要的临时对象构造析构，提高性能
        // 直接使用lambda函数构造thread对象
        workers.emplace_back( 
            [this] {
                // 每个工作线程的主循环
                for(;;) {
                    std::function<void()> task; // 这里的task将对应任务队列的元素
                    // 这段代码放在块中的原因是控制下面lock的生命周期，确保在块的末尾释放this->queue_mutex，取出任务后就没必要继续持有锁，尽快释放锁
                    {
                        // 获取任务队列的互斥锁，任务队列的线程安全性
                        std::unique_lock<std::mutex> lock(this->queue_mutex); // 创建unique_lock对象：立即锁定this->queue_mutex,lock对象生命周期结束自动释放this->queue_mutex

                        // 等待新任务或线程池停止才停止阻塞线程，其他线程调用了与该条件变量关联的 notify_one() 或 notify_all() 函数也可以停止阻塞线程
                        /* 工作线程在调用 condition.wait() 时必须持有 queue_mutex 锁。这样做的目的是为了在检查条件（this->stop || !this->tasks.empty()）和进入等待状态之间避免竞态条件。
                        这是因为如果在检查条件和调用 wait() 之间有其他线程修改了条件并发出通知，那么这个通知可能会被错过，导致线程错误地进入等待状态。*/
                        // ()可以省略，wait()第二个参数为谓词，仅当线程被唤醒并谓词为true时lock才会释放this->queue_mutex，wait()返回时，lock重新获取this->queue_mutex
                        this->condition.wait(lock, [this]{ return this->stop || !this->tasks.empty(); }); 

                        // 如果线程池已停止并且没有任务，退出线程
                        if(this->stop && this->tasks.empty()) return; // 这里结束死循环

                        // 获取下一个任务
                        task = std::move(this->tasks.front()); // 将tasks队列中的第一个任务的左值引用转为右值引用
                        this->tasks.pop(); // 将tasks队列中的第一个弹出队列
                    } 

                    // 执行任务
                    task();
                }
            }
        );
}

// 析构函数实现
ThreadPool::~ThreadPool() {
    // 把这个互斥锁放在代码块中是为了及时释放
    {
        // 获取任务队列的互斥锁并设置停止标志
        std::unique_lock<std::mutex> lock(queue_mutex); // 防止析构时还有线程在对任务队列进行操作，确保在析构对象时不会发生数据竞争或者访问已经被销毁的资源
        stop = true;
    }
    // 通知所有工作线程
    condition.notify_all(); // 唤醒所有等待在该条件变量上的线程，让所有工作线程都能尽快地检查到 stop 标志的变化，并据此决定是否应该退出

    // 主线程等待所有工作线程完成
    // worker.join();当一个线程（例如主线程）调用另一个线程（例如工作线程）的 join 方法时，调用线程（主线程）会等待被调用线程（工作线程）完成执行
    for(std::thread &worker: workers) worker.join(); // 调用一个线程对象的join方法会导致当前线程（在这个情况下是主线程）阻塞，直到对应的工作线程完成执行
}

// 将新任务添加到线程池的实现,将传进来的函数封装成无参数的可异步执行的packaged_task：任务，然后定义这个任务的结果句柄，将任务添加到任务队列，通知线程（线程自己会去获取新任务执行），最后返回任务结果句柄
template<class F, class... Args>
auto ThreadPool::enqueue(F&& f, Args&&... args) 
    -> std::future<typename std::result_of<F(Args...)>::type> { // std::result_of这里的类型只有在运行时才能确定，所以需要typename告知编译器
    using return_type = typename std::result_of<F(Args...)>::type; // 定义return_type为result_of模板推导出来的类型,以当成正常类型使用

    /*
    将任务包装为一个 std::packaged_task，目的：
    1、异步执行：std::packaged_task允许你将任务的执行与其结果的检索分离。你可以在一个线程中执行任务，并在另一个线程中等待结果。这对于并行和并发编程非常有用。
    2、结果存储：std::packaged_task与一个std::future对象关联，该对象用于存储任务的返回值。这意味着你可以在任务完成后的任何时间检索结果，而不必立即处理它
    3、类型安全：通过使用std::result_of来推断返回类型，std::packaged_task提供了一种类型安全的方式来处理异步任务的结果。这有助于减少类型错误，并使代码更容易理解和维护。
    4、错误处理：如果在执行任务期间抛出异常，std::packaged_task将捕获该异常并将其存储在关联的std::future对象中。
    5、灵活性：通过使用std::bind和完美转发，你可以将任何可调用对象与任何参数集绑定在一起，创建一个新的可调用对象。这为处理各种任务提供了极大的灵活性。
    6、同步控制：与std::condition_variable结合使用时，std::packaged_task可以用于更复杂的同步模式，如线程池中的工作调度
    */ 
    /*
    make_shared:创建共享指针的工厂函数，创建一个指向std::packaged_task的std::shared_ptr
    std::package_task类模板用于包装可调用对象，使其可以异步执行（与future对象关联）,需要一个可调用对象的签名来描述它将要包装的任务
    bind将函数 f 和参数 args... 绑定在一起，创建一个新的可调用对象（std::forward<Args>(args)展开给f作为实参），当任务最终被线程调用时，不需要参数，线程池的用户可以将任何带有任何参数的函数传递给enqueue方法，而线程池的内部实现将这些函数统一视为无参数的可调用对象。这增加了线程池的灵活性，允许它处理各种不同的任务类型，而无需为每种可能的函数签名编写特殊代码
    forward完美转发原始参数类型，保留参数左值/右值属性
    result()可调用对象的签名，它没有参数并返回return_type类型的值
    */
    auto task = std::make_shared<std::packaged_task<return_type()> >(
        std::bind(std::forward<F>(f), std::forward<Args>(args)...) // 任务的参数与原始函数绑定，封装成无参数函数
    );

    // 获取任务的 future（异步的函数返回结果），用于异步获取任务的返回值
    std::future<return_type> res = task->get_future(); // get_future方法由packaged_task提供

    {
        // 获取任务队列的互斥锁，避免数据竞争
        std::unique_lock<std::mutex> lock(queue_mutex);

        // 如果线程池已停止，抛出异常
        if(stop) throw std::runtime_error("enqueue on stopped ThreadPool");

        // 将任务添加到任务队列
        tasks.emplace([task](){ (*task)(); });
    }

    // 通知一个工作线程有新任务
    condition.notify_one();

    return res;
}

int main() {
    // 创建一个包含4个工作线程的线程池
    ThreadPool pool(4);
    /*
    用于存储任务结果的句柄，这里交由到主线程来控制任务完成后的任意时间点获取任务结果，这允许主线程在等待结果的同时执行其他工作，控制获取任务结果的顺序，任务执行顺序还是由线程池调度策略控制，
    */
    std::vector<std::future<int>> results; 

    // 将8个任务添加到线程池
    for(int i = 0; i < 10; ++i) {
        // 主线程存储任务结果句柄的vector插入线程池插入任务的方法返回的句柄
        results.emplace_back(
            // 线程池插入任务
            pool.enqueue([i] {
                std::cout << "Thread " << i << " is working." << std::endl;
                /*
                std::this_thread: 这是一个命名空间，提供了一组访问当前线程的函数
                sleep_for用于阻塞当前线程指定的时间段
                std::chrono::seconds(1): 这是一个时间段，表示1秒。std::chrono是一个命名空间，包括一组表示时间点、时间段和时钟的类和函数。std::chrono::seconds是一个时间段的类型，表示秒数。
                */
                std::this_thread::sleep_for(std::chrono::seconds(1)); // 当前线程暂停执行1秒
                std::cout << "Thread " << i << " has finished." << std::endl;
                return i * i;
            })
        );
    }

    // 输出每个任务的结果
    for(auto && result: results)
    {
        std::cout << result.get() << ' ';
        std::cout << std::endl;
    }
    

    return 0;
}
/*
//
class ThreadSafeInt {
private:
    int value;
    std::mutex mtx;

public:
    ThreadSafeInt(int v) : value(v) {}

    // 增加整数的值
    void increment() {
        std::lock_guard<std::mutex> lock(mtx); // 保证这个对象的线程安性
        ++value;
    }

    // 获取整数的值
    int get() {
        std::lock_guard<std::mutex> lock(mtx);
        return value;
    }
};
int main() {
    ThreadPool pool(4);  // 创建一个包含4个工作线程的线程池
    ThreadSafeInt sharedInt(0);  // 创建一个线程安全的整数，初始值为0

    const int TASK_COUNT = 1000;  // 我们将创建1000个任务

    for (int i = 0; i < TASK_COUNT; ++i) {
        pool.enqueue([&sharedInt]() {
            sharedInt.increment();  // 每个任务都会增加整数的值
        });
    }

    // 等待所有任务完成
    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "Final value of sharedInt: " << sharedInt.get() << std::endl;  // 应该输出1000

    return 0;
}
*/
