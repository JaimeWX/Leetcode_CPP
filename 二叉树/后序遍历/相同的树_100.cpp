class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if(p == nullptr && q != nullptr)    return false;
        if(p != nullptr && q == nullptr)    return false;
        if(p == nullptr && q == nullptr)    return true;
        if(p->val != q ->val)   return false;

        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);
        bool isSame = left && right;
        return isSame;
    }
};