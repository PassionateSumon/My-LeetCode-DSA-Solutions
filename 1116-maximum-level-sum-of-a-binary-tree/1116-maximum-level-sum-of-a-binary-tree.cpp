class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        q.push({NULL, 1});
        int ans = INT_MIN, sum = 0, level = 0;
        while(!q.empty()) {
            TreeNode* curr = q.front().first;
            int lvl = q.front().second;
            q.pop();
            if(curr == NULL) {
                if(ans < sum) {
                    ans = sum;
                    level = lvl;
                }
                sum = 0;
                if(q.empty()) break;
                else q.push({NULL,lvl+1});
            } else {
                sum += curr->val;
                if(curr->left) q.push({curr->left,lvl+1});
                if(curr->right) q.push({curr->right, lvl+1});
            }
        }
        return level;
    }
};