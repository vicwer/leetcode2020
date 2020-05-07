#include <iostream>
#include <queue>
#include <vector>

struct BinaryTree
{
    int val;
    BinaryTree* left;
    BinaryTree* right;
};

int sum(BinaryTree* root, int val)
{
    if(!root)
        return 0;
    if(!root->left && !root->right)
        return root->val + val * 10;
    val = val * 10 + root->val;
    return sum(root->left, val) + sum(root->right, val);
}

int sumNumbers(BinaryTree* root)
{
    return sum(root, 0);    
}