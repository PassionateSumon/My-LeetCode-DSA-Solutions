class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        for(int i = 0; i < flights.size(); i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];
            adj[u].push_back({v, w});
        }
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        queue<pair<int, pair<int, int>>> pq;
        pq.push({0, {0, src}});

        while(!pq.empty()) {
            int level = pq.front().first;
            auto it = pq.front().second;
            int cost = it.first;
            int node = it.second;
            pq.pop();
            if(level > k) {
                break;
            }
            for(auto it: adj[node]) {
                int adjNode = it.first;
                int adjCost = it.second;
                if(dist[adjNode] > cost + adjCost && level <= k) {
                    dist[adjNode] = cost + adjCost;
                    pq.push({level + 1, {dist[adjNode], adjNode}});
                }
            }
        }

        return (dist[dst] == 1e9) ? -1 : dist[dst];
    }
};