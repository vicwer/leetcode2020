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

BinaryTree* last = NULL;
void flatten(BinaryTree* root)
{
    if(!root)
        return;
    flatten(root->right);
    flatten(root->left);
    root->right = last;
    root->left = NULL;
    last = root;
}