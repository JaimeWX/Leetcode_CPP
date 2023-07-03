class Solution {
private:
    unordered_map<TreeNode*,int> height_map;

    int getHeight(TreeNode* root)
    {
        if(root == nullptr) // 空结点的高度为0
            return 0; 

        int left_height = getHeight(root->left);

        int right_height = getHeight(root->right);

        // cout << root->val << endl;
        // cout << "left_height: " << left_height << endl;
        // cout << "right_height: " << right_height << endl;
        height_map.insert(pair<TreeNode*,int>(root, 1+max(left_height,right_height)));
        return 1+max(left_height,right_height);
    }
public:
    void traversal_heightMap(unordered_map<TreeNode*,int> height_map)
    {
        // for(unordered_map<TreeNode*,int>::iterator it = height_map.begin(); it != height_map.end(); it++)
        // {
        //     cout << it->first->val << "--" << it->second << endl;
        // }
        for(auto&[k,v]:height_map)
	        cout << k->val << "--" << v << endl;
    }
};