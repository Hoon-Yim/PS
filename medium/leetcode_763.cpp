// 763. Partition Labels
// https://leetcode.com/problems/partition-labels/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <utility>

class Solution
{
public:
    std::vector<int> partitionLabels(std::string s)
    {
        int last[26];
        for (int i = 0; i < s.length(); ++i) { last[s[i] - 'a'] = i; }

        std::vector<int> ret;
        int right = 0, left = 0;

        for(int i = 0; i < s.length(); ++i)
        {
            right = std::max(right, last[s[i] - 'a']);
            if (i == right)
            {
                ret.push_back(right - left + 1);
                left = right + 1;
            }
        }

        return ret;
    }
};