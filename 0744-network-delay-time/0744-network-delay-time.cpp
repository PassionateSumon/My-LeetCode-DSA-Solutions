class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int des, int src) {
        vector<pair<int, int>> adj[des+1];
        for(int i = 0; i < times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            adj[u].push_back({v, w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        vector<int> dist(des+1, 1e9);
        dist[src] = 0;
        while(!pq.empty()) {
            int cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it: adj[node]) {
                int adjNode = it.first;
                int ncost = it.second;
                if(dist[adjNode] > cost + ncost) {
                    dist[adjNode] = cost + ncost;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        } 
        int ans = INT_MIN;
        for(int i = 1; i <= des; i++) {
            if(dist[i] == 1e9) return -1;
            ans = max(ans, dist[i]);
        }       
        return ans;
    }
};