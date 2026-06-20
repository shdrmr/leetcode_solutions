add_executable(test-two-sum 0001-two-sum-test.cpp)
target_link_libraries(test-two-sum PRIVATE two-sum GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(test-two-sum)
