// 24. Swap Nodes in Pairs
// https://leetcode.com/problems/swap-nodes-in-pairs/

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
    ListNode* swapPairs(ListNode* head)
    {
        if (head == nullptr) { return nullptr; }
        if (head->next == nullptr) { return head; }
        std::vector<int> temp;

        while (head)
        {
            temp.push_back(head->val);
            head = head->next;
        }

        for (int i = 0; i < temp.size() - 1; i += 2)
        {
            int tem = temp[i];
            temp[i] = temp[i + 1];
            temp[i + 1] = tem;
        }

        ListNode* ret = new ListNode(0);
        ListNode* tempNode = ret;
        for (const int& num : temp)
        {
            tempNode->next = new ListNode(num);
            tempNode = tempNode->next;
        }
        return ret->next;
    }
};