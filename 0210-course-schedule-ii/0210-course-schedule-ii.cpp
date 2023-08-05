class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
        }

        vector<int> indegree(n, 0);
        for(auto it: adj) {
            for(int i: it) {
                indegree[i]++;
            }
        }

        queue<int> q;
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        if(ans.size() == n) return ans;
        return {};
    }
};