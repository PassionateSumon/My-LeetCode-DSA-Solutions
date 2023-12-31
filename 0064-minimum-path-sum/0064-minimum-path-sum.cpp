class Solution {
// private:
// int rec(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp) {
//     // Pruning 
//     if(row < 0 || col < 0) return 100000;

//     // Base case 
//     if(row == 0 && col == 0) return grid[0][0];

//     // Cache check 
//     if(dp[row][col] != -1) return dp[row][col];

//     // Compute
//     int up = grid[row][col] + rec(row - 1, col, grid, dp);
//     int left = grid[row][col] + rec(row, col -1, grid, dp);

//     // Return --> Save and return
//     return dp[row][col] = min(up, left);
// }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        // Tabulation -->
        for(int i = 0; i < n; i++) {
            for(int j =0; j < m; j++) {
                if(i == 0 && j == 0) dp[i][j] = grid[i][j];
                else {
                    int up = 1e9, left = 1e9;
                    if(i > 0) up = grid[i][j] + dp[i-1][j];
                    if(j > 0) left = grid[i][j] + dp[i][j - 1];         
                    dp[i][j] = min(up, left);
                }
            }
        }
        return dp[n-1][m-1];
    }
};