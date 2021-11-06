// 617. Merge Two Binary Trees
// https://leetcode.com/problems/merge-two-binary-trees/

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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2)
    {
        if (root1 == nullptr) { return root2; }

        std::stack<std::pair<TreeNode*, TreeNode*>> addition;
        addition.push(std::make_pair(root1, root2));

        while (!addition.empty())
        {
            std::pair<TreeNode*, TreeNode*> temp = addition.top();
            addition.pop();
            if (temp.first == nullptr || temp.second == nullptr) { continue; }

            temp.first->val += temp.second->val;

            if (temp.first->left == nullptr) { temp.first->left = temp.second->left; }
            else { addition.push(std::make_pair(temp.first->left, temp.second->left)); }

            if (temp.first->right == nullptr) { temp.first->right = temp.second->right; }
            else { addition.push(std::make_pair(temp.first->right, temp.second->right)); }
        }

        return root1;
    }
};