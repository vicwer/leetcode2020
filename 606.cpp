#include <iostream>
#include <vector>
#include <queue>
#include <string>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



std::string tree2str(TreeNode* root)
{
    std::string res = "";
    if(!root)
        return res;

    if(!root->left && !root->right)
        return res.append(std::to_string(root->val));
    res = res + std::to_string(root->val);
    res = res + ("(" + tree2str(root->left) + ")");
    if(root->right)
        res = res + ("(" + tree2str(root->right) + ")");

    return res;
}
