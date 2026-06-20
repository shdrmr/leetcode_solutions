#include "solution.h"
#include <map>

// My implementation
std::vector<int> twoSumOriginal(const std::vector<int> &nums, int target)
{
    auto new_array = nums;
    std::vector<std::pair<int, int>> m_Nums;
    for (int i = 0; i < nums.size(); i++)
    {
        m_Nums.push_back({nums[i], i});
    }
    std::sort(m_Nums.begin(), m_Nums.end(), [](const auto& a, const auto& b){return a.first < b.first;});

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            auto total = m_Nums[i].first + m_Nums[j].first;
            if (total > target)
            {
                break;
            }

            if (total == target)
            {
                return {m_Nums[i].second, m_Nums[j].second};
            }
        }
    }

    throw std::runtime_error("Can not reach here (hopefully)");
}

std::vector<int> twoSum(const std::vector<int> &nums, int target)
{
    std::unordered_map<int, int> myMap;
    for (int i = 0; i < nums.size(); i++)
    {
        auto val = target - nums[i];

        // see if it exists in map
        if (myMap.find(val) != myMap.end())
        {
            return {i, myMap[val]};
        }
        myMap[nums[i]] = i;
    }

    throw std::runtime_error("Can not reach here (hopefully)");
}
