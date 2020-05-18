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

int findMaxValIdx(std::vector<int>& nums, int left, int right)
{
    int maxVal = nums[left];
    int idx = left;
    for(int i = left; i <= right; i++)
    {
        maxVal = maxVal > nums[i] ? maxVal : nums[i];
        if(maxVal == nums[i])
            idx = i;
    }

    return idx;
}

TreeNode* buildTree(std::vector<int>& nums, int left, int right)
{
    if(left > right)
        return NULL;

    int maxValIdx = findMaxValIdx(nums, left, right);

    TreeNode* root = new TreeNode(nums[maxValIdx]);

    root->left = buildTree(nums, left, maxValIdx-1);
    root->right = buildTree(nums, maxValIdx+1, right);

    return root;
}

TreeNode* constructMaximumBinaryTree(std::vector<int>& nums)
{
    int left = 0;
    int right = nums.size() - 1;
    TreeNode* root = buildTree(nums, left, right);
    return root;
}
