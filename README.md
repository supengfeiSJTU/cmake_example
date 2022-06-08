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

四. step4

1.前面步骤中src目录下只有一个main文件，我们这步中在src下增加多个目录。项目改为通过url进行数据传输，并可能采用json格式

2.在src/CMakeLists.txt中利用set(source ${CMAKE_CURRENT_SOURCE_DIR}/application/main.cpp ${CMAKE_CURRENT_SOURCE_DIR}/input/read.cpp)或file(GLOB_RECURSE source ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)添加可执行文件依赖的源文件；并且通过include_directories(${CMAKE_CURRENT_SOURCE_DIR})添加src目录下各文件的include头文件前缀，这样src/application/main.cpp可以直接#include<input/read.h>

3.find_package用来寻找第三方依赖的包路径，有Module模式与Config模式

3.1 cmake默认采用Module模式，make官方为我们预定义了许多寻找依赖包的Module，他们存储在path_to_your_cmake/share/cmake-<version>/Modules目录下。每个以Find<LibaryName>.cmake命名的文件都可以帮我们找到一个包，例如CURL, CURL采用Config模式会报错即find_package(CURL CONFIG REQUIRED)

3.2 如果Module模式搜索失败，没有找到对应的Find<LibraryName>.cmake文件，则转入Config模式进行搜索，可以直接指定COnfig模式，默认在 /usr/lib下进行寻找(不同操作系统不同)，例如jsoncpp，find_package(jsoncpp REQUIRED)和find_package(jsoncpp CONFIG REQUIRED)都可以

3.3 Boost由于是hpp文件，在头文件中实现，所以不需要进行链接

参考：https://zhuanlan.zhihu.com/p/97369704

4.find_package之后通过target_link_libraries进行链接

5.步骤

a. 在根目录下执行cmake -B build

b. 在根目录下执行cmake --build build，然后执行./build/src/get_url.bin
