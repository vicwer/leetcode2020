#include <iostream>
#include <vector>
#include <queue>

struct Node
{
    int val;
    std::vector<Node*> children;

    Node() {}
    Node(int x) : val(x) {}
    Node(int x, std::vector<Node*> _children) {
        val = x;
        children = _children;
    }
};


std::vector<int> res;
std::vector<int> preorder(Node* root)
{
    if(!root)
        return res;

    res.push_back(root->val);
    for(int i = 0; i < root->children.size(); i++)
    {
        Node* cnt_root = root->children[i];
        preorder(cnt_root);
    }

    return res;
}
