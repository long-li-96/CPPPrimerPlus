// template members 成员模板

#include <iostream>

using std::cout;
using std::endl;

template <typename T>
class beta
{
private:
    template <typename V>   // nested template class member
    class hold              // 定义了一个成员模板类
    {
    private:
        V val;
    public:
        hold(V v = 0) : val(v) {}
        void show() const {cout << val << endl; }
        V Value() const {return val;}
    };

    hold<T> q;  // template object
    hold<int> n; // template object

public:
    beta( T t, int i) : q(t), n(i) {}
    template <typename U>  // template method 泛型函数模板
    U blab(U u, T t) {return (n.Value() + q.Value() * u / t);}
    // 这里的T是与构造函数调用时传的类型是同一个,U是新定义的泛型
    void Show() const {q.show(); n.show();}
};

int main()
{
    beta<double> guy(3.5, 3); // 类构造函数使用的类型是double
    cout << "T was set to double.\n";
    guy.Show();

    cout << 'V was set to T, which is double, then V was set to int\n';

    cout << guy.blab(10, 2.3) << endl;
    cout << "U was set to int\n";

    cout << guy.blab(10.0, 2.3) << endl;
    cout << "U was set to double\n";
    cout << "Done\n";
    return 0;
}