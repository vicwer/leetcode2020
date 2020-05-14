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

bool isSameTree(TreeNode* s, TreeNode* t)
{
    if(!s && !t)
        return true;
    if((!s && t) || (s && !t))
        return false;

    return isSameTree(s->left, t->left) && isSameTree(s->right, t->right) && s->val == t->val;
}

bool isSubtree(TreeNode* s, TreeNode* t)
{
    bool res = isSameTree(s, t);
    if(res)
        return res;
    if(s)
    {
        res = isSubtree(s->left, t);
        if(res)
            return res;
        res = isSubtree(s->right, t);
        if(res)
            return res;
    }

    return res;
}
