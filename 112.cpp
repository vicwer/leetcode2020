#include <iostream>
#include <vector>
#include <queue>

struct BinaryTree
{
    int val;
    BinaryTree* left;
    BinaryTree* right;

    BinaryTree(int x): val(x), left(NULL), right(NULL) {};
};

bool hasPathSum(BinaryTree* root, int sum)
{
    if(!root)
        return 0;
    if(!root->left && !root->right)
    {
        return sum - root->val == 0;
    }
    return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
}

class CreateTree {
public:
    BinaryTree* createTree(std::vector<int> list);
};

BinaryTree* CreateTree::createTree(std::vector<int> list)
{
    if(list.empty())
        return NULL;
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
    std::vector<int> list = {5,4,8,11,-233,13,4,7,2,-233,-233,-233,1};
    CreateTree tree;
    BinaryTree* root = tree.createTree(list);
    bool res = hasPathSum(root, 22);

    std::cout << res << std::endl;

    return 0;
}