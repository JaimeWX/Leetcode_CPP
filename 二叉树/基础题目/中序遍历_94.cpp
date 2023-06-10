#include <vector>
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
private:
    void traversal(TreeNode* root, vector<int>& vec)
    {
        if(root == nullptr)
            return ;
        
        traversal(root->left, vec);

        vec.push_back(root->val);

        traversal(root->right, vec);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> vec;
        traversal(root, vec);
        return vec;
    }
};

