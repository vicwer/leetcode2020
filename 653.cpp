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

std::vector<int> list;

void inorder(TreeNode* root)
{
    if(!root)
        return;

    inorder(root->left);
    list.push_back(root->val);
    inorder(root->right);

    return;
}

bool findTarget(TreeNode* root, int k)
{
    inorder(root);

    int left = 0;
    int right = list.size() - 1;

    while(left < right)
    {
        if(list[left] + list[right] < k)
        {
            left++;
        }
        else if(list[left] + list[right] > k)
        {
            right--;
        }
        else
        {
            return true;
        }
    }

    return false;
}
