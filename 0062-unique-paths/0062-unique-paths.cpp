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
    // <<-------- Memoization ------->>
    // int uniquePaths(int m, int n) {
    //     vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
    //     return rec(0, 0, m-1, n-1, dp);
    // }

    // <<----------- Tabulation ---------->>
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 1));
        dp[m-1][n-1] = 1;
        for(int row = m-2; row >= 0; row--) {
            for(int col = n-2; col >= 0; col--) {
                int down = dp[row+1][col];
                int right = dp[row][col+1];
                dp[row][col] = down + right;
            }
        }
        return dp[0][0];
    }
};