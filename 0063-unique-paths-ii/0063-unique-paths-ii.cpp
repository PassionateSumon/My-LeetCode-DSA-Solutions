class Solution {
// private:
// int rec(int row, int col, vector<vector<int>> &nums, vector<vector<int>> &dp) {
//     int rDes = nums.size() - 1, cDes = nums[0].size() - 1;
//     // Pruning 
//     if(row > rDes || col > cDes) return 0;
//     // Base case
//     if(row <= rDes && col <= cDes && nums[row][col] == 1) return 0;
//     if(row == rDes && col == cDes) return 1;

//     //Cache check
//     if(dp[row][col] != -1) return dp[row][col];

//     // Compute
//     int down = rec(row+1, col, nums, dp); 
//     int right = rec(row, col+1, nums, dp);

//     // Return 
//     return dp[row][col] = (down + right);
// }
public:
    // int uniquePathsWithObstacles(vector<vector<int>>& grid) {
    //     int m = grid.size(), n = grid[0].size();
    //     vector<vector<int>> dp(m, vector<int>(n, -1));
    //     return rec(0, 0, grid, dp);
    // }

    // <<----------- Tabulation ---------->>
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<long long>> dp(m, vector<long long>(n, 1));
        for(int row = m-1; row >= 0; row--) {
            for(int col = n-1; col >= 0; col--) {
                if(grid[row][col] == 1) {
                    dp[row][col] = 0;
                } else if(row == m-1 && col == n-1) {
                    dp[row][col] = 1;
                } else {
                    long long down = 0; 
                    if(row < m-1) down = dp[row+1][col];
                    long long right = 0; 
                    if(col < n-1) right = dp[row][col+1];

                    dp[row][col] = down + right;
                }
            }
        }
        return (int)dp[0][0];
    }
};