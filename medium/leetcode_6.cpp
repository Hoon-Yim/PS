// 6. Zigzag Conversion
// https://leetcode.com/problems/zigzag-conversion/

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
    std::string convert(std::string s, int numRows)
    {
        if (numRows == 1) { return s; }

        std::vector<std::string> rows(std::min(numRows, int(s.size())));
        bool goingDown = false;
        int curLow = 0;

        for (const char c : s)
        {
            rows[curLow] += c;
            if (curLow == 0 || curLow == numRows - 1) { goingDown = !goingDown; }
            curLow += (goingDown) ? 1 : -1;
        }

        std::string ret;
        for (const std::string& str : rows)
        {
            ret += str;
        }

        return ret;
    }
};
