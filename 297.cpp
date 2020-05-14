#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>

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
    else
        return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

std::string serialize(TreeNode* root)
{
    std::stringstream res = "";
    if(!root)
        return res.str();

    int depth = maxDepth(root);

    std::queue<TreeNode*> cnt_layer;
    cnt_layer.push(root);

    int cnt_depth = 0;
    while(!cnt_layer.empty())
    {
        cnt_depth += 1;

        int size = cnt_layer.size();
        for(int i = 0 ;i < size; i++)
        {
            TreeNode* cnt_root = cnt_layer.front();
            cnt_layer.pop();
            if(!cnt_root)
            {
                // res = res + "#,";
                res << "#,";
                continue;
            }
            else
            {
                // res = res + std::to_string(cnt_root->val)+",";
                res << cnt_root->val;
                res << ",";
                if(cnt_depth < depth)
                {
                    cnt_layer.push(cnt_root->left);
                    cnt_layer.push(cnt_root->right);
                }
            }
        }
    }

    std::string ret = res.str();
    ret.pop_back();
    ret = "[" + ret + "]";

    return ret;
}

std::vector<std::string> split(std::string data)
{
    data.erase(data.begin());
    data.pop_back();
    std::vector<std::string> res;
    istringstream iss(data);

    std::string tmp;
    while(getline(iss, tmp, ','))
    {
        res.push_back(tmp);
    }

    return res;
}

TreeNode* deserialize(std::string data)
{
    if(data.empty())
        return NULL;

    std::vector<std::string> data_list = split(data);

    TreeNode* root = new TreeNode(atoi(data_list[0].c_str()));
    std::queue<TreeNode*> cnt_layer;
    cnt_layer.push(root);

    for(int i = 1; i < data_list.size();)
    {
        TreeNode* cnt_root = cnt_layer.front();
        cnt_layer.pop();

        if(i < data_list.size())
        {
            if(data_list[i] != "#")
            {
                TreeNode* left = new TreeNode(atoi(data_list[i].c_str()));
                cnt_root->left = left;
                cnt_layer.push(left);
            }
            i++;
            if(data_list[i] != "#")
            {
                TreeNode* right = new TreeNode(atoi(data_list[i].c_str()));
                cnt_root->right = right;
                cnt_layer.push(right);
            }
            i++;
        }
    }

    return root;
}
