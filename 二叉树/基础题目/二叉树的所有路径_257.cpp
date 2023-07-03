class Solution {
private:
    vector<string> res;
    vector<int> path;
    
    void backtracking(TreeNode* root)
    {
        path.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr)
        {
            string s_path;
            for(int i=0; i<path.size(); i++)
            {
                s_path += to_string(path[i]);
                if(i != path.size()-1)
                    s_path += "->";
            }
            res.push_back(s_path);
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
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        backtracking(root);        
        return res;
    }
};