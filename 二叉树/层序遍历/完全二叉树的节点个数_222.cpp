class Solution {
private:
    int levelTraversal(TreeNode* root, int count)
    {
        if(root == nullptr) return count;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            int size = que.size();
            for(int i=0; i<size; i++)
            {
                TreeNode* node = que.front();
                que.pop();
                count += 1;
                if(node->left)  que.push(node->left);
                if(node->right) que.push(node->right);
            }
        } 
        return count;
    }
public:
    int countNodes(TreeNode* root) 
    {
        return levelTraversal(root, 0);
    }
};