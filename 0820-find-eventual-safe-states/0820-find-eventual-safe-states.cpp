class Solution {
private:
bool dfs(int node, vector<int> &vis, vector<int> &pv, vector<vector<int>>& edges, vector<int> &check) {
    vis[node] = 1;
    pv[node] = 1;
    for(auto it: edges[node]) {
        if(!vis[it]) {
            if(dfs(it, vis, pv, edges, check) == true) {
                check[it] = 0;
                return true;
            }
        } else if(pv[it]) {
            check[it] = 0;
            return true;
        }
    }

    pv[node] = 0;
    check[node] = 1;
    return false;
}
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& edges) {
        // Observations -->
        // 1 - > If there have a cycle then for sure it'll not be a part of safe state
        // So if i code the cycle detection and those which are not forming cycle 
        // That will be the safe states .....
        int n = edges.size();
        // vector<int> adj[n];
        // for(int i = 0; i < n; i++) {
        //     int u = edges[i][0];
        //     int v = edges[i][1];
        //     adj[u].push_back(v);
        // }

        vector<int> vis(n, 0), pathV(n, 0), check(n, 0);
        // int vis[n] = {0};
        // int pathV[n] = {0};
        // int check[n] = {0}; //track of the elements of not having or connected in a cycle
        for(int i = 0; i < vis.size(); i++) {
            if(!vis[i]) {
                dfs(i, vis, pathV, edges, check);
            }
        }

        vector<int> ans;
        for(int i = 0; i < check.size(); i++) {
            if(check[i] == 1) ans.push_back(i);
        }
        return ans;
    }
};