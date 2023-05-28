#ifndef QUEUE_H_
#define QUEUE_H_

class Customer{
    private:
        long arrive;// arrival time for customer
        int processtime; // processing time for customer
    public:
        Customer() { arrive = processtime = 0;}
        void set(long when); // set arrival=processtime=when
        long when() const {return arrive;}
        int ptime() const {return processtime; }
};

#endif