#include <iostream>
#include <vector>
#include <queue>

struct BinaryTree
{
    int val;
    BinaryTree* left;
    BinaryTree* right;
};

int res = 0;

int sumOfLeftLeaves(BinaryTree* root)
{
    if(!root)
        return 0;

    if(root->left && root->left->left == NULL && root->left->right == NULL)
    {
        res += root->left->val;
    }

    sumOfLeftLeaves(root->left);
    sumOfLeftLeaves(root->right);

    return res;
}