class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode*> res;
        if(N % 2 == 0)
            return res;
        if(N == 1)
        {
            TreeNode* root = new TreeNode(0);
            res.push_back(root);
        }
        else
        {
            for(int i = 1; i <= N-2; i+=2)
            {
                for(auto left : allPossibleFBT(i))
                {
                    for(auto right : allPossibleFBT(N-i-1))
                    {
                        TreeNode* root = new TreeNode(0);
                        root->left = left;
                        root->right = right;
                        res.push_back(root);
                    }
                }
            }
        }

        return res;
    }
};
