#include <gtest/gtest.h>
#include <solution.h>

TEST(PalindromeTest, TestCases)
{
    EXPECT_EQ(isPalindrome(121), true);
    EXPECT_EQ(isPalindrome(-121), false);
    EXPECT_EQ(isPalindrome(10), false);
    EXPECT_EQ(isPalindrome(1234567899), false);


    EXPECT_EQ(isPalindrome_C(121), 1);
    EXPECT_EQ(isPalindrome_C(-121), 0);
    EXPECT_EQ(isPalindrome_C(10), 0);
    EXPECT_EQ(isPalindrome_C(1234567899), 0);
}
