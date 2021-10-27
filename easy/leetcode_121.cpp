// 121. Best Time to Buy and Sell Stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

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
    int maxProfit(std::vector<int>& prices)
    {
        int maxL = 0;
        int low = INT32_MAX, lowL = 0;
        int mProf = 0;

        for (int i = 0; i < prices.size(); ++i)
        {
            if (low > prices[i]) { low = prices[i]; lowL = i; }
            else { maxL = i; }

            if (lowL < maxL) { mProf = std::max(prices[maxL] - prices[lowL], mProf); }
        }

        return mProf;
    }
};