// 7. Reverse Integer
// https://leetcode.com/problems/reverse-integer/

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
    int reverse(int x)
    {
        int original = x;
        long ret = 0;
        std::vector<int> reversed;

        while (original)
        {
            reversed.push_back(original % 10);
            original /= 10;
        }

        for (int& num : reversed)
        {
            ret *= 10;
            ret += num;
        }

        if (ret > INT32_MAX || ret < INT32_MIN) { return 0; }
        return ret;
    }
};
