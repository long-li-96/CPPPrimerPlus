#include "14_7_3.h"
#include <cstring>

const int SIZE = 5;

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    using std::strchr;

    Queue<Worker> queue_worker(SIZE);
    Worker * worker_temp[SIZE];

    int ct;
    for (ct = 0; ct < SIZE; ct ++)
    {
        char choice;
        cout << "Enter the employee category: \n"
             << "w: waiter s: singer "
             << "q: quit\n";
        cin >> choice;
        // 第一个参数str是要被查找的字符串，第二个参数character是要查找的字符。如果查找成功，函数将返回一个指向该字符第一次出现位置的指针；如果查找失败，函数将返回nullptr。
        while (strchr("wsq", choice) == NULL)
        {
            cout << "Please enter a w, s, or q: ";
            cin >> choice;
        }
        if (choice == 'q') break;
        switch (choice) {
            case 'w':
                worker_temp[ct] = new Waiter;
                worker_temp[ct]->Set();
                queue_worker.enqueue(* worker_temp[ct]);
                break;
            case 's':
                worker_temp[ct] = new Singer;
                worker_temp[ct]->Set();
                queue_worker.enqueue(* worker_temp[ct]);
                break;
            // case 't':
            //     worker_temp[ct] = new  SingingWaiter;
            //     worker_temp[ct]->Set();
            //     queue_worker.enqueue(worker_temp[ct]);
            //     break;
        }
        cin.get();
    }
    cout << "\nHere is your staff:\n";
    int i;
    for (i = 0; i < ct; i++) {
        cout << endl;
        worker_temp[i]->Show();
    }
    cout << queue_worker.queuecount() << endl;
    
    for (i = 0; i < ct; i++) delete worker_temp[i];
    cout << "Bye.\n";
    return 0;
}

// #include "14_7_3.h"

// const int SIZE = 3;
// int main()
// {
// 	int count = 0;
// 	Worker* pWorker = new Worker[SIZE];
// 	pWorker[0] = Worker("Jim", 1001);
// 	pWorker[1] = Worker("Tom", 1002);
// 	pWorker[2] = Worker("Tim", 1003);
// 	Queue<Worker> queue(3);
// 	while (queue.queuecount() < 3)
// 		queue.enqueue(pWorker[count++]);
// 	if (queue.queuecount() == 3)std::cout << "The Queue is full, the elements are: \n";
// 	queue.show();
// 	while (queue.queuecount() > 0)
// 		queue.dequeue(pWorker[--count]);
// 	if (queue.queuecount() == 0)std::cout << "The Queue is empty now. \n";
// 	delete[] pWorker;
// 	system("pause");
// 	return 0;
// }