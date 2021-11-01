// 283. Move Zeros
// https://leetcode.com/problems/move-zeroes/

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
public:
    void moveZeroes(std::vector<int>& nums)
    {
/*      faster than 8% solution
 *      erasing and pushing back cause lots of operations
        int zeros = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0) { nums.erase(nums.begin() + i); ++zeros; --i; }
        }

        for (int i = 0; i < zeros; ++i) { nums.push_back(0); }
*/

        int zero = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i]) { nums[zero++] = nums[i];}
        }
        for (; zero < nums.size(); nums[zero] = 0) {}
    }
};