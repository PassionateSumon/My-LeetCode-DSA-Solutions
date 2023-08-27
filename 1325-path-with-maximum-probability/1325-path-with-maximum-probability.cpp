class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int, double>> adj[n];
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double w = succProb[i];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        vector<double> dist(n, -1e9);
        dist[start] = 1.00;
        priority_queue<pair<int, double>> q;
        q.push({start,1.00});
        while(!q.empty()) {
            int node = q.top().first;
            double prob = q.top().second;
            q.pop();

            for(auto it: adj[node]) {
                int newNode = it.first;
                double newProb = it.second;
                if(dist[newNode] < (prob*newProb)) {
                    dist[newNode] = (prob*newProb);
                    q.push({newNode, dist[newNode]});
                }
            }
        }
        return dist[end] == -1e9 ? 0.00 : dist[end];
    }
};