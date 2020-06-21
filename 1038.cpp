class Solution {
    int cnt_sum = 0;
public:
    TreeNode* bstToGst(TreeNode* root) {
        if(!root)
            return NULL;

        bstToGst(root->right);
        cnt_sum += root->val;
        root->val = cnt_sum;
        bstToGst(root->left);

        return root;
    }
};
