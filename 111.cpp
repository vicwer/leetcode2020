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

int minDepth(BinaryTree* root)
{
    if(!root)
    {
        return 0;
    }
    return std::min(minDepth(root->left), minDepth(root->right)) + 1;
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
    std::vector<std::vector<int>> lists = {{3,9,20,-233,-233,15,7}, {1}, {1,2,3}, {1,2}, {}};
    CreateTree tree;
    for(auto list : lists)
    {
        BinaryTree* root = tree.createTree(list);
        int res = minDepth(root);

        std::cout << res << std::endl;
    }
    return 0;
}