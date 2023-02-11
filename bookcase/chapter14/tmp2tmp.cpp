// template friends to a template class
// 约束模板友元函数

#include <iostream>

using std::cout;
using std::endl;

// 1、template prototypes
template <typename T> void counts();
template <typename T> void report(T &);

// template class
template <typename TT> // 与友元的类型参数不一致
class HasFriendT
{
private:
    TT item;
    static int ct;

public:
    HasFriendT(const TT & i) : item(i) {ct ++;}
    ~HasFriendT() {ct --;}
    // 2、再次将模板声明为友元, 函数名后接<>表明是模板具体化
    friend void counts<TT>(); // 因为没有参数，必须使用模板参数语法<TT>来指明其具体化
    friend void report<> (HasFriendT<TT> &); // <>中可以为空，是因为可以从函数参数推断出模板类型参数
};

template <typename T>
int HasFriendT<T>::ct = 0;

// 3、template friend functions definitions
template <typename T>
void counts()
{
    cout << "template size: " << sizeof(HasFriendT<T>) << "; ";
    cout << "template counts(): " << HasFriendT<T>::ct << endl;
}

template <typename T>
void report(T & hf)
{
    cout << hf.item << endl;
}

int main()
{
    counts<int> ();

    HasFriendT<int> hfi1(10);
    HasFriendT<int> hfi2(20);
    HasFriendT<double> hfdb(10.5);

    report(hfi1); // generate report(HasFriendt<int> &)
    report(hfi2); // generate report(HasFriend<int> &)
    report(hfdb); // generate report(HasFriend<double> &)

    cout << "counts<int> () output: \n";
    counts<int>();
    cout << "counts<double>() output:\n";
    counts<double>();

    return 0;
}
