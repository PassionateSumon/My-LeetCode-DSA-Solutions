class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        // 1st step => Find the shortest path using Dijkstra
        vector<pair<int, int>> adj[n];
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int cnt = edges[i][2];
            adj[u].push_back({v,cnt});
            adj[v].push_back({u,cnt});
        }

        vector<int> dist(n, 1e9);
        dist[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0}); // node <-=-> distance
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int node = it.first;
            int remDist = it.second;
            for(auto i: adj[node]) {
                int newNode = i.first;
                int newDist = i.second;
                if(dist[newNode] > (remDist+newDist+1)) {
                    dist[newNode] = (remDist+newDist+1);
                    pq.push({newNode, dist[newNode]});
                }
            } 
        }

        int ans = 0;
        for(int it: dist) {
            if(it <= maxMoves) ans++;
            cout << it << " ";
        }

        for(int i = 0; i < edges.size(); i++) {
            int src = edges[i][0], dest = edges[i][1], dis = edges[i][2];
            int fromSrc = max(0, maxMoves-dist[src]);
            int fromDest = max(0, maxMoves-dist[dest]);
            ans += min(dis, fromSrc+fromDest); 
        }

        return ans;
    }
};