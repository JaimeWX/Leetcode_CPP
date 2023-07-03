class Solution {
private:
    vector<string> vec;
    string path; 
    void backtracking(TreeNode* root)
    {   
        path += to_string(root->val);
        if(root->left == nullptr && root->right == nullptr)
        {
            vec.push_back(path);
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
    int sumNumbers(TreeNode* root) 
    {
        backtracking(root);
        int sum = 0;
        for(string s : vec)
        {
            sum += stoi(s);
        }
        return sum;
    }
};