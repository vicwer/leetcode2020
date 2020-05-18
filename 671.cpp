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

int findMin(TreeNode* root, int val)
{
    if(!root)
        return -1;

    if(root->val > val)
        return root->val;

    int left_min = findMin(root->left, val);
    int right_min = findMin(root->right, val);

    if(left_min > val && right_min > val)
        return std::min(left_min, right_min);
    return std::max(left_min, right_min);
}

int findSecondMinimumValue(TreeNode* root)
{
    return findMin(root, root->val);
}
