cmake_minimum_required(VERSION 3.10)

project(leetcode_shdrmr)

set(CMAKE_CXX_STANDARD 20)

enable_testing()

add_subdirectory(third-party/googletest)

# Easy
add_subdirectory(tests/easy/)
add_subdirectory(problems/easy/0001-two-sum)
add_subdirectory(problems/easy/0009-palindrome)
add_subdirectory(problems/easy/0013-roman-numerals)
