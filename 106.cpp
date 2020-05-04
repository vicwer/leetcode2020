#include <vector>
#include <queue>
#include <iostream>

struct BinaryTree
{
    int val;
    BinaryTree* left;
    BinaryTree* right;
};

BinaryTree* buildTree(int leftin, int rightin, int leftpost, int rightpost, std::vector<int>& inorder, std::vector<int>& postorder)
{
    if(rightin < leftin || rightpost < leftpost)
        return NULL;

    BinaryTree* root = new BinaryTree(postorder[rightpost]);

    int mid = 0;
    for(int i = leftin; i < rightin; i++)
    {
        if(postorder[rightpost] == inorder[i])
        {
            mid = i;
            break;
        }
    }

    int left_size = mid - leftin;
    root->left = buildTree(leftin, mid-1, leftpost, leftpost+left_size-1, inorder, postorder);
    root->right = buildTree(mid+1, rightin, leftpost+left_size, rightpost-1, inorder, postorder);

    return root;
}

BinaryTree* buildTree(std::vector<int>& inorder, std::vector<int>& postorder)
{
    return buildTree(0, inorder.size()-1, 0, postorder.size()-1, inorder, postorder);
}