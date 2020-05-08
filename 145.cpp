#include <vector>
#include <queue>
#include <iostream>

struct BinaryTree
{
    int val;
    BinaryTree* left;
    BinaryTree* right;
};

vector<int> res;

vector<int> postorderTraversal(BinaryTree* root)
{
    if(!root)
        return res;

    postorderTraversal(root->left);
    postorderTraversal(root->left);
    res.push_back(root->val);

    return res;
}