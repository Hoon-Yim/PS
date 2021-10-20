// 94. Binary Tree Inorder Traversal
// https://leetcode.com/problems/binary-tree-inorder-traversal/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <utility>

struct TreeNode
{
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
    std::vector<int> ret;
    std::vector<int> inorderTraversal(TreeNode* root)
    {
        traverse(root);
        return ret;
    }

    void traverse(TreeNode* self)
    {
        if (self == nullptr) { return; }
        traverse(self->left);
        ret.push_back(self->val);
        traverse(self->right);
    }
};