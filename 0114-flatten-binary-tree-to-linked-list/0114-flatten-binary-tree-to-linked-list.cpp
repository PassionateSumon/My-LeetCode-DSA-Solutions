class Solution {
private:
void preOrder(TreeNode* root, vector<int> &pre) {
    if(!root) return;
    pre.push_back(root->val);
    preOrder(root->left, pre);
    preOrder(root->right, pre);
}
public:
    void flatten(TreeNode* root) {
        // Do the pre-order traversal and store them in an array
        // Traverse the array and make a Tree whose left pointer is always null and 
        // right is the traversal way ---->
        if(!root) return;
        vector<int> pre;
        preOrder(root, pre);
        for(int i = 1; i < pre.size(); i++) {
            root->left = NULL;
            root->right = new TreeNode(pre[i]);
            root = root->right;
        }
    }
};