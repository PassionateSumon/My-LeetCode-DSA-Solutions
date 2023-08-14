class Solution {
private:
int dfs(TreeNode* root) {
    if(root == NULL) return 0;
    return max(dfs(root->left), dfs(root->right))+1;
}
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int left = diameterOfBinaryTree(root->left);
        int lh = dfs(root->left);
        int right = diameterOfBinaryTree(root->right);
        int rh = dfs(root->right);
        return max((rh+lh), max(left, right));
    }
};