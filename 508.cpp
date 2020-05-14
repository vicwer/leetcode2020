#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

std::unordered_map<int, int> map;

int findFrequentTreeSum1(TreeNode* root)
{
    if(!root)
        return 0;

    int sum = root->val;
    if(root->left)
        sum += findFrequentTreeSum1(root->left);
    if(root->right)
        sum += findFrequentTreeSum1(root->right);

    if(map.count(sum) > 0)
        map[sum] += 1;
    else
        map.insert({sum, 1});

    return sum;
}

std::vector<int> findFrequentTreeSum(TreeNode* root)
{

    findFrequentTreeSum1(root);

    std::vector<int> res;
    int maxFrequent = 0;
    for(auto i : map)
    {
        int key = i.first;
        int val = i.second;
        maxFrequent = val > maxFrequent ? val : maxFrequent;
    }

    for(auto i : map)
    {
        int key = i.first;
        int val = i.second;
        if(val == maxFrequent)
            res.push_back(key);
    }

    return res;
}
