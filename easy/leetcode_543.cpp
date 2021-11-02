// 543. Diameter of Binary Tree
// https://leetcode.com/problems/diameter-of-binary-tree/


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
int diameterOfBinaryTree(TreeNode* root)
{
    diameter(root);
    return maxdiameter;
}

private:
int maxdiameter = 0;
int diameter(TreeNode* root)
{
    if (root == nullptr) { return 0; }

    int left = diameter(root->left);
    int right = diameter(root->right);

    maxdiameter = std::max(maxdiameter, left + right);
    return std::max(left, right) + 1;
}
};