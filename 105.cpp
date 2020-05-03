#include <vector>
#include <iostream>
#include <queue>

struct BinaryTree {
    int val;
    BinaryTree* left;
    BinaryTree* right;

    BinaryTree(int x): val(x), left(NULL), right(NULL) {};
};

BinaryTree* buildTree(int leftpre, int rightpre, int leftin, int rightin, std::vector<int>& preorder, std::vector<int>& inorder)
{
    if(rightpre < leftpre || rightin < leftin)
        return NULL;

    BinaryTree* root = new BinaryTree(preorder[leftpre]);

    int mid = 0;

    for(int i = leftin; i < rightin; i++)
    {
        if(preorder[leftpre] == inorder[i])
        {
            mid = 1;
            break;
        }
    }

    int left_size = mid - leftin;
    root->left = buildTree(leftpre+1, leftpre+left_size, leftin, mid-1, preorder, inorder);
    root->right = buildTree(leftpre+left_size+1, rightpre, mid+1, rightin, preorder, inorder);

    return root;
}

BinaryTree* buildTree(std::vector<int>& preorder, std::vector<int>& inorder)
{
    return buildTree(0, preorder.size()-1, 0, inorder.size()-1, preorder, inorder);
}