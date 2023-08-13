#include "hello/hello.h"
#include "world.h" // 正常编译会报找不到路径

#include <iostream>

int main()
{
    Hello();
    World();
    return 0;
}