include(GoogleTest)

add_executable(test-two-sum 0001-two-sum-test.cpp)
target_link_libraries(test-two-sum PRIVATE two-sum GTest::gtest_main)
gtest_discover_tests(test-two-sum)

add_executable(test-palindrome 0009-palindrome-test.cpp)
target_link_libraries(test-palindrome PRIVATE palindrome GTest::gtest_main)
gtest_discover_tests(test-palindrome)
