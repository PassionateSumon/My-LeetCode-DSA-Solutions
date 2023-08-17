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
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        int ans = 0;
        while(!q.empty()) {
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();
            ans = level;
            if(node-> left) q.push({node->left, level+1});
            if(node-> right) q.push({node->right, level+1});
        }
        return ans;
    }
};