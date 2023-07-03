class Solution {
private:
    int res;

    void backtracking(TreeNode* root, int depth)
    {
        res = depth > res ? depth : res;
        if(root->left == nullptr && root->right == nullptr)
        {
            return ;
        }

        if(root->left)
        {
            depth++;
            backtracking(root->left, depth);
            depth--;
        }

        if(root->right)
        {
            depth++;
            backtracking(root->right, depth);
            depth--;
        }

        return ;
    }
public:
    int maxDepth(TreeNode* root) 
    {
        res = 0;
        if(root == nullptr) return res;
        backtracking(root, 1);
        return res;
    }
};