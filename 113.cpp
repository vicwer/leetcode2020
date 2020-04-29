#include <iostream>
#include <vector>
#include <queue>

struct BinaryTree
{
    int val;
    BinaryTree* left;
    BinaryTree* right;

    BinaryTree(int x) : val(x), left(NULL), right(NULL) {};
};

std::vector<std::vector<int>> res;
std::vector<int> cnt_res;

std::vector<std::vector<int>> pathSum(BinaryTree* root, int sum)
{
    if(!root)
        return res;

    if(!root->left && !root->right)
    {
        if(root->val - sum == 0)
        {
            cnt_res.push_back(root->val);
            res.push_back(cnt_res);
            cnt_res.pop_back();
        }
        return res;
    }
    cnt_res.push_back(root->val);
    pathSum(root->left, sum-root->val);
    pathSum(root->right, sum-root->val);
    cnt_res.pop_back();

    return res;
}