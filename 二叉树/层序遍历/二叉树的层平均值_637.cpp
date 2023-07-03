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
    vector<vector<int>> level_traversal(TreeNode* root)
    {
        vector<vector<int>> vecs;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            int size = que.size();
            vector<int> vec;
            for(int i=0; i<size; i++)
            {
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if(node->left)  que.push(node->left);
                if(node->right) que.push(node->right);
            }
            vecs.push_back(vec);
        } 
        return vecs;
    }
public:
    vector<double> averageOfLevels(TreeNode* root) 
    {   
        vector<double> res;
        vector<vector<int>> vecs = level_traversal(root);
        for(int i=0; i<vecs.size(); i++)
        {
            double mean = accumulate(vecs[i].begin(), vecs[i].end(), 0.0) / vecs[i].size();
            res.push_back(mean);
        }
        return res;
    }
};