// template members 成员模板
// 一个模板类作为另一个模板类的成员，这个嵌套模板类及方法在类外定义

#include <iostream>

using std::cout;
using std::endl;

template <typename T>
class beta
{
private:
    template <typename V> // member declaration
    class hold;
    hold <T> q;
    hold <int> n;

public:
    beta(T t, int i) : q(t), n(i) {}
    template<typename U> // 泛型函数模板 member template func declaration
    U blab(U u, T t);
    void Show() const {q.show(); n.show();}
};

// member definition
template <typename T>
    template<typename V>
    class beta<T>::hold
    {
    private:
        V val;
    public:
        hold(V v = 0) : val(v) {}
        void show() const {std::cout << val << std::endl;}
        V Value() const {return val;}
    };

// member template func definition
template <typename T>
    template <typename U>
    U beta<T>::blab(U u, T t)
    {
        return (n.Value() + q.Value()) * u / t;
    }

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
