#cmake 最低版本要求为3.16
cmake_minimum_required(VERSION 3.16)

#工程名字为say_hello
project(say_hello)

#生成的可执行文件为say_hello.bin，依赖的文件为main.cpp
add_executable(say_hello.bin main.cpp)