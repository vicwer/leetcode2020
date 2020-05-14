#include <iostream>
#include <queue>
#include <vector>

struct Node
{
    int val;
    std::vectorN<Node*> children;


    Node() {}
    Node(int x) : val(x) {}
    Node(int x, std::vector<int> _children) {
        val = x;
        children = _children;
    }
};

std::vector<int> res;

std::vector<int> postorder(Node* root)
{
    if(!root)
        return res;

    for(int i = 0; i < root->children.size(); i++)
    {
        Node* cnt_root = root->children[i];
        postorder(cnt_root);
    }
    res.push_back(root->val);

    return res;
}
