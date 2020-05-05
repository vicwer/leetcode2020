#include <iostream>
#include <vector>
#include <queue>

struct BinaryTree
{
    int val;
    BinaryTree* left;
    BinaryTree* right;

    BinaryTree(int x) : val(x), left(NULL), right(NULL) {};
};

std::vector<int> func(BinaryTree* root)
{
    std::vector<int> res;
    std::queue<BinaryTree*> cnt_root;
    if(!root)
    {
        return res;
    }
    cnt_root.push(root);
    while(!cnt_root.empty())
    {
        BinaryTree* tree = cnt_root.front();
        res.push_back(tree->val);
        cnt_root.pop();
        if(tree->left)
        {
            cnt_root.push(tree->left);
        }
        if(tree->right)
        {
            cnt_root.push(tree->right);
        }
    }

    return res;
}

std::vector<std::vector<int>> levelOrder(BinaryTree* root)
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
            cnt_layer.pop();
            cnt_res.push_back(cnt_root->val);
            if(cnt_root->left)
            {
                cnt_layer.push(cnt_root->left);
            }
            if(cnt_root->right)
            {
                cnt_layer.push(cnt_root->right);
            }
        }
        if(!cnt_res.empty())
            res.push_back(cnt_res);
    }

    return res;
}

class CreateTree {
public:
    BinaryTree* createTree(std::vector<int> list);
};

BinaryTree* CreateTree::createTree(std::vector<int> list)
{
    BinaryTree* root = new BinaryTree(0);
    std::queue<BinaryTree*> queue_list;
    if(!list.empty())
    {
        root->val = list[0];
        queue_list.push(root);
    }

    int idx = 1;
    while(!queue_list.empty())
    {
        BinaryTree* cnt_root = queue_list.front();
        queue_list.pop();
        if(idx < list.size())
        {
            if(list[idx] != -233)
            {
                BinaryTree* left = new BinaryTree(list[idx]);
                cnt_root->left = left;
                queue_list.push(left);
            }
            idx++;
        }
        if(idx < list.size())
        {
            if(list[idx] != -233)
            {
                BinaryTree* right = new BinaryTree(list[idx]);
                cnt_root->right = right;
                queue_list.push(right);
            }
            idx++;
        }
    }

    return root;
}

int main()
{
    std::vector<int> list = {1,2,3,-233,4,6,8,-233,5,-233,7,9,-233,-233,-233,-233,-233,-233,10};
    CreateTree tree;
    BinaryTree* root = tree.createTree(list);
    std::vector<int> res = func(root);
    for(auto val : res)
        std::cout << val << std::endl;

    return 0;
}