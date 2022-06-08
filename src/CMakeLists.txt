#cmake 最低版本要求为3.16
cmake_minimum_required(VERSION 3.16)

#工程名字为get_url
project(get_url)

set(source ${CMAKE_CURRENT_SOURCE_DIR}/application/main.cpp ${CMAKE_CURRENT_SOURCE_DIR}/input/read.cpp)
# 这里也可以用file增加source变量
# file(GLOB_RECURSE source ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

#生成的可执行文件为get_url.bin，依赖的文件为source
add_executable(get_url.bin ${source})

#添加include路径从src开始
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

#查找第三方库
find_package(CURL REQUIRED)
find_package(jsoncpp CONFIG REQUIRED)

#链接第三方库
##target_link_libraries(get_url.bin ${Boost_LIBRARIES})

target_link_libraries(get_url.bin CURL::libcurl)
target_link_libraries(get_url.bin jsoncpp_lib)