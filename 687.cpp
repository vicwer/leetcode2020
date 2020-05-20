int longest = 0;

int findLongest(TreeNode* root, int val)
{
    if(!root)
        return 0;

    int left = findLongest(root->left, root->val);
    int right = findLongest(root->right, root->val);

    longest = std::max(longest, left+right);
    if(root->val == val)
        return std::max(left, right) + 1;
    return 0;
}

int longestUnivaluePath(TreeNode* root)
{
    if(!root)
        return 0;

    findLongest(root, root->val);

    return longest;
}
