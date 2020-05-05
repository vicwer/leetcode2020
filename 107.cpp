#include <vector>
#include <iostream>
#include <queue>

struct BinaryTree
{
    int val;
    BinaryTree* left;
    BinaryTree* right;
};

std::vector<std::vector<int>> levelOrderBottom(BinaryTree* root)
{
    std::vector<std::vector<int>> res;
    std::vector<int> cnt_res;

    if(!root)
        return res;

    std::queue<BinaryTree*> cnt_layer;
    std::vector<std::queue<BinaryTree*>> layers;
    cnt_layer.push(root->val);
    layers.push_back(cnt_layer);
    
    while(!layers.empty())
    {
        std::queue<BinaryTree*> cnt = layers[0];
        layers.clear();
        std::queue<BinaryTree*> new_layer;

        while(!cnt.empty())
        {
            BinaryTree* cnt_root = cnt.front();
            cnt_res.push_back(cnt_root->val);
            cnt.pop();

            if(cnt_root->left)
            {
                new_layer.push(cnt_root->left);
            }
            if(cnt_root->right)
            {
                new_layer.push(cnt_root->right);
            }
        }
        res.insert(res.begin(), cnt_res);
        cnt_res.clear();
        if(!new_layer.empty())
            layers.push_back(new_layer);
    }

    return res;
}

std::vector<std::vector<int>> levelOrderBottom(BinaryTree* root)
{
    std::vector<std::vector<int>> res;

    if(!root)
        return res;

    std::queue<BinaryTree*> cnt_layer;
    cnt_layer.push(root);

    while(!cnt_layer.empty())
    {
        std::vector<int> cnt_res;
        int size = cnt_layer.size();
        for(int i = 0; i < size; i++)
        {
            BinaryTree* cnt_root = cnt_layer.front();
            cnt_res.push_back(cnt_root->val);
            cnt_layer.pop();

            if(cnt_root->left)
                cnt_layer.push(cnt_root->left);
            if(cnt_root->right)
                cnt_layer.push(cnt_root->right);
        }

        if(!cnt_res.empty())
            res.insert(res.begin(), cnt_res);
    }

    return res;
}
