#include <iostream>
#include <vector>
#include <queue>
#include <string>

struct BinaryTree
{
    int val;
    BinaryTree* left;
    BinaryTree* right;

    BinaryTree(int x) : val(x), left(NULL), right(NULL) {}
};

int depth(BinaryTree* root)
{
    if(!root)
        return 0;

    return std::max(depth(root->left), depth(root->right)) + 1;
}

std::string serialize(BinaryTree* root)
{
    std::string res;

    if(!root)
        return res;

    int depth = depth(root);

    std::queue<BinaryTree*> cnt_layer;
    cnt_layer.push(root);

    int cnt_depth = 1;
    while(!cnt_layer.empty())
    {
        cnt_depth += 1;
        int size = cnt_layer.size();
        for(int i = 0; i < size; i++)
        {
            BinaryTree* cnt_root = cnt_layer.front();
            cnt_layer.pop();
            res = res + std::to_string(cnt_root->val) + ",";
            if(cnt_root->left)
                cnt_layer.push(cnt_root->left);
            else if(cnt_depth < depth)
                res = res + "null" + ",";
            if(cnt_root->right)
                cnt_layer.push(cnt_root->right);
            else if(cnt_depth < depth)
                res = res + "null" + ",";
        }
    }
    res.pop_back();

    res = "[" + res + "]";

    return res;
}

std::vector<std::string> split(std::string data)
{
    data.pop_back();
    data.erase(data.begin());
    std::vector<std::string> res;
    std::istringstream iss(data);
    std::string tmp;

    while(getline(iss, tmp, ','))
    {
        res.push_back(tmp);
    }

    return res;
}
std::string deserialize(std::string data)
{
    
    if(data.empty())
        return NULL;

    std::vector<std::string> data_list = split(data);

    if(data_list[0] == "null")
        return NULL;

    BinaryTree* root = new BinaryTree(atoi(data_list[0].c_str()));

    std::queue<BinaryTree*> cnt_layer;
    cnt_layer.push(root);
    for(int i = 1; i < data_list.size(); i++)
    {
        BinaryTree* cnt_root = cnt_layer.front();
        cnt_layer.pop();

        if(data_list[i] != "null")
        {
            BinaryTree* left = new BinaryTree(atoi(data_list[i].c_str()));
            cnt_root->left = left;
            cnt_layer.push(left);
        }
        else
        {
            i++;
        }
        i++;
        if(data_list[i] != "null")
        {
            BinaryTree* right = new BinaryTree(atoi(data_list[i].c_str()));
            cnt_root->right = right;
            cnt_left.push(right);
        }
        else
        {
            i++;
        }
    }

    return root;
}
