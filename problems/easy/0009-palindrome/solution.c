#include <stdbool.h>

int isPalindrome_C(int x)
{
    if (x < 0)
    {
        return 0;
    }

    // reconstruct the number backwards. Each digit in x is appended(added) to the previous digit * 10
    int reversed = 0;
    int remainder = x;
    while (remainder != 0)
    {
        reversed = 10*reversed + (remainder % 10);
        remainder = remainder/10;
    }

    // If original number and reverserd number are equal then its a palindrome
    return x == reversed;
}
