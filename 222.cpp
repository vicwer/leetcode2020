#include <vector>
#include <queue>
#include <iostream>

struct BinaryTree
{
    int val;
    BinaryTree* left;
    BinaryTree* right;
};

int maxDepth(BinaryTree* root)
{
    int depth = 0;
    while(root)
    {
        depth += 1;
        root = root->left;
    }

    return depth;
}

int countNodes(BinaryTree* root)
{
    if(!root)
        return 0;

    int ld = maxDepth(root->left);
    int rd = maxDepth(root->right);
    
    if(ld == rd)
        return 1+(1<<ld)-1+countNodes(root->right);
    else
        return 1+(1<<rd)-1+countNodes(root->left);
}