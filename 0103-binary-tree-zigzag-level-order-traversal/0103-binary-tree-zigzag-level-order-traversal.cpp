class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        vector<int> ds;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        q.push({NULL, 0});
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int lvl = p.second;
            if(node == NULL) {  
                if((lvl%2)!= 0) {
                    reverse(ds.begin(), ds.end());
                } 
                ans.push_back(ds);
                ds.resize(0);
                if(q.empty()) break;
                else q.push({NULL, lvl+1});
            } else {
                ds.push_back(node->val);
                if(node->left) q.push({node->left, lvl+1});
                if(node->right) q.push({node->right, lvl+1});
            }
        }
        return ans;
    }
};