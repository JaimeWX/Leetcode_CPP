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
    bool backtracking(TreeNode* root, int targetSum)
    {
        path.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr)
        {   
            int sum = 0;
            for(int i=0; i<path.size(); i++)
            {
                sum += path[i];
            }
            if(sum == targetSum)
            {   
                return true;
            }
            else
            {
                return false;
            }
        }
        if(root->left)  
        {
            if(backtracking(root->left, targetSum)) return true;
            path.pop_back();
        }
        if(root->right)
        {
            if(backtracking(root->right, targetSum)) return true;
            path.pop_back();
        }
        return false;
    }
public:
    
    bool hasPathSum(TreeNode* root, int targetSum) 
    {   
        if(root == nullptr) return false;
        return backtracking(root,targetSum);
    }
};