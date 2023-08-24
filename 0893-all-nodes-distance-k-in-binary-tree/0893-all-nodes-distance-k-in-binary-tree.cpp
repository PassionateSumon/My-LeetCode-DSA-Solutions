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
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // 1st Step ==>
        // First i've to create a Map and store the parent nodes --->
        unordered_map<TreeNode*, TreeNode*> store_parent;
        store(root, store_parent); // Stored all the parents

        // 2nd step -->
        // I have to do a BFS and find accross the target node using the help of Map 
        // to get the access of neighbour nodes -->
        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> vis; // Must have to create this to prevent visiting same node again...............
        q.push(target);
        vis[target] = true;
        int level = 0;
        while(!q.empty()) {
            if(level == k) break;
            level++;
            
            int size = q.size();
            for(int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left && !vis[curr->left]) {
                    vis[curr->left] = true;
                    q.push(curr->left);
                }
                if(curr->right && !vis[curr->right]) {
                    vis[curr->right] = true;
                    q.push(curr->right);
                }
                if(store_parent[curr] && !vis[store_parent[curr]]) {
                    vis[store_parent[curr]] = true;
                    q.push(store_parent[curr]);
                }
            }
        }

        // Now the 3rd Step ==>
        // Whichever elements remains in the queue, are my answer -->
        vector<int> ans;
        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            ans.push_back(curr->val);
        }

        return ans;
    }
};