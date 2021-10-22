// 53. Maximum Subarray
// https://leetcode.com/problems/maximum-subarray/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <utility>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums)
    {
        if (nums.size() == 1) { return nums.front(); };

        int max = INT32_MIN, maxSoFar = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] <= maxSoFar + nums[i]) { maxSoFar += nums[i]; }
            else { maxSoFar = nums[i]; }

            if (max < maxSoFar) { max = maxSoFar; }
        }

        return max;
    }
};