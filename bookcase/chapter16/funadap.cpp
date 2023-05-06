// using function adapters
// 使用函数适配器

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional> // for transform()、multiplies<>、bind

// transform()用于对容器中的元素进行操作并将结果存储在另一个容器中。它可以应用一个一元操作（即仅使用一个输入参数的操作）或二元操作（使用两个输入参数的操作）
void Show(double);
const int LIM = 6;
int main()
{
    using namespace std;
    double arr1[LIM] = {28, 29, 30, 35, 38, 59};
    double arr2[LIM] = {63, 65, 69, 75, 80, 99};
    vector<double> gr8 (arr1, arr1+LIM); // c++11支持初始列表， vector<double> gr8 = {28, 29, 30, 35, 38, 59};
    vector<double> m8(arr2, arr2 + LIM); // c++11支持初始列表， vector<double> m8 {63, 65, 69, 75, 80, 99};
    cout.setf(ios_base::fixed);
    cout.precision(1);
    cout << "gt8:\t";
    for_each(gr8.begin(), gr8.end(), Show); // 第三个参数是函数符(函数对象)
    cout << endl;
    cout << "m8:\t";
    for_each(m8.begin(), m8.end(), Show);
    cout << endl;

    vector<double> sum(LIM);
    transform(gr8.begin(), gr8.end(), m8.begin(), sum.begin(), plus<double>()); // plus<double>()模板类初始化一个函数对象,处理c++内置类型、重载了+的自定义类型,重载了+，用于两个迭代器中的元素相加
    cout << "sum:\t";
    for_each(sum.begin(), sum.end(), Show);
    cout << endl;

    vector<double> prod(LIM);
    transform(gr8.begin(),gr8.end(), prod.begin(), bind(multiplies<double>(), 2.5, placeholders::_1)); // 在c++17中bind1st已被移除 bind(multiplies<double>(), 2.5, placeholders::_1)==bind1st(multiplies<double>(), 2.5)
    // bind()函数适配器，在这里将原本需要两个参数的multiplies函数符转化为只需一个参数的函数符，这里是将常数2.5赋给multiplies<double>()的第一个参数
    cout << "prod:\t";
    for_each(prod.begin(), prod.end(), Show);
    cout << endl;
    
    return 0;
}

void Show(double v)
{
    std::cout.width(6);
    std::cout << v << ' ';
}