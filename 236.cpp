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

BinaryTree* lowestCommonAncestor(BinaryTree* root, BinaryTree* p, BinaryTree* q)
{
    if(!root || root == p || root == q)
        return root;

    BinaryTree* left = lowestCommonAncestor(root->left, p, q);
    BinaryTree* right = lowestCommonAncestor(root->right, p, q);

    if(left == NULL && right == NULL)
        return NULL;
    else if(left && right)
        return root;
    else
        return !left ? right : left;
    
}