// 155. Min Stack
// https://leetcode.com/problems/min-stack/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <utility>

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

class MinStack {
private:
    std::stack<std::pair<int, int>> stack;

public:
    MinStack() {}

    void push(int val)
    {
        if (stack.empty()) { stack.push({val, val}); return; }
        if (stack.top().second > val) { stack.push({val, val}); return; }
        stack.push({val, stack.top().second});
    }

    void pop()
    {
        // if (!stack.empty()) { stack.pop(); }
        stack.pop();
    }

    int top()
    {
        // if (!stack.empty()) { stack.top(); }
        return stack.top().first;
    }

    int getMin() {
        return stack.top().second;
    }
};