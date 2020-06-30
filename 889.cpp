class Solution {
public:
    TreeNode* helper(vector<int> pre, vector<int> post, int prestart, int preend, int poststart, int postend)
    {
        if(prestart > preend || poststart > postend)
            return NULL;
        
        TreeNode* node = new TreeNode(pre[prestart]);
        if(prestart == preend)
            return node;
        int index = 0;
        while(post[index] != pre[prestart+1])
        {
            index++;
        }

        node->left = helper(pre, post, prestart+1, prestart+1+index-poststart, poststart, index);
        node->right = helper(pre, post, prestart+2+index-poststart, preend, index+1, preend-1);

        return node;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return helper(pre, post, 0, pre.size()-1, 0, post.size()-1);
    }
};
