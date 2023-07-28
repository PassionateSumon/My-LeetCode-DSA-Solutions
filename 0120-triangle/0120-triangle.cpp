class Solution {
private:
int rec(int row, int col, vector<vector<int>> &tri, vector<vector<int>>& dp) {
    // Base case 
    if(row == tri.size() - 1) return tri[row][col];

    // Cache check
    if(dp[row][col] != -1) return dp[row][col];

    // Compute
    int curr = 0, currPlusOne = 0;
    if(row < tri.size()) {
        curr = tri[row][col] + rec(row+1, col, tri, dp);
        currPlusOne = tri[row][col] + rec(row+1, col+1, tri, dp);
    }

    return dp[row][col] = min(curr, currPlusOne);
}
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n+1, 0));
        for(int j = 0; j < n; j++) {
            dp[n-1][j] = triangle[n-1][j];
        }

        for(int i = n-2; i >= 0; i--) {
            for(int j = i; j >= 0; j--) {
                int curr = triangle[i][j] + dp[i+1][j];
                int currPlusOne = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(curr, currPlusOne);
            }
        }
        return dp[0][0];
    }
};