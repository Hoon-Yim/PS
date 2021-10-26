// 101. Symmetric Tree
// https://leetcode.com/problems/symmetric-tree/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <utility>

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode *root)
    {
        return isSame(root, root);
    }

private:
    bool isSame(TreeNode *left, TreeNode *right)
    {
        if (!left and !right) { return true; }
        if (!left or !right) { return false; }
        return left->val == right->val && isSame(left->left, right->right) && isSame(left->right, right->left);
    }
};