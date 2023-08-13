cmake_minimum_required(VERSION 3.16.3)
project(hello)

# 将${CMAKE_CURRENT_SOURCE_DIR}/hello.cpp设置为HELLO_SRC变量
# ${CMAKE_CURRENT_SOURCE_DIR}为cmake内置变量，表示当前CMakeLists.txt所在的目录
set(HELLO_SRC ${CMAKE_CURRENT_SOURCE_DIR}/hello.cpp)

# 添加一个动态库hellolib
# 将${HELLO_SRC}设置为hellolib库的源文件
add_library(hellolib SHARED ${HELLO_SRC})
