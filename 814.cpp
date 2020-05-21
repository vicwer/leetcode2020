bool prune(TreeNode* root)
{
    if(!root)
        return false;

    return root->val == 1 || prune(root->left) || prune(root->right);
}
TreeNode* pruneTree(TreeNode* root)
{
    if(!root)
        return NULL;

    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    if(prune(root))
        return root;
    else
        return NULL;
}
