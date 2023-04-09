// some set operation
// 集合的操作

#include <iostream>
#include <string>
#include <set>

#include <algorithm>
#include <iterator>

int main()
{
    using namespace std;
    const int N = 6;
    string s1[N] = {"buffoon", "thinkers", "for", "heavy", "can", "for"};
    string s2[N] = {"metal", "any", "food", "elegant", "deliver", "for"};

    set<string> A(s1, s1+N); // 初始化A为s1[0,N)的字符串集合
    set<string> B(s2, s2 +N);

    ostream_iterator<string, char> out(cout, " "); // 定义一个将string以char用cout输出，空格分隔每个元素的输出迭代器

    cout << "Set A: ";
    copy(A.begin(), A.end(), out); // 将A copy到输出迭代器输出
    cout << endl;

    cout << "Set B: ";
    copy(B.begin(), B.end(), out);
    cout << endl;
    
    cout << "Union of A and B: \n";
    set_union(A.begin(), A.end(), B.begin(), B.end(), out); // 显示A和B的并集
    cout << endl;

    cout << "Intersection of A and B: ";
    set_intersection(A.begin(), A.end(), B.begin(), B.end(), out); // 显示A和B的交集
    cout << endl;


    cout << "Difference of A and B:\n";
    set_difference(A.begin(), A.end(), B.begin(), B.end(), out); // 显示A和B的差
    cout << endl;

    set<string> C;
    cout << "Set C:\n";
    set_union(A.begin(), A.end(), B.begin(), B.end(), insert_iterator<set<string> > (C, C.begin()));
    copy(C.begin(), C.end(), out);
    cout << endl;

    string s3("grungy");
    C.insert(s3); // 将s3插入C
    cout << "Set C after insertion: \n";
    copy(C.begin(), C.end(), out);
    cout << endl;

    cout << "Showing a range: \n";
    copy(C.lower_bound("ghost"), C.upper_bound("spook"), out);
    cout << endl;

    return 0;

}