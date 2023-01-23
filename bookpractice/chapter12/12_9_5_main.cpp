#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
#include "12_9_5.h"

const int MIN_PER_HR = 60;

bool newcustomer(double x);

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
    Queue line(qs); // line queue holds up to qs people

    int hours = 100; // hours of simulator
    // simulation will run 1 cycle per minute
    long cyclelimit = MIN_PER_HR * hours; // # of cycles, 用来判断每分钟是否有新用户
    double perhour = 1; // average # of arrival per hour
    
    Item temp; // new customer data
    long turnaways = 0; // turned away by full queue
    long customers = 0; // joined the queue
    long served = 0; // served during the simulation
    long sum_line = 0; // cumulative line length
    int wait_time = 0; // time until autoteller is free 队伍第一个用户等待进入交易的时间
    long line_wait = 0; // cumulative time in line
    double ave_served_waitTime = 0.0;

    while (perhour ++ && ave_served_waitTime <= 1)
    {
        double min_per_cust = MIN_PER_HR / perhour;
        for (int cycle = 0; cycle < cyclelimit; cycle ++) 
        {
            if (newcustomer(min_per_cust)) // have newcomer
            {
                if (line.isfull())
                    turnaways ++;
                else
                {
                    customers++;
                    temp.set(cycle); // cycle = time of arrival 设置到达时间、交易时间
                    line.enqueue(temp); // add newcomer to line
                }
            }
            if (wait_time <= 0 && !line.isempty()) // 不用等并且队伍非空的情况，踢出一个用户:队伍只有这个新加入的用户
            {
                line.dequeue(temp); // attend next customer
                wait_time = temp.ptime(); // for wait_time minutes 队伍接下来的等待时间就是这个用户的交易时间
                line_wait += cycle - temp.when(); // 队伍总等待时长等于每个人的等待时间之和
                served++;
            }
            if (wait_time > 0)
                wait_time --; // 如果atm正在处理，那每次循环就等atm的时间减1分钟
            sum_line += line.queuecount(); // 有问题，怎么会每分钟加一次队伍当前人数
        }

        // reporting results
        if (customers > 0)
        {
            cout << "average of arrival per hour " << perhour << endl;
            cout << "customers accepted: " << customers << endl;
            cout << " customers served: " << served << endl;
            cout << " turnaway: " << turnaways << endl;
            cout << "average queue size: ";
            cout.precision(2);
            cout.setf(ios_base::fixed, ios_base::floatfield);
            cout << (double) sum_line / cyclelimit << endl;
            cout << " average wait_time: "
                << ave_served_waitTime << " minutes\n";
        }
        else 
            cout << "No customers!\n";
        cout << "Done!\n";
        ave_served_waitTime = (double) line_wait / served;
    }

    return 0;
}

bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}