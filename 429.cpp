#include <iostream>
#include <vector>
#include <queue>
#include <string>

class Node
{
    int val;
    std::vector<Node*> children;

    Node() {}

    Node(int x)
    {
        val = x;
    }

    Node(int x, std::vector<Node*> _children)
    {
        val = x;
        children = _children;
    }
};

std::vector<std::vector<int>> levelOrder(Node* root)
{
    std::vector<std::vector<int>> res;

    if(!root)
        return res;

    std::queue<Node*> cnt_layer;
    cnt_layer.push(root);

    while(!cnt_layer.empty())
    {
        int size = cnt_layer.size();

        std::vector<int> cnt_res;
        for(int i = 0; i < size; i++)
        {
            Node* cnt_root = cnt_layer.front();
            cnt_layer.pop();
            cnt_res.push_back(cnt_root->val);

            std::vector<Node*> cnt_child = cnt_root->children;
            for(int j = 0; j < cnt_child.size(); j++)
            {
                cnt_layer.push(cnt_child[j]);
            }
        }
        if(!cnt_res.empty())
            res.push_back(cnt_res);
    }

    return res;
}