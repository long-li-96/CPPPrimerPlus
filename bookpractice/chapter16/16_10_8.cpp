// mat容器存储姓名列表，并显示排列后的顺序
// pat容器同
// 创建第三个容器，合并两个姓名列表，去重，并显示容器的内容
#include <set>
#include <iostream>
#include <algorithm>

const int  maxNumOfInvitees = 5;

int main()
{
    std::multiset<std::string> mat;
    std::multiset<std::string> pat;
    std::multiset<std::string> strUnion;
    std::ostream_iterator<std::string, char> out(std::cout, " ");
    std::string tempStr;
    std::cout << "Please enter the name of invitees: \n";
    for (int i = 0; i < maxNumOfInvitees; i ++)
    {
        if (std::getline(std::cin, tempStr))
            mat.insert(tempStr);
    }
    std::copy(mat.begin(),mat.end(), out);

    std::cout << "\nPlease enter the name of invitees: \n";
    for (int i = 0; i < maxNumOfInvitees; i ++)
    {
        if (std::getline(std::cin, tempStr))
            pat.insert(tempStr);
    }
    std::copy(pat.begin(), pat.end(), out);
    std::set_union(mat.begin(), mat.end(), pat.begin(), pat.end(),
    std::insert_iterator<std::multiset<std::string> > (strUnion, strUnion.begin()));
    std::cout << "\nThe union of two sets is :\n";
    std::copy(strUnion.begin(), strUnion.end(), out);

    return 0;
}

