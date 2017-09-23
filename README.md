# cmake-sample

## 1、最小Cmake build one bin
  
```cmake
  1 cmake_minimum_required(VERSION 2.8)
  2 project(SAMPLE1)
  3
  4 add_executable(sample1 test.cc)
```


## 2、build one lib 静态库 ,  one bin

```cmake
  1 cmake_minimum_required(VERSION 2.8)
  2 project(SAMPLE2)
  3
  4 add_library(hello hello.cc)
  5
  6 add_executable(sample2 test.cc)
  7
  8 target_link_libraries(sample2 hello)
```


## 3、build one lib 动态库 ,  one bin

```cmake
  1 cmake_minimum_required(VERSION 2.8)
  2 project(SAMPLE2)
  3
  4 add_library(hello SHARED hello.cc)
  5
  6 add_executable(sample2 test.cc)
  7 target_link_libraries(sample2 hello)
```


## 4、编译时传入的宏，影响预编译阶段的 #if #else #endif ，链接阶段增加系统的dl ,list 命令
  
  ```cmake
  1 cmake_minimum_required(VERSION 2.8)
  2 project(SAMPLE2)
  3
  4 if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
  5   add_definitions(-D_WIN32)
  6 elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
  7   add_definitions(-D__linux)
  8 elseif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  9   add_definitions(-D__darwin)
 10 endif()
 11
 12 add_library(hello SHARED hello.cc)
 13
 14 list(APPEND SAMPLE_BASE_LIBS dl)
 15
 16 add_executable(sample2 test.cc)
 17 target_link_libraries(sample2 ${SAMPLE_BASE_LIBS})
 ```

## 5、单元测试管理，set变量、编译子目录、enable_testing()/add_test - make test

```cmake
 1 cmake_minimum_required(VERSION 2.8)
  2 project(SAMPLE2)
  3
  4 add_library(hello hello.cc)
  5
  6 add_executable(sample2 test.cc)
  7 target_link_libraries(sample2 hello)
  8
  9 enable_testing()
 10 add_subdirectory(test)

/test/CMakeList.txt
  1 cmake_minimum_required(VERSION 2.8)
  2 project(SAMPLE_TEST)
  3
  4 include_directories(
  5   ${SAMPLE_TEST_SOURCE_DIR}/../ext/gtest-1.6.0/include
  6   ${SAMPLE_TEST_SOURCE_DIR}/../ext/gtest-1.6.0
  7   ${SAMPLE_TEST_SOURCE_DIR}/..
  8   )
  9
 10 add_library(gtest ${SAMPLE_TEST_SOURCE_DIR}/../ext/gtest-1.6.0/src/gtest-all.cc)
 11 add_library(gtest_main ${SAMPLE_TEST_SOURCE_DIR}/../ext/gtest-1.6.0/src/gtest_main.cc)
 12
 13 set(TEST_LIBS
 14   gtest
 15   gtest_main
 16   hello
 17   )
 18
 19 add_executable(hello_unittest hello_unittest.cc)
 20 target_link_libraries(hello_unittest ${TEST_LIBS} pthread)
 21 add_test(HELLO_UNITTEST hello_unittest --gtest_output=xml:TESTS-hello_unittest.xml)
```


## 6、一个目录独立编译so，一个目录编译so/bin 依赖其他目录了的so[目前测试会自动识别出编译顺序]
*     	CMAKE_CURRENT_SOURCE_DIR 当前处理的CMakeLists.txt所在的路径
* 		CMAKE_CURRENT_BINARY_DIR target编译目录

```cmake
├── CMakeLists.txt
├── hello
│   ├── CMakeLists.txt
│   ├── hello.cc
│   └── hello.h
└── sample
    ├── CMakeLists.txt
    └── test.cc

./CMakeLists.txt
  1 cmake_minimum_required(VERSION 2.8)
  2 project(SAMPLE2)
  3 include_directories(${CMAKE_CURRENT_SOURCE_DIR})
  4 add_subdirectory(sample)
  5 add_subdirectory(hello)

./hello/CMakeLists.txt
1 add_library(hello SHARED hello.cc)

./sample/CMakeLists.txt
1 add_executable(sample2 test.cc)
  2 target_link_libraries(sample2 hello)

```


##  待追加

* find_xxxx   
* add_dependencies 
* add_custom_target  
* configure_file
* function(ADD_THIRDPARTY_LIB LIB_NAME)   
* KRPC_GENERATE(实现Kudu Cmake extend plugin)



