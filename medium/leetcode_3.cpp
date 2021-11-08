// 3. Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

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
    int lengthOfLongestSubstring(std::string s)
    {
        std::vector<int> vis(256, -1);
        int max = 0, start = -1;

        for (int i = 0; i < s.length(); ++i)
        {
            start = (vis[s[i]] > start) ? vis[s[i]] : start;
            vis[s[i]] = i;
            max = (max < i - start) ? i - start : max;
        }

        return max;
    }
};