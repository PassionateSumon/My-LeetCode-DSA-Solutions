class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& hei) {
        int n = hei.size(), m = hei[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0,{0,0}});

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!pq.empty()) {
            int diff = pq.top().first;
            auto it = pq.top().second;
            int row = it.first;
            int col = it.second;
            pq.pop();

            if(row == n- 1 && col == m-1) return diff;

            for(int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    int newDiff = max(abs(hei[row][col] - hei[nrow][ncol]), diff);
                    if(newDiff < dist[nrow][ncol]) {
                        dist[nrow][ncol] = newDiff;
                        pq.push({newDiff, {nrow, ncol}});
                    }
                }
            }
        }
        return 0;
    }
};