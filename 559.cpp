#include <vector>
#include <iostream>
#include <queue>

struct Node
{
    int val;
    std::vector<Node*> children;

    Node() {}
    Node(int x) : val(x) {}
    Node(int x, std::vector<Node*> _children) : val(x), children(_children) {}
};

int maxDepth(TreeNode* root)
{
    if(!root)
        return 0;

    int cnt_max_depth = 0;
    for(int i = 0; i < root->children.size(); i++)
    {
        Node* cnt_root = root->children[i];
        int cnt_depth = maxDepth(cnt_root);
        cnt_max_depth = std::max(cnt_depth, cnt_max_depth);
    }
    return cnt_max_depth + 1;
}
