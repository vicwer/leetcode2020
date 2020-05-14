#include <iostream>
#include <vector>
#include <queue>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL)
};

// int rob(TreeNode* root)
// {
//     if(!root)
//         return 0;
//     int res_left = 0;
//     if(root->left)
//         res_left = rob(root->left->left) + rob(root->left->right);
//     int res_right = 0;
//     if(root->right)
//         res_right = rob(root->right->left) + rob(root->right->right);
//     return std::max(root->val+res_left+res_right, rob(root->right)+rob(root->left));
// }

int rob(TreeNode* root)
{
    if(!root)
        return 0;
    std::vector<int> rob_res = rob2(root);

    return std::max(rob_res[0], rob_res[1]);
}

std::vector<int> rob2(TreeNode* root)
{
    if(!root)
        return {0,0};
    std::vector<int> left_res = rob2(root->left);
    std::vector<int> right_res = rob2(root->right);
    std::vector<int> rob_res{0,0};
    rob_res[0] = std::max(left_res[0], left_res[1]) + std::max(right_res[0], right_res[1]);
    rob_res[1] = root->val + left_res[0] + right_res[0];

    return rob_res;
}
