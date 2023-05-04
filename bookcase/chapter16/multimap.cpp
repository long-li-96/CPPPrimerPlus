// use a multimap

#include <iostream>
#include <string>
#include <map>
#include <algorithm>

typedef int KeyType;
typedef std::pair<const KeyType , std::string> Pair;
typedef std::multimap<KeyType, std::string> MapCode;

int main()
{
    using namespace std;
    MapCode codes;

    codes.insert(Pair(415, "San Francisco")); // multimap中元素是键值对，需要用pair对象存储
    codes.insert(Pair(510, "Oakland"));
    codes.insert(Pair(718, "Brooklyn"));
    codes.insert(Pair(718, "Sraten Island"));
    codes.insert(Pair(415, "San Rafael"));
    codes.insert(Pair(510, "Berkley"));

    cout << "Number of cities with area code 415: "
         << codes.count(415) << endl; // 返回具有键为415的元素的个数
    cout << "Number of cities with area code 718: "
         << codes.count(718) << endl;
    cout << "Number of cities with area 510: "
         << codes.count(510) << endl;
    cout << "Area Code City\n";
    MapCode::iterator it;

    for (it = codes.begin(); it != codes.end(); ++ it)
    {
        cout << " " << (*it).first << " "
             << (*it).second << endl;
    }

    pair<MapCode::iterator, MapCode::iterator> range = codes.equal_range(718); // 定义一个pair对象，用来存储equal_range返回的两个迭代器：first、second

    cout << "Cities with area code 718: \n";
    for (it = range.first; it != range.second; ++it)
        cout << (*it).second << endl;
    
    return 0;
}