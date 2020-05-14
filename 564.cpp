#include <iostream>
#include <vector>
#include <queue>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sum(TreeNode* root)
{
    if(!root)
        return 0;

    return root->val+sum(root->left)+sum(root->right);
}

int findTilt(TreeNode* root)
{
    if(!root)
        return 0;

    return findTilt(root->left) + findTilt(root->right) + std::abs(sum(root->left) - sum(root->right));
}
