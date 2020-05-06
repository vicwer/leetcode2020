#include <iostream>
#include <vector>
#include <queue>

struct BinaryNode
{
    int val;
    BinaryNode* left;
    BinaryNode* right;
    BinaryNode* next;
};

BinaryNode* connect(BinaryNode* root)
{
    if(!root)
    {
        return root;
    }

    BinaryNode* res = root;
    std::queue<BinaryNode*> cnt_layer;
    cnt_layer.push(root);

    while(!cnt_layer.empty())
    {
        int size = cnt_layer.size();
        BinaryNode* tmp = cnt_layer.front();
        if(tmp->left)
            cnt_layer.push(tmp->left);
        if(tmp->right)
            cnt_layer.push(tmp->right);
        cnt_layer.pop();
        for(int i = 0; i < size - 1; i++)
        {
            BinaryNode* cnt_root = cnt_layer.front();
            if(cnt_root->left)
                cnt_layer.push(cnt_root->left);
            if(cnt_root->right)
                cnt_layer.push(cnt_root->right);
            tmp->next = cnt_root;
            tmp = cnt_root;
            cnt_layer.pop();
        }
        tmp->next = NULL;
    }

    return res;
}

BinaryNode* connect(BinaryNode* root)
{
    if(!root)
    {
        return root;
    }

    BinaryNode* res = root;
    std::queue<BinaryNode*> cnt_layer;
    cnt_layer.push(root);

    while(!cnt_layer.empty())
    {
        int size = cnt_layer.size();
        for(int i = 0; i < size; i++)
        {
            BinaryNode* cnt_root = cnt_layer.front();
            cnt_layer.pop();
            if(cnt_root->left)
                cnt_layer.push(cnt_root->left);
            if(cnt_root->right)
                cnt_layer.push(cnt_root->right);
            if(i < size - 1)
                cnt_root->next = cnt_layer.front();
        }
    }

    return res;
}
