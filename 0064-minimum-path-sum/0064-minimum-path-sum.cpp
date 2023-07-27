class Solution {
private:
int rec(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    // Pruning 
    if(row < 0 || col < 0) return 100000;

    // Base case 
    if(row == 0 && col == 0) return grid[0][0];

    // Cache check 
    if(dp[row][col] != -1) return dp[row][col];

    // Compute
    int up = grid[row][col] + rec(row - 1, col, grid, dp);
    int left = grid[row][col] + rec(row, col -1, grid, dp);

    // Return --> Save and return
    return dp[row][col] = min(up, left);
}
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return rec(n-1, m-1, grid, dp);
    }
};