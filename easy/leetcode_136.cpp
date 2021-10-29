// 136. Single Number
// https://leetcode.com/problems/single-number/

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
    int singleNumber(std::vector<int>& nums)
    {
        int result = 0;

        for (int num : nums) { result ^= num; }

        return result;
    }
};