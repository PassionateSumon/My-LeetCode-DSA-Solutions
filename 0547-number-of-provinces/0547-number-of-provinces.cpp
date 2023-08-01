class Solution {
private:
void dfs(int node, vector<int> &vis, vector<int> adj[]) {
    vis[node] = 1;
    for(auto it: adj[node]) {
        if(vis[it] == 0) {
            dfs(it, vis, adj);
        }
    }
}
public:
    int findCircleNum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> adj[201];
        for(int i = 0; i < n; i++) {
            for(int j =0; j< n; j++) {
                if(i!= j && grid[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(n+1, 0);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                ans++;
                dfs(i, vis, adj);
            }
        }
        return ans;
    }
};