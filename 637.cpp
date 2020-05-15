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

std::vector<double> averageOfLevels(TreeNode* node)
{
    if(!root)
        return {};

    std::vector<double> res;

    std::queue<TreeNode*> cnt_layer;
    cnt_layer.push(root);
    while(!cnt_layer.empty())
    {
        int size = cnt_layer.size();

        double sum = 0.;
        for(int i = 0; i < size; i++)
        {
            TreeNode* cnt_root = cnt_layer.front();
            cnt_layer.pop();
            sum += cnt_root->val;
            if(cnt_root->left)
                cnt_layer.push(cnt_root->left);
            if(cnt_root->right)
                cnt_layer.push(cnt_root->right);
        }
        res.push_back(sum / size);
    }

    return sum;
}
