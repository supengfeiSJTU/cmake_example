#cmake 最低版本要求为3.16
cmake_minimum_required(VERSION 3.16)

#工程名字为get_url
project(get_url)

#添加子目录
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src)