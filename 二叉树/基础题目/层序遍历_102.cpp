#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> res;
        queue<TreeNode*> que;
        if(root != nullptr)   que.push(root);
        while(!que.empty())
        {
            vector<int> vec;
            int size = que.size();
            for(int i=0; i<size; i++)
            {
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if(node->left != nullptr)  que.push(node->left);
                if(node->right != nullptr) que.push(node->right);
            }
            res.push_back(vec);
        }
        return res;
    }
};