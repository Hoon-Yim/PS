// 226. Invert Binary Tree
// https://leetcode.com/problems/invert-binary-tree/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <utility>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root)
    {
        if (root == nullptr) { return nullptr; }
        swap(root);

        return root;
    }

private:
    void swap(TreeNode* root)
    {
        if (root == nullptr) { return; }

        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        swap(root->left);
        swap(root->right);
    }
};