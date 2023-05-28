// 使用STL queue模板类，重新编写bank.cpp
#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
#include <queue>
#include "16_10_6.h"

const int MIN_PER_HR = 60;

bool newcustomer(double x); // is there a new customer?

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;

    // setting things up
    std::srand(std::time(0)); // random initializing of rand()

    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    std::queue<Customer> line; // 

    cout << "Enter the number of simulation hours: ";
    int hours;
    cin >> hours;
    // simulation will run 1 cycle per minute
    long cyclelimit = MIN_PER_HR * hours; // 用来判断每分钟是否有新用户

    cout << "Enter the average number of customers per hour: ";
    double perhour;
    cin >> perhour;
    double min_per_cust; // average time between arrivals
    min_per_cust = MIN_PER_HR / perhour; // 每几分钟一个用户

    Customer customer; // new customer data
    long turnaways = 0; // turned away by full queue
    long customers = 0; // joined the queue
    long served = 0; // served during the simulation
    long sum_line = 0; // cumulative line length
    int wait_time = 0; // time until autoteller is free 队伍第一个用户等待进入交易的时间
    long line_wait = 0; // cumulative time in line

    // running the simulation 每分钟一次循环
    for (int cycle = 0; cycle < cyclelimit; cycle ++)
    {
        if (newcustomer(min_per_cust)) // have newcomer
        {
            if (line.size() >= qs)
                turnaways ++; 
            else
            {
                customers ++;
                customer.set(cycle); // 设置到达时间、交易时间
                line.push(customer); // add newcomer to line
            }
        }
        if (wait_time <=0 && !line.empty()) // 不用等并且队伍非空的情况，踢出一个用户:队伍只有这个新加入的用户
        {
            wait_time = customer.ptime(); // for wait_time minutes 队伍接下来的等待时间就是这个用户的交易时间
            line_wait += cycle - customer.when(); // 队伍总等待时间等于每个人的等待时间之和
            line.pop(); // 踢出队首的元素
            served ++;
        }
        if (wait_time > 0)
            wait_time --; // 如果atm正在处理，那每次循环，等待atm的时间减1分钟
        sum_line += line.size(); // 用来计算每分钟队伍的平均长度
    }

    // reporting results
    if (customers > 0)
    {
        cout << "customers accepted: " << customers << endl;
        cout << "customers served: " << served << endl;
        cout << "turnaway: " << turnaways << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double) sum_line / cyclelimit << endl;
        cout << " average wait_time: "
             << (double) line_wait / served << " minutes\n";
    }
    else
        cout << "No customers!\n";
    cout << "Done!\n";
    
    return 0;

}

bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}