# Leet Code Solutions

For me to learn, explore and become better

## Build instructions
To build and run the tests, ensure you have CMake installed:
```
mkdir build && cd build
cmake ..
make
ctest .
```

## 1. Two Sum
### C++
There are two solutions. The first one is my own attempt. I start by sorting the list in ascending order. This ensures
that we do not need to iterate on elements if target is lesser than the sum of the values of the indices. I store an
std::pair of values and their indices before sorting them. The inner loop always starts one index ahead of the outer
loop since the previous combos are already checked. In this way, the total number of iterations will lie between O(n)
and O(n^2)

After reading a bit, it seems that since std::unordered_map.find() is gives us a result in O(1) time, we can build the
map and check for our value as the loop goes - giving us a result in O(n) time

### C
The same approach is done in C. However I had to implement a very basic hash map functionality to achieve the same
behavior.

## 9. Palindrome
There are two solutions attempted. They are as follows. Given an integer X with K digits (base 10)

Solution 1
- convert the integer to string representation.
- assign two ptrs, start and end to the string. start points to the first char and end points to the last. Ensure you do
not point to the null char.
- check if *start == *end. If not, its not a palindrome
- increment start and decrement end and check again
- do this until the total number of digits left is either 0 or 1(for odd number of digits).
- This approach will take O(k) to convert the int to string and O(k/2) time to check if its a palindrome

Solution 2
- We can reverse the integer without converting to a string. The formula is
´´´
int r = 0
int n = X

while (n != 0)
{
    r = 10*r + n%10
    n = n/10
}
´´´
- Now check if they are equal. If so its a palindrome

### 13 Roman numeral to int
The tricky part was to determince if an I comes before V or when X comes before C or other similar situations. Hence the
implementation which was finally chosen basically does this:
- Iterate through the string
- Add up the integer value for letter
- Determine if the previous letter affects the current letter in any way
- For ex consider IV.
    - I = 1, total = 1
    - V = 5 : total = 6
    - But V "allows" I to subtract from itself so we need to undo the addition and subtract as well to get the original
      value
    - total = total - 1 - 1 = 4
- The best way to determine if the previous letter does indeed affect the current letter is to exploit how roman
  numerals are written - Largest numbers left to right. When parsing each letter, if the current letter is higher
  value than the previous one, then for sure it subtracts the value.
- So using an std::map for lookup and a single if condition, we can get a low speed of execution.
