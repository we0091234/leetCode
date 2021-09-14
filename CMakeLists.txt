cmake_minimum_required(VERSION 3.10.0)
project(xiaolei)
<<<<<<< HEAD
set(CMAKE_CXX_STANDARD 14)
find_package(Boost REQUIRED COMPONENTS regex)
include_directories(${Boost_INCLUDE_DIRS})
link_libraries(${Boost_LIBRARIES})
add_executable(xiaolei regexTest.cpp)
=======
add_executable(xiaolei /home/xiaolei/leetcode/leetCode/二叉树/buildTree.cpp)
>>>>>>> f9491aed6ef15faec74ff73e2bd17d176e1a6cb5
add_definitions(-O0)