#include <queue>
#include <vector>
#include <map>
#include <set>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void dfs(TreeNode* root, std::map<TreeNode*, TreeNode*>& umap)
    {
        if(!root)
            return;

        if(root->left)
            umap[root->left] = root;
        if(root->right)
            umap[root->right] = root;

        dfs(root->left, umap);
        dfs(root->right, umap);

        return;
    }

    std::vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
    {
        std::vector<int> res;
        if(k == 0)
        {
            res.push_back(target->val);
            return res;
        }

        std::map<TreeNode*, TreeNode*> umap;

        dfs(root, umap);

        std::queue<TreeNode*> queueTree;
        queueTree.push(target);

        std::set<TreeNode*> visitedNode;
        visitedNode.insert(target);

        int step = 0;
        while(!queueTree.empty())
        {
            step++;
            for(int i = queueTree.size(); i > 0; i--)
            {
                TreeNode* cnt_node = queueTree.front();
                queueTree.pop();
                
                if(cnt_node->left && !visitedNode.count(cnt_node->left))
                {
                    if(step == k)
                    {
                        res.push_back(cnt_node->left->val);
                    }

                    queueTree.push(cnt_node->left);
                    visitedNode.insert(cnt_node->left);

                }

                if(cnt_node->right && !visitedNode.count(cnt_node->right))
                {
                    if(step == k)
                    {
                        res.push_back(cnt_node->right->val);
                    }

                    queueTree.push(cnt_node->right);
                    visitedNode.insert(cnt_node->right);

                }

                if(umap[cnt_node] && !visitedNode.count(umap[cnt_node]))
                {
                    if(step == k)
                    {
                        res.push_back(umap[cnt_node]->val);
                    }

                    queueTree.push(umap[cnt_node]);
                    visitedNode.insert(umap[cnt_node]);

                }
            }

            if(step == k)
                break;
        }

        return res;
    }
};