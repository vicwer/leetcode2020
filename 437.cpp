#include <iostream>
#include <vector>
#include <queue>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};

int count = 0;

int cntPathSum(TreeNode* root, int sum)
{
    if(!root)
        return;

    if(root->val - sum == 0)
        count += 1;
    cntPathSum(root->left, sum-root->val);
    cntPathSum(root->right, sum-root->val);
}

int pathSum(TreeNode* root, int sum)
{
    if(!root)
        return 0;

    int pathNum = 0;
    std::queue<TreeNode*> cnt_layer;
    cnt_layer.push(root);

    while(!cnt_layer.empty())
    {
        TreeNode* cnt_root = cnt_layer.front();
        cnt_layer.pop();
        if(cnt_root->left)
            cnt_layer.push(cnt_root->left);
        if(cnt_root->right)
            cnt_layer.push(cnt_root->right);

        cntPathSum(cnt_root, sum);
    }

    return pathNum;
}
