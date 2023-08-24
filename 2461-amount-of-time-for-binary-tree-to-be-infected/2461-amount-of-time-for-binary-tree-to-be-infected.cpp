class Solution {
private:
void store(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &par) {
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        if(curr->left) {
            par[curr->left] = curr;
            q.push(curr->left);
        }
        if(curr->right) {
            par[curr->right] = curr;
            q.push(curr->right);
        }
    }
}
TreeNode* solve(TreeNode* root, int val) {
    if(!root) return NULL;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        if(curr->val == val) return curr;
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
    return NULL;
}
public:
    int amountOfTime(TreeNode* root, int start) {
        // 1st Step ==>
        // First i've to create a Map and store the parent nodes --->
        unordered_map<TreeNode*, TreeNode*> store_parent;
        store(root, store_parent); // Stored all the parents

        // 2nd step -->
        // I have to do a BFS and find accross the target node using the help of Map 
        // to get the access of neighbour nodes -->
        TreeNode* s_node = solve(root, start);
        queue<pair<TreeNode*, int>> q;
        unordered_map<TreeNode*, bool> vis; // Must have to create this to prevent visiting same node again...............
        q.push({s_node, 0});
        vis[s_node] = true;
        int ans;
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                TreeNode* curr = q.front().first;
                int level = q.front().second;
                q.pop();
                ans = level;
                if(curr->left && !vis[curr->left]) {
                    vis[curr->left] = true;
                    q.push({curr->left,level+1});
                }
                if(curr->right && !vis[curr->right]) {
                    vis[curr->right] = true;
                    q.push({curr->right,level+1});
                }
                if(store_parent[curr] && !vis[store_parent[curr]]) {
                    vis[store_parent[curr]] = true;
                    q.push({store_parent[curr], level+1});
                }
            }
        }
        return ans;
    }
};