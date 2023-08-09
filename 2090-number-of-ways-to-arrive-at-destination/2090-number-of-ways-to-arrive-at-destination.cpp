#define ll long long
const int mod = 1e9+7;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> adj[n];
        for(int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            ll t = roads[i][2];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        pq.push({0, 0});
        vector<ll> dist(n, 1e18);
        dist[0] = 0;
        vector<ll> ways(n, 0);
        ways[0] = 1;
        while(!pq.empty()) {
            ll dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it: adj[node]) {
                int newNode = it.first;
                ll newDis = it.second;
                if(dist[newNode] > newDis + dis) {
                    dist[newNode] = newDis + dis;
                    pq.push({dist[newNode], newNode});
                    ways[newNode] = ways[node]; // This is the first time arrived
                } else if(dist[newNode] == newDis + dis) { // This means this is the second time
                    ways[newNode] = (ways[newNode] + ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};