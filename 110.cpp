#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>

struct BinaryTree
{
    int val;
    BinaryTree* left;
    BinaryTree* right;
};

int depth(BinaryTree* root)
{
    if(!root)
        return 0;
    return std::max(depth(root->left), depth(root->right)) + 1;
}

bool isBalanced(BinaryTree* root)
{
    if(!root)
        return true;

    if(abs(depth(root->left) - depth(root->right)) > 1)
        return false;
    else
        return isBalanced(root->left) && isBalanced(root->right);
}
