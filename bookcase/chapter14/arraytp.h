// Array Template 数组模板和非类型参数
#ifndef ARRAYTP_H_
#define ARRAYTP_H_

template <class T, int n>
class ArrayTP
{ // 类名实际是ArrayTP< class T, int n>
private:
    T ar[n];

public:
    ArrayTP() {};
    explicit ArrayTP(const T & v);
    virtual T & operator[] (int i);
    virtual T operator[] (int i) const;
};

template <class T, int n>
ArrayTP<T, n>::ArrayTP(const T & v)
{
    for ( int i = 0; i < n; i ++)
        ar[i] =v;
}

template <class T, int n>
T & ArrayTP<T, n>::operator[] (int i )
{
    if ( i < 0 || i >= n)
    {
        std::cerr << "Error in array limits: " << i
                  << " is out of range\n";
        std::exit(EXIT_FAILURE);
    }
    return ar[i];
}

template <class T, int n> 
T ArrayTP<T, n>::operator[](int i) const
{
    if (i < 0 || i > n)
    {
        std::cerr << "Error in array limits: " << i
                  << " is out of range\n";
        std::exit(EXIT_FAILURE);
    }
    return ar[i];
}

#endif