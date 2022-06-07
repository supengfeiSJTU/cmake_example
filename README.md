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
