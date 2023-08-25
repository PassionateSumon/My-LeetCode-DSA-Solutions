class Solution {
private:
void rec(TreeNode* par, TreeNode* child, int &count) {
    if(child == NULL) return;
    rec(child, child->left, count);
    rec(child, child->right, count);
    if(child->val > 1) {
        int donate = child->val - 1;
        child->val = 1;
        par->val += donate;
        count += donate;
    }
    else if(child->val < 1) {
        int take = 1+abs(child->val);
        par->val -= take;
        child->val = 1;
        count += take;
    }
}
public:
    int distributeCoins(TreeNode* root) {
        int count = 0;
        rec(root, root, count);
        return count;
    }
};