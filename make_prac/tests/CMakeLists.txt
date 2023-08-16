cmake_minimum_required(VERSION 3.16.3)
project(test_hello_world)
#将gtest 添加到项目中,googletest不是tests的子目录，所以需要指定编译路径
add_subdirectory(${HELLO_WORLD_PROJECT_ROOT}/ThirdPart/googletest googletest)
# 添加可执行程序
add_executable(test_hello ${CMAKE_CURRENT_SOURCE_DIR}/test_hello.cpp)
# 添加test_hello依赖的googletest头文件路径
target_include_directories(test_hello PUBLIC ${HELLO_WORLD_PROJECT_ROOT}/ThirdPart/googletest/googletest/include)
# 添加test_hello的头文件路径
target_include_directories(test_hello PUBLIC ${HELLO_WORLD_PROJECT_ROOT})
# 添加test_hello依赖的库:hellolib gtest gtest_main
target_link_libraries(test_hello PUBLIC hellolib gtest gtest_main)
# 将这个测试用例添加到ctest或make test
add_test(NAME test_hello
		COMMAND test_hello)


# test_world **********************
add_executable(test_world ${CMAKE_CURRENT_SOURCE_DIR}/test_world.cpp)

target_include_directories(test_world PUBLIC ${HELLO_WORLD_PROJECT_ROOT}/ThirdPart/googletest/googletest/include)
target_include_directories(test_world PUBLIC ${HELLO_WORLD_PROJECT_ROOT})

target_link_libraries(test_world PUBLIC worldlib gtest gtest_main)

add_test(NAME test_world
         COMMAND test_world)