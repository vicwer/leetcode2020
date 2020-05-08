#include <iostream>
#include <vector>
#include <queue>

struct BinaryTree
{
    int val;
    BinaryTree* left;
    BinaryTree* right;
};

vector<int> res;

vector<int> preorderTraversal(BinaryTree* root)
{
    if(!root)
        return res;

    res.push_back(root->val);
    preorderTraversal(root->left);
    preorderTraversal(root->right);

    return res;
}
