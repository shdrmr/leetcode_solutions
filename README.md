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
