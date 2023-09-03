# cmake_minimum_required(VERSION 3.16.3)
# project(hello_world)

# # 添加子目录：进入hello目录，执行CMakeLists.txt
# add_subdirectory(hello)
# add_subdirectory(world)

# # 主程序只依赖main.cpp
# add_executable(main main.cpp)

# target_include_directories(main PUBLIC world)

# # 添加main需要链接的库
# target_link_libraries(main PUBLIC hellolib)
# target_link_libraries(main PUBLIC worldlib)

# # 添加第三方项目
# add_subdirectory(ThirdPart/googletest)

cmake_minimum_required(VERSION 3.16.3)
project(hello_world)
# 开启测试
enable_testing()
# 声明一个变量为项目的根路径（当前文件所在的目录）
set(HELLO_WORLD_PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
add_subdirectory(hello)
add_subdirectory(world)

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/world)
target_link_libraries(${PROJECT_NAME} PUBLIC hellolib)
target_link_libraries(${PROJECT_NAME} PUBLIC worldlib)
# 引入子项目 测试用例目录
add_subdirectory(tests)