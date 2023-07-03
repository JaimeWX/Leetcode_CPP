class Solution {
public:
    int maxDepth(TreeNode* root) 
    {
        if(root == nullptr) return 0;

        int left = maxDepth(root->left);

        int right = maxDepth(root->right);

        int max_depth = 1 + max(left,right);

        return max_depth;
    }
};