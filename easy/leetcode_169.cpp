// 169. Majority Element
// https://leetcode.com/problems/majority-element/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <utility>

class Solution {
public:
    int majorityElement(std::vector<int>& nums)
    {
        if (nums.size() == 1) { return nums[0]; }

        int max = 0, maxLocation = 0;
        std::map<int, int> map;

        for (int num : nums)
        {
            if (map.find(num) == map.end()) { map.insert(std::make_pair(num, 0)); }
            else { map[num]++; }

            if (max < map[num])
            {
                maxLocation = num;
                max = map[num];
            }
        }

        return maxLocation;
    }
};