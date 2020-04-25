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

std::vector<int> res;
std::vector<int> inorderTransversal(BinaryTree* tree)
{
    if(tree)
    {
        inorderTransversal(tree->left);
        res.push_back(tree->val);
        inorderTransversal(tree->right);
    }

    return res;
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
    std::vector<std::vector<int> > test_cases = {{}, {1}, {1, -233, 2, 3}};

    for(auto test_case : test_cases)
    {
        CreateTree* tree;
        BinaryTree* root = tree->createTree(test_case);
        res.clear();
        res = inorderTransversal(root);
        for(auto i : res)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;

    }
    return 0;
}