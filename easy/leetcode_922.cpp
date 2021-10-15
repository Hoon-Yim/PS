// 922. Sort Array By Parity II
// https://leetcode.com/problems/sort-array-by-parity-ii/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <utility>

class Solution
{
private:
    int findOdd(std::vector<int>& nums, int i)
    {
        for (; i < nums.size(); ++i)
        {
            if (nums[i] % 2 != 0) return i;
        }
    }

    int findEven(std::vector<int>& nums, int i)
    {
        for (; i < nums.size(); ++i)
        {
            if (nums[i] % 2 == 0) return i;
        }
    }

public:
    std::vector<int> sortArrayByParityII(std::vector<int>& nums)
    {
        bool oddOrNot = false;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (!oddOrNot)
            {
                int position = findEven(nums, i);
                std::iter_swap(nums.begin() + i, nums.begin() + position);
            }
            else
            {
                int position = findOdd(nums, i);
                std::iter_swap(nums.begin() + i, nums.begin() + position);
            }

            oddOrNot = !oddOrNot;
        }

        return nums;
    }
};