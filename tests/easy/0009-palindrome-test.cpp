#include <gtest/gtest.h>
#include <solution.h>

TEST(PalindromeTest, TestCase1)
{
    EXPECT_EQ(isPalindrome(121), true);
    EXPECT_EQ(isPalindrome_C(121), 1);
}

TEST(PalindromeTest, TestCase2)
{
    EXPECT_EQ(isPalindrome(-121), false);
    EXPECT_EQ(isPalindrome_C(-121), 0);
}

TEST(PalindromeTest, TestCase3)
{
    EXPECT_EQ(isPalindrome(10), false);
    EXPECT_EQ(isPalindrome_C(10), 0);
}

TEST(PalindromeTest, TestCase4)
{
    EXPECT_EQ(isPalindrome(1234567899), false);
    EXPECT_EQ(isPalindrome_C(1234567899), 0);
}
