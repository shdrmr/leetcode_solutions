include(GoogleTest)

add_executable(test-two-sum 0001-two-sum-test.cpp)
target_link_libraries(test-two-sum PRIVATE two-sum GTest::gtest_main)
gtest_discover_tests(test-two-sum)

add_executable(test-palindrome 0009-palindrome-test.cpp)
target_link_libraries(test-palindrome PRIVATE palindrome GTest::gtest_main)
gtest_discover_tests(test-palindrome)

add_executable(test-roman-int 0013-roman-numerals-test.cpp)
target_link_libraries(test-roman-int PRIVATE romantoint GTest::gtest_main)
gtest_discover_tests(test-roman-int)
