#include <iostream>
#include <vector>
#include <queue>
#include <stack>

struct BinaryTree
{
    int val;
    BinaryTree* left;
    BinaryTree* right;

    BinaryTree(int x) : val(x), left(NULL), right(NULL) {};
};

std::vector<std::vector<int>> func(BinaryTree* root)
{
    std::vector<std::vector<int>> res;
    if(!root)
        return res;

    std::queue<std::stack<BinaryTree*>> cnt_layer;

    std::stack<BinaryTree*> stack_layer;
    stack_layer.push(root);
    cnt_layer.push(stack_layer);

    int idx = 0;
    while(!cnt_layer.empty())
    {
        
        std::stack<BinaryTree*> cnt_stack = cnt_layer.front();

        cnt_layer.pop();

        std::stack<BinaryTree*> new_stack;
        std::vector<int> cnt_res;
        while(!cnt_stack.empty())
        {
            BinaryTree* cnt_root = cnt_stack.top();
            cnt_stack.pop();
            cnt_res.push_back(cnt_root->val);
            if(idx % 2 == 1)
            {
                if(cnt_root->right)
                    new_stack.push(cnt_root->right);
                if(cnt_root->left)
                    new_stack.push(cnt_root->left);
            }
            else
            {
                if(cnt_root->left)
                    new_stack.push(cnt_root->left);
                if(cnt_root->right)
                    new_stack.push(cnt_root->right);
            }
        }
        res.push_back(cnt_res);
        idx++;
        if(!new_stack.empty())
            cnt_layer.push(new_stack);
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
    std::vector<int> list = {3,9,20,-233,-233,15,7};
    CreateTree tree;
    BinaryTree* root = tree.createTree(list);
    std::vector<std::vector<int>> res = func(root);

    for(auto i : res)
    {
        for(auto j : i)
            std::cout << j << std::endl;
    }

    return 0;
}



