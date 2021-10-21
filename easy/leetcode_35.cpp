// 35. Search Insert Position
// https://leetcode.com/problems/search-insert-position/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <utility>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target)
    {
        int low = 0, mid = 0, right = nums.size() - 1;

        while (low <= right)
        {
            mid = low + (right - low) / 2;
            if (nums[mid] == target) { return mid; }

            if (nums[mid] < target)
            {
                low = mid + 1;
                if (low > right) return low;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
                if (right < low && low == 0) return 0;
            }
        }

        return mid;
    }
};