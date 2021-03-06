// 279. Perfect Squares
// https://leetcode.com/problems/perfect-squares/

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
    int numSquares(int n)
    {
        if (n == 0) { return 0; }
        std::vector<int> dp(n + 1, INT32_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j * j <= i; ++j)
            {
                dp[i] = std::min(dp[i], dp[i - j * j] + 1);
            }
        }

        return dp.back();
    }
};