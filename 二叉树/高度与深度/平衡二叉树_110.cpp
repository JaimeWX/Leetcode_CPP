class Solution {
private:
    int getHeight(TreeNode* root)
    {
        if(root == nullptr) // 空结点的高度为0
            return 0; 

        int left_height = getHeight(root->left);
        if(left_height == -1)   return -1;    

        int right_height = getHeight(root->right);
        if(right_height == -1)  return -1; 

        return abs(left_height-right_height) > 1 ? -1 : 1+max(left_height,right_height);
    }
public:
    bool isBalanced(TreeNode* root)
    {   
        int res = getHeight(root);
        return res == -1 ? false : true;
    }

};