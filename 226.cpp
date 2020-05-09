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

BinaryTree* invertTree(BinaryTree* root)
{
    if(!root)
        return root;

    BinaryTree* tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    invertTree(root->left);
    invertTree(root->right);

    return root;
}