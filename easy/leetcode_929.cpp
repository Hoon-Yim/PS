// 929. Unique Email Addresses
// https://leetcode.com/problems/unique-email-addresses/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <utility>

class Solution
{
public:
    int numUniqueEmails(std::vector<std::string>& emails)
    {
        std::set<std::string> set{};

        for (int i = 0; i < emails.size(); ++i)
        {
            int at = emails[i].find('@');
            std::string front = emails[i].substr(0, at);
            std::string back = emails[i].substr(at + 1, emails[i].size());

            for (int i = 0; i < front.size(); ++i)
            {
                if (front[i] == '.') { front.erase(front.begin() + i); i--; }
                if (front[i] == '+') { front.erase(front.begin() + i, front.end()); break; }
            }

            set.insert(front + '@' + back);
            std::cout << front+ '@' + back << '\n';
        }

        return set.size();
    }
};