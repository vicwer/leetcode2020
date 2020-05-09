#include <iostream>
#include <vector>
#include <queue>
#include <string>

struct BinaryTree
{
    int val;
    BinaryTree* left;
    BinaryTree* right;
};

std::vector<std::string> res;

void binaryTreePaths(BinaryTree* root, std::string path)
{
    if(!root)
        return;
    path += std::to_string(root->val);
    
    if(!root->left && !root->right)
    {
        res.push_back(path);
        return;
    }

    binaryTreePaths(root->left, path+"->");
    binaryTreePaths(root->right, path+"->");

    return;
}

std::vector<std::string> binaryTreePaths(BinaryTree* root)
{
    if(!root)
        return res;

    std::string path = "";
    binaryTreePaths(root, path);

    return res;
}