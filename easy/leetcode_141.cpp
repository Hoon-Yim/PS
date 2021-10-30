// 141. Linked List Cycle
// https://leetcode.com/problems/linked-list-cycle/

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
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr or head->next == nullptr) { return false; }
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (slow != nullptr and fast != nullptr and fast->next)
        {
            if (slow == fast) { return true; }
            slow = slow->next;
            fast = fast->next->next;
        }

        return false;
    }
};