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
    TreeNode* traversal(vector<int>& pre, int ps, int pe, vector<int>& in, int is, int ie)
    {   
        if(ps == pe)    return nullptr;

        int rootValue = pre[ps];
        TreeNode* root = new TreeNode(rootValue);
        if(pe -ps == 1) return root;

        int splitInx;
        for(int i=0; i<in.size(); i++)
        {
            if(in[i] == rootValue)
            {
                splitInx = i;
                break;
            }
        }

        int l_in_s = is;
        int l_in_e = splitInx;
        int r_in_s = splitInx + 1;
        int r_in_e = ie;

        int l_pre_s = ps + 1;
        int l_pre_e = ps + 1 + splitInx - is;
        int r_pre_s = ps + 1 + splitInx - is;
        int r_pre_e = pe;

        root->left = traversal(pre, l_pre_s, l_pre_e, in, l_in_s, l_in_e);
        root->right = traversal(pre, r_pre_s, r_pre_e, in, r_in_s, r_in_e);

        return root;


    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        if (inorder.size() == 0 || preorder.size() == 0) return nullptr;
        return traversal(preorder, 0, preorder.size(), inorder, 0, inorder.size()); // 左闭右开
    }
};