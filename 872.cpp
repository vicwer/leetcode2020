class Solution {
public:
    void get(TreeNode*root, std::vector<int>& list)
    {
        if(!root)
            return;
        if(!root->left && !root->right)
        {
            list.push_back(root->val);
            return;
        }
        get(root->left, list);
        get(root->right, list);

        return;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        std::vector<int> root1_list;
        std::vector<int> root2_list;

        get(root1,root1_list);
        get(root2,root2_list);

        if(root1_list.size() == root2_list.size())
        {
            for(int i = 0; i < root1_list.size(); i++)
            {
                if(root1_list[i] != root2_list[i])
                {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
};
