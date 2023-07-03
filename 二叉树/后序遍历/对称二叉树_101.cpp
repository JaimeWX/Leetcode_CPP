struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){};
};


class Solution {
private:
    bool compare(TreeNode* left, TreeNode* right)
    {
        if(left == nullptr && right != nullptr) return false;
        else if(left != nullptr && right == nullptr)    return false;
        else if(left == nullptr && right == nullptr) return true;
        else if(left->val != right->val)    return false;

        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left);
        bool isSame = outside && inside;
        return isSame;
    }
public:
    bool isSymmetric(TreeNode* root) 
    {
        if(root == nullptr) return true;
        return compare(root->left, root->right);
    }
};