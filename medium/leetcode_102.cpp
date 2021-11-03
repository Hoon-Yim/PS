// 102. Binary Tree Level Order Traversal
// https://leetcode.com/problems/binary-tree-level-order-traversal/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <utility>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root)
    {
        std::vector<std::vector<int>> ret;
        if (root == nullptr) { return ret; }

        std::queue<TreeNode*> que;
        que.push(root);
        while (!que.empty())
        {
            int n = que.size();
            std::vector<int> curLevel;

            for (int i = 0; i < n; ++i)
            {
                TreeNode* p = que.front();
                que.pop();
                curLevel.push_back(p->val);
                if (p->left) { que.push(p->left); }
                if (p->right) { que.push(p->right); }
            }
            ret.push_back(curLevel);
        }
        return ret;
    }
};