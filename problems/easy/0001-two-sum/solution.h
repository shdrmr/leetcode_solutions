#ifndef __SOLUTION_H_
#define __SOLUTION_H_

#include <vector>
/**
 * Two Sum
 * https://leetcode.com/problems/two-sum/description/
 */

std::vector<int> twoSum(const std::vector<int>& nums, int target);
extern "C" void twoSum_C(const int* const nums, int num_elements, int* res, int target);

#endif
