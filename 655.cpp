#include <iostream>
#include <vector>
#include <queue>
#include <string>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int depth = 0;

int maxDepth(TreeNode* root)
{
    if(!root)
        return 0;

    return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

void print(TreeNode* root, int cnt_depth, std::vector<std::vector<std::string>>& res, int loc)
{
    if(!root)
        return;

    res[cnt_depth][loc] = std::to_string(root->val);

    if(!root->left && !root->right)
        return;

    int dis = 1<<(depth-cnt_depth-2);

    if(root->left)
        print(root->left, cnt_depth+1, res, loc-dis);
    if(root->right)
        print(root->right, cnt_depth+1, res, loc+dis);
    return;
}

std::vector<std::vector<std::string>> printTree(TreeNode* root)
{
    depth = maxDepth(root);

    std::vector<std::vector<std::string>> res(depth, std::vector<std::string>((1<<depth)-1,""));

    print(root, 0, res, res[0].size()>>1);

    return res;
}
