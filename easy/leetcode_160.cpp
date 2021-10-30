// 160. Intersection of Two Linked Lists
// https://leetcode.com/problems/intersection-of-two-linked-lists/

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
    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == nullptr || headB == nullptr) { return nullptr; }
        ListNode* tempA = headA;
        ListNode* tempB = headB;

        while (tempA != tempB)
        {
            tempA = tempA == nullptr ? headB : tempA->next;
            tempB = tempB == nullptr ? headA : tempB->next;
        }

        return tempA;
    }
};