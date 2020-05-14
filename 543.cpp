#include <iostream>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int depth(TreeNode* root)
{
    if(!root)
        return 0;
    return std::max(depth(root->left), depth(root->right)) + 1;
}

int diameterOfBinaryTree(TreeNode* root)
{
    if(!root)
        return 0;

    int leftDepth = depth(root->left);
    int rightDepth = depth(root->right);

    int diameterLeft = diameterOfBinaryTree(root->left);
    int diameterRight = diameterOfBinaryTree(root->right);

    return std::max(leftDepth+rightDepth, std::max(diameterLeft, diameterRight));
}

// int res = 0;

// int dfs(TreeNode* root)
// {
//     if(!root)
//         return 0;

//     int left = dfs(root->left);
//     int right = dfs(root->right);
//     res = std::max(res, left+right);
//     return std::max(left, right) + 1;
// }

// int diameterOfBinaryTree(TreeNode* root)
// {
//     dfs(root);
//     return res;
// }
