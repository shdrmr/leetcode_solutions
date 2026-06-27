#include <gtest/gtest.h>
#include <solution.h>

TEST(RomanNumerals, TestCase_III)
{
    std::string roman = "III";
    EXPECT_EQ(romanToInt(roman), 3);
    EXPECT_EQ(romanToInt_C(roman.c_str(), roman.size()), 3);
}

TEST(RomanNumerals, TestCase_LVIII)
{
    std::string roman = "LVIII";
    EXPECT_EQ(romanToInt(roman), 58);
    EXPECT_EQ(romanToInt_C(roman.c_str(), roman.size()), 58);
}

TEST(RomanNumerals, TestCase_MCMXCIV)
{
    std::string roman = "MCMXCIV";
    EXPECT_EQ(romanToInt(roman), 1994);
    EXPECT_EQ(romanToInt_C(roman.c_str(), roman.size()), 1994);
}

TEST(RomanNumerals, TestCase_DCXXI)
{
    std::string roman = "DCXXI";
    EXPECT_EQ(romanToInt(roman), 621);
    EXPECT_EQ(romanToInt_C(roman.c_str(), roman.size()), 621);
}
