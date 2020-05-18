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

int max = 0;

void findMaxWidth(TreeNode* root, int depth, unsigned long long idx, std::vector<int>& left_list)
{
    if(!root)
        return;

    if(depth > left_list.size())
        left_list.push_back(idx);
    max = max > (idx - left_list[depth-1] + 1) ? max : (idx - left_list[depth-1] + 1);

    findMaxWidth(root->left, depth+1, idx*2, left_list);
    findMaxWidth(root->right, depth+1, idx*2+1, left_list);

    return;
}

int widthOfBinaryTree(TreeNode* root)
{
    std::vector<int> left_list;

    findMaxWidth(root, 1, 1, left_list);

    return max;
}
