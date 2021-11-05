// 199. Binary Tree Right Side View
// https://leetcode.com/problems/binary-tree-right-side-view/

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
    // faster
private:
    void recursion(TreeNode* root, int level, std::vector<int>& ret)
    {
        if (root == nullptr) { return; }
        if (ret.size() < level) { ret.push_back(root->val); }
        recursion(root->right, level + 1, ret);
        recursion(root->left, level + 1, ret);
    }

public:
    std::vector<int> rightSideView(TreeNode* root)
    {
        std::vector<int> ret;
        recursion(root, 1, ret);
        return ret;
    }

    // slower version
//    std::vector<int> rightSideView(TreeNode* root)
//    {
//        std::vector<int> ret;
//        if (root == nullptr) { return ret; }
//        std::queue<TreeNode*> q; q.push(root);
//
//        while (!q.empty())
//        {
//            int n = q.size();
//            std::stack<int> curLevel;
//
//            for (int i = 0; i < n; ++i)
//            {
//                TreeNode* temp = q.front(); q.pop();
//                curLevel.push(temp->val);
//                if (temp->left != nullptr) { q.push(temp->left); }
//                if (temp->right != nullptr) { q.push(temp->right); }
//            }
//            ret.push_back(curLevel.top());
//            curLevel = std::stack<int>();
//        }
//        return ret;
//    }
};