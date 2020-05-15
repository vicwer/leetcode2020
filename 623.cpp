#include <iostream>
#include <queue>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode* root)
{
    if(!root)
        return 0;

    return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

TreeNode* addOneRow(TreeNode* root, int v, int d)
{
    if(d == 1)
    {
        TreeNode* cnt_root = new TreeNode(v);
        cnt_root->left = root;
        return cnt_root;
    }

    int max_depth = maxDepth(root);

    std::queue<TreeNode*> cnt_layer;
    cnt_layer.push(root);

    int cnt_depth = 0;
    while(!cnt_layer.empty())
    {
        cnt_depth += 1;
        int size = cnt_layer.size();
        for(int i = 0; i < size; i++)
        {
            TreeNode* cnt_root = cnt_layer.front();
            cnt_layer.pop();

            if(d - 1 == cnt_depth)
            {
                TreeNode* left = cnt_root->left;
                TreeNode* right = cnt_root->right;

                TreeNode* new_left = new TreeNode(v);
                TreeNode* new_right = new TreeNode(v);
                cnt_root->left = new_left;
                new_left->left = left;
                cnt_root->right = new_right;
                new_right->right = right;
            }
            else
            {
                if(cnt_root->left)
                    cnt_layer.push(cnt_root->left);
                if(cnt_root->right)
                    cnt_layer.push(cnt_root->right);
            }
        }
        if(d - 1 == cnt_depth)
        {
            break;
        }
    }

    return root;
}
