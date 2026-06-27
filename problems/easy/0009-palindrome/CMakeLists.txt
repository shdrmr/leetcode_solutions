add_library(palindrome solution.cpp solution.c)
target_include_directories(palindrome PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
