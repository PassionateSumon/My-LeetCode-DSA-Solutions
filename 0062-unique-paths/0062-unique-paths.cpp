class Solution {
private:
int rec(int row, int col, int rDes, int cDes, vector<vector<int>> &dp) {
    // Pruning 
    if(row > rDes || col > cDes) return 0;
    // Base case
    if(row == rDes && col == cDes) return 1;

    //Cache check
    if(dp[row][col] != -1) return dp[row][col];

    // Compute
    int down = rec(row+1, col, rDes, cDes, dp);
    int right = rec(row, col+1, rDes, cDes, dp);

    // Return 
    return dp[row][col] = (down + right);
}
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return rec(0, 0, m-1, n-1, dp);
    }
};