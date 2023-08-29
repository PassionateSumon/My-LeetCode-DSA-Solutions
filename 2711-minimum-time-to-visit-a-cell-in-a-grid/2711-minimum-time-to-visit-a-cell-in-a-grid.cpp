class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n = grid.size(), m = grid[0].size();
        if(grid[0][1] > 1 && grid[1][0] > 1) return -1;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;  
        q.push({0, {0, 0}}); // steps-> row-col
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        while(!q.empty()) {
            int steps = q.top().first;
            int row = q.top().second.first;
            int col = q.top().second.second;
            q.pop();
            if(row == n-1 && col == m-1) return steps;
            if(vis[row][col]) continue;
            vis[row][col] = true;
            for(int i = 0; i < 4; i++) {
                int newRow = row + dr[i];
                int newCol = col + dc[i];
                if(newRow < 0 || newRow > n-1 || newCol < 0 || newCol > m-1 || vis[newRow][newCol]) continue;
                int wait = (grid[newRow][newCol] - steps)%2 == 0 ? 1 : 0;
                q.push({max(steps+1, grid[newRow][newCol]+wait), {newRow, newCol}});
            } 
        }
        return -1;
    }
};