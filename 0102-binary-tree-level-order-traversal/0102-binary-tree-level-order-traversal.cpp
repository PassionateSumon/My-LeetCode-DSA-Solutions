class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        vector<int> ds;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()) {
                TreeNode* node = q.front();
                q.pop();
                if(node == NULL) {
                    ans.push_back(ds);
                    ds.resize(0);
                    if(!q.empty()) q.push(NULL);
                } else {
                    ds.push_back(node->val);
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                }
        } 
        return ans;
    }
};