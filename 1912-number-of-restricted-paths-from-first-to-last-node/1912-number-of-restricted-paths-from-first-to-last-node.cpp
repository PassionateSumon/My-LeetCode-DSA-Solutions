const int mod = 1e9+7;
class Solution {
int n; 
vector<long long> dist, ways;
private:
int rec(int node, vector<pair<int, long long>> adj[]) {
    if(node == n) return 1;
    if(ways[node] != -1) return ways[node];
    ways[node] = 0;
    for(auto it: adj[node]) {
        int nn = it.first;
        if(dist[nn] < dist[node]) {
            ways[node] = ((ways[node]%mod) + rec(nn, adj))%mod;
        }
    }
    return (int)ways[node];
}
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        this->n = n;
        vector<pair<int, long long>> adj[n+1];
        dist.assign(n+1, 1e18);
        ways.assign(n+1, -1);
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            long long w = it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        // First we are going to apply the Dijkstra's Algo to find the shortest path among all
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, n});
        dist[n] = 0;
        while(!pq.empty()) {
            auto it = pq.top();
            long long dis = it.first;
            int node = it.second;
            pq.pop();
            for(auto i: adj[node]) {
                int nn = i.first;
                long long nd = i.second;
                if(dis + nd < dist[nn]) {
                    dist[nn] = dis+nd;
                    pq.push({dist[nn], nn});
                }
            }
        }

        // Now i have to go to all node's adjacent nodes and whichever is ending to the last
        // node with all decreasing values in the path then i have to increase my count
        // vector<int> ways(n+1, -1);
        return rec(1, adj);
    }
};