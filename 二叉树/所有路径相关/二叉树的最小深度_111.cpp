/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    vector<int> path;
    vector<int> all_path_len;
    void backtracking(TreeNode* root)
    {   
        path.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr)
        {
            all_path_len.push_back(path.size());
            return ;
        }
        if(root->left)
        {
            backtracking(root->left);
            path.pop_back();
        }
        if(root->right)
        {
            backtracking(root->right);
            path.pop_back();
        }
    }
public:
    int minDepth(TreeNode* root) 
    {
        if(root==nullptr)   return 0;
        int res = INT_MAX;
        backtracking(root);
        for(int i=0; i<all_path_len.size(); i++)
        {
            if(all_path_len[i] < res)
                res = all_path_len[i];
        }
        return res;
    }
};