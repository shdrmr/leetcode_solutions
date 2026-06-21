#include <gtest/gtest.h>
#include <solution.h>

static void testTwoSum(const std::vector<int>& testCase, int target, const std::vector<int>& expected)
{
    auto res = twoSum(testCase, target);
    std::sort(res.begin(), res.end());
    EXPECT_EQ(res, expected);

    // Test C implementation
    res = {-1, -1};
    twoSum_C(testCase.data(), testCase.size(), res.data(), target);
    std::sort(res.begin(), res.end());
    EXPECT_EQ(res, expected);

}

TEST(TwoSumTest, Case1)
{
    std::vector<int> testCase {2, 7, 11, 15};
    int target = 9;
    std::vector<int> expected {0, 1};
    testTwoSum(testCase, target, expected);
}

TEST(TwoSumTest, Case2)
{
    std::vector<int> testCase {3,2,4};
    int target = 6;
    std::vector<int> expected {1, 2};
    testTwoSum(testCase, target, expected);
}

TEST(TwoSumTest, Case3)
{
    std::vector<int> testCase {3,3};
    int target = 6;
    std::vector<int> expected {0,1};
    testTwoSum(testCase, target, expected);
}

TEST(TwoSumTest, Case4)
{
    std::vector<int> testCase {-1, -2, -3, -4, -5};
    int target = -8;
    std::vector<int> expected {2,4};
    testTwoSum(testCase, target, expected);
}

TEST(TwoSumTest, Case5)
{
    std::vector<int> testCase {0,4,3,0};
    int target = 0;
    std::vector<int> expected {0,3};
    testTwoSum(testCase, target, expected);
}
