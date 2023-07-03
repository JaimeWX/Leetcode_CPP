class Solution {
private:
    void invert(TreeNode* root)
    {
        if(root == nullptr) return ;
        swap(root->left, root->right);
        invert(root->left);
        invert(root->right);
    }
public:
    TreeNode* invertTree(TreeNode* root) 
    {
        invert(root);
        return root;
    }
};
