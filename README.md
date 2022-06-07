# cmake_example
cmake使用的案例

一. step1 

1.目的

初步使用cmake，使用命令cmake_minimum_required，project，add_executable上手

2.步骤

a. 在根目录下执行cmake .

b. 在根目录下执行make，生成say_hello.bin可执行文件

c. 在根目录下执行./say_hello.bin


二. step2

1.第一次上手cmake会把cmake自动生成文件平铺在根目录下，不太方便，可以采用外部构建的方式

2.步骤

a. 在根目录下执行cmake -B build，会生成build目录，并且把cmake的生成文件放在build目录中

b. 在根目录下执行cmake --build build，会在build目录中生成say_hello.bin可执行文件

三. step3

1.step2中只有一个源文件main.cpp是平铺在项目根目录下的，实际项目中有很多源文件在不同目录里，所以新建src目录作为源代码的根目录，将main.cpp挪到src下

2.可以将CMakeLists.txt中add_executable改为add_executable(say_hello.bin ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

3.更通用的做法为在src目录下也新建一个CMakeLists.txt，最外层的CMakeLists.txt通过add_subdirectory调用src的CMakeLists.txt

4.步骤

a. 在根目录下执行cmake -B build

b. 在根目录下执行cmake --build build，会在build/src目录中生成say_hello.bin可执行文件

