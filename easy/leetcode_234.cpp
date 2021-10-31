// 234. Palindrome Linked List
// https://leetcode.com/problems/palindrome-linked-list/submissions/

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

class Solution
{
public:
    bool isPalindrome(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* pre = nullptr;
        ListNode* next = nullptr;

        while (slow != nullptr)
        {
            next = slow->next;
            slow->next = pre;
            pre = slow;
            slow = next;
        }

        while (head != nullptr and pre != nullptr)
        {
            if (head->val != pre->val) { return false; }
            head = head->next;
            pre = pre->next;
        }

        return true;
    }
};