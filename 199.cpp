#include <iostream>
#include <vector>
#include <queue>

struct BinaryTree
{
    int val;
    BinaryTree* left;
    BinaryTree* right;
};

std::vector<int> rightSideView(BinaryTree* root)
{
    std::vector<int> res;
    if(!root)
        return res;

    std::queue<BinaryTree*> cnt_layer;
    cnt_layer.push(root);

    while(!cnt_layer.empty())
    {
        
        int size = cnt_layer.size();
        for(int i = 0; i < size; i++)
        {
            BinaryTree* cnt_root = cnt_layer.front();
            cnt_layer.pop();
            if(i == 0)
            {
                res.push_back(cnt_root->val);
            }
            if(cnt_root->right)
                cnt_layer.push(cnt_root->right);
            if(cnt_root->left)
                cnt_layer.push(cnt_root->left);
        }
    }

    return res;
}