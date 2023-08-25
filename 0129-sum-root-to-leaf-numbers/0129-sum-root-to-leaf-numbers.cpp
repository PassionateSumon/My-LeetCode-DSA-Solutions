class Solution {
private:
void dfs(TreeNode* root, int val, int &sum) {
    if(root->left == NULL && root->right == NULL) {
        val = (val*10)+root->val;
        sum += val;
        return;
    }

    val = (val*10)+root->val;
    if(root->left) dfs(root->left, val, sum);
    if(root->right) dfs(root->right, val, sum);
}
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        dfs(root, 0, sum);
        return sum;
    }
};