// 2. Add Two Numbers
// https://leetcode.com/problems/add-two-numbers/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <utility>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* returningNode = new ListNode(0);
        ListNode* temp = returningNode;
        int carry = 0, sum = 0;

        while (l1 != nullptr || l2 != nullptr)
        {
            int f = (l1 != nullptr) ? l1->val : 0;
            int s = (l2 != nullptr) ? l2->val : 0;
            sum = f + s + carry;
            carry = sum / 10;
            temp->next = new ListNode(sum % 10);
            temp = temp->next;
            if (l1 != nullptr) { l1 = l1->next; }
            if (l2 != nullptr) { l2 = l2->next; }
        }
        if (carry > 0) { temp->next = new ListNode(carry); }
        return returningNode->next;
    }
};