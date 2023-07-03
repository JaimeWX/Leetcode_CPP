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
    TreeNode* traversal(vector<int>& in, int is, int ie, vector<int>& pos, int ps, int pe)
    {
        if(ps == pe) return nullptr;

        int rootValue = pos[pe-1];
        TreeNode* root = new TreeNode(rootValue);

        if(pe-ps == 1)  return root;

        int splitIdx;
        for(int i=0; i<in.size(); i++)
        {
            if(in[i] == rootValue)
            {
                splitIdx = i;
                break;
            }

        }

        int l_i_s = is;
        int l_i_e = splitIdx;
        int r_i_s = splitIdx+1;
        int r_i_e = ie;

        int l_p_s = ps;
        int l_p_e = ps+(splitIdx-is);
        int r_p_s = ps+(splitIdx-is);
        int r_P_e = pe-1;

        root->left = traversal(in, l_i_s, l_i_e, pos, l_p_s, l_p_e);
        root->right = traversal(in,r_i_s,r_i_e, pos, r_p_s,r_P_e);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        if(inorder.size() == 0 || postorder.size() == 0)    return nullptr;
        return traversal(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};