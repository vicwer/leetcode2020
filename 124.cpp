#include <iostream>
#include <vector>
#include <queue>

struct BinaryTree
{
    int val;
    BinaryTree* left;
    BinaryTree* right;
};

int result = 0;

int dfs(BinaryTree* root)
{
    if(!root)
        return 0;

    int left = max(dfs(root->left), 0);
    int right = max(dfs(root->right), 0);
    result = max(root->val + left + right, result);
    return max(0, max(left, right))+root->val;
}

int maxPathSum(BinaryTree* root)
{
    if(!root)
        return 0;
    result = root->val;
    dfs(root);
    return result;
}