class Solution {
private:
int rec(int row, int col, vector<vector<int>> &nums, vector<vector<int>> &dp) {
    int rDes = nums.size() - 1, cDes = nums[0].size() - 1;
    // Pruning 
    if(row > rDes || col > cDes) return 0;
    // Base case
    if(row <= rDes && col <= cDes && nums[row][col] == 1) return 0;
    if(row == rDes && col == cDes) return 1;

    //Cache check
    if(dp[row][col] != -1) return dp[row][col];

    // Compute
    int down = rec(row+1, col, nums, dp); 
    int right = rec(row, col+1, nums, dp);

    // Return 
    return dp[row][col] = (down + right);
}
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return rec(0, 0, grid, dp);
    }
};