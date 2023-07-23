#include <iostream>

template <typename T, typename F>
T use_f(T v, F f)
{
    static int count = 0; // 根据这个静态成员的地址可以确定模板实例化了多少次
    count ++;
    std::cout << " use_f count = " << count
              << ", &count = " << & count << std::endl;
    return f(v);
}

class Fp
{
    private:
        double z_;
    public:
        Fp(double z = 1.0) : z_ (z) {}
        double operator() (double p) {return z_*p;}
};

class Fq
{
    private:
        double z_;
    public:
        Fq(double z = 1.0) : z_(z) {}
        double operator() (double q) {return z_+q; }
};