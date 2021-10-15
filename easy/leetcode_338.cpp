// 338. Counting Bits
// https://leetcode.com/problems/counting-bits/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <utility>

// faster than 5.86%

/*class Solution
{
public:
    std::vector<int> countBits(int n)
    {
        std::vector<int> ret;
        ret.push_back(0);

        for (int i = 1; i <= n; ++i)
        {
            int ii = i;
            std::vector<int> temp;

            while(ii)
            {
                if (ii % 2 == 1) { temp.push_back(ii % 2); }
                ii /= 2;
            }

            if (temp.empty()) { ret.push_back(1); continue; }
            ret.push_back(temp.size());
        }

        return ret;
    }
};*/

class Solution
{
public:
    std::vector<int> countBits(int n)
    {
        std::vector<int> ret;

        for (int i = 0; i <= n; ++i)
        {
            int ii = i;
            int count = 0;
            while (ii)
            {
                ii &= (ii - 1);
                ++count;
            }
            ret.push_back(count);
        }

        return ret;
    }
};