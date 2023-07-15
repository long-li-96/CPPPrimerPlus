/* 
Mat 和 Pat想邀请他们的朋友来参加派对，就像第16章中的编程练习8那样，但现在他们希望
使用文件。他们请您编写一个完成下述任务的程序。
· 从文本文件mat.dat中读取Mat朋友的姓名清单，其中每行为一个朋友。姓名将被存储在
容器，然后按顺序显示出来。
· 从文本文件pat.dat中读取Pat朋友的姓名清单，其中每行为一个朋友。姓名将被存储在
容器中，然后按顺序显示出来。
· 合并两个清单，删除重复的条目，并将结果保存在文件matnpat.dat中，其中每行为一个朋友
*/ 
#include <set>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstdlib>
