class Solution {
private:
int rec(int ind, int last, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    int n = grid.size();
    // Base case 
    if(ind == n) return 0;
    // Cache check
    if(dp[ind][last+1] != -1) return dp[ind][last+1];

    // Compute
    int ans = INT_MAX;
    for(int j = 0; j < n; j++) {
        if(j != last) {
            int curr = grid[ind][j] + rec(ind+1, j, grid, dp);
            ans = min(ans, curr);
        }
    }

    //Save and return
    return dp[ind][last+1] = ans;
}
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));

        int ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            ans = min(ans, rec(0, -1, grid, dp));
        }

        return ans;
    }
};