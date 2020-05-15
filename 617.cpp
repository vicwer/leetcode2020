#include <iostream>
#include <vector>
#include <queue>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
{
    if(!t1)
        return t2;
    if(!t2)
        return t1;

    TreeNode* new_tree = new TreeNode(t1->val+t2->val);

    new_tree->left = mergeTrees(t1->left, t2->left);
    new_tree->right = mergeTrees(t1->right, t2->right);

    return new_tree;
}
