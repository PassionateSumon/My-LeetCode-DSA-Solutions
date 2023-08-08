class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        // As we move by taken uniformly weight thereby i can use the Queue as well -->
        queue<pair<int, pair<int, int>>> q;
        if(grid[0][0] == 0) q.push({1, {0, 0}});
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0] = 0;
        int drow[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dcol[] = {0, 1, 1, 1, 0, -1, -1, -1};
        int ans = INT_MAX;
        while(!q.empty()) {
            int level = q.front().first;
            auto co_ord = q.front().second;
            int row = co_ord.first;
            int col = co_ord.second;
            q.pop();

            if(row == n-1 && col == n-1) ans = min(ans, level);

            // I have to go through all the 8 directions -->
            for(int i = 0; i < 8; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 0) {
                    if(dist[nrow][ncol] > level + dist[row][col]) {
                        dist[nrow][ncol] = level + dist[row][col];
                        q.push({level+1, {nrow, ncol}});
                    }
                }
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};