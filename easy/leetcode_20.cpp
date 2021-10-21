// 20. Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <utility>

class Solution {
public:
    // runtime 4 ms speed
//    bool isValid(std::string s)
//    {
//        std::stack<char> st;
//
//        for (const char ch : s)
//        {
//            if (ch == '(' || ch == '[' || ch == '{')
//            {
//                st.push(ch);
//            }
//            else if (!st.empty() && (ch == ']' || ch == '}'))
//            {
//                if (st.top() == (ch - 2)) { st.pop(); }
//                else { return false; }
//            }
//            else
//            {
//                if (!st.empty() && st.top() == (ch - 1)) { st.pop(); }
//                else { return false; }
//            }
//        }
//
//        if (st.empty()) { return true; }
//        return false;
//    }

    // runtime 0 ms
    bool isValid(std::string s)
    {
        std::stack<char> st;

        for (const char ch : s)
        {
            switch (ch)
            {
                case '(':
                case '[':
                case '{':
                    st.push(ch);
                    break;
                case ')':
                    if (st.empty() || st.top() != '(') { return false; }
                    st.pop();
                    break;
                case ']':
                    if (st.empty() || st.top() != '[') { return false; }
                    st.pop();
                    break;
                case '}':
                    if (st.empty() || st.top() != '{') { return false; }
                    st.pop();
                    break;
                default:
                    break;
            }
        }

        return st.empty();
    }
};