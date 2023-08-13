cmake_minimum_required(VERSION 3.16.3)
project(hello_world)

# 添加子目录：进入hello目录，执行CMakeLists.txt
add_subdirectory(hello)
add_subdirectory(world)

# 主程序只依赖main.cpp
add_executable(main main.cpp)

target_include_directories(main PUBLIC world)

# 添加main需要链接的库
target_link_libraries(main PUBLIC hellolib)
target_link_libraries(main PUBLIC worldlib)