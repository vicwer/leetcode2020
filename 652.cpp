#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

std::unordered_map<std::string, int> list;

std::vector<TreeNode*> ret;
std::string getTreeList(TreeNode* root)
{
    std::string res;
    if(!root)
        return "#";
    res = std::to_string(root->val) + " " + getTreeList(root->left) + " " + getTreeList(root->right);
    if(list[res] == 1)
        ret.push_back(root);
    list[res]++;
    return res;
}

std::vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
{
    getTreeList(root);
    return ret;
}
