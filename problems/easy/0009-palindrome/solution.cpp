#include <format>
bool isPalindromeSolution1(int x)
{
    auto str = std::format("{}", x);

    auto start_it = str.begin();
    auto end_it = str.rbegin();

    int num_digits_remaining = str.size();
    do
    {
        if (*start_it++ != *end_it++)
        {
            return false;
        }
        num_digits_remaining = num_digits_remaining - 2;
    }
    while(num_digits_remaining > 1);

    return true;
}

bool isPalindromeSolution2(int x)
{
    if (x < 0)
    {
        return false;
    }

    // reconstruct the number backwards. Each digit in x is appended(added) to the previous digit * 10
    int reversed = 0;
    int remainder = x;
    while (remainder != 0)
    {
        reversed = 10*reversed + (remainder % 10);
        remainder = remainder/10;
    }
    return x == reversed;
}

bool isPalindrome(int x)
{
    return isPalindromeSolution2(x);
}
