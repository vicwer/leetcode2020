/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int depth(TreeNode* root)
    {
        if(!root)
            return 0;
        else
            return std::max(depth(root->left), depth(root->right)) + 1;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root)
            return NULL;
        else
        {
            int left_depth = depth(root->left);
            int right_depth = depth(root->right);

            if(left_depth == right_depth)
            {
                return root;
            }
            else if(left_depth > right_depth)
            {
                return subtreeWithAllDeepest(root->left);
            }
            else
            {
                return subtreeWithAllDeepest(root->right);
            }
        }
    }
};
