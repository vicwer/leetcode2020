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

bool sameTree(BinaryTree* root1, BinaryTree* root2)
{
    if(!root1 && !root2)
    {
        return true;
    }
    else if(root1 && root2)
    {
        return sameTree(root1->left, root2->left) && sameTree(root1->right, root2->right) && root1->val == root2->val;
    }
    else
    {
        return false;
    }
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
    std::vector<std::vector<int> > list = {{1,2,3}, {1,2,3}, {1}, {2}, {1,2}, {1}};
    CreateTree tree;
    for(int i = 0; i < list.size(); i+=2)
    {
        BinaryTree* root1 = tree.createTree(list[i]);
        BinaryTree* root2 = tree.createTree(list[1+1]);
        std::cout << sameTree(root1, root2) << std::endl;
    }

    return 0;
}