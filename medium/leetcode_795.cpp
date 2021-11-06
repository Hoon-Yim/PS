// 795. Number of Subarrays with Bounded Maximum
// https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <utility>

class Solution
{
private:
    int count(std::vector<int>& nums, int bound)
    {
        int ret = 0, count = 0;
        for (int& i : nums)
        {
            count = (i <= bound) ? count + 1 : 0;
            ret += count;
        }
        return ret;
    }

public:
    int numSubarrayBoundedMax(std::vector<int>& nums, int left, int right)
    {
        return count(nums, right) - count(nums, left - 1);
    }
};