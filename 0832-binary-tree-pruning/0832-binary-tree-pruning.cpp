class Solution {
private:
    int dfs(TreeNode* root) {
        if(root == NULL) return 0;
        // Leaf Node -->
        if(root->left == NULL && root->right == NULL) {
            if(root->val == 0) return 0;
            else return 1;
        }

        int left = dfs(root->left);
        int right = dfs(root->right);
        if(left == 0) root->left = NULL;
        if(right == 0) root->right = NULL;

        return left + right + (root->val == 1 ? 1 : 0);
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        return (dfs(root) != 0) ? root : NULL;
    }
};