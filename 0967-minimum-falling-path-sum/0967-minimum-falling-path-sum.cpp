class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int j = 0; j < n; j++) dp[n-1][j] = matrix[n-1][j];

        for(int i = n-2; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                int down = 1e5, left = 1e5, right = 1e5;
                if(j == n-1) {
                    down = matrix[i][j] + dp[i+1][j];
                    left = matrix[i][j] + dp[i+1][j-1]; 
                } else if(j == 0) {
                    down = matrix[i][j] + dp[i+1][j];
                    right = matrix[i][j] + dp[i+1][j+1]; 
                } else if(j > 0 && j < n-1) {
                    down = matrix[i][j] + dp[i+1][j];
                    left = matrix[i][j] + dp[i+1][j-1]; 
                    right = matrix[i][j] + dp[i+1][j+1];
                }

                dp[i][j] = min(down, min(left, right));
            }
        }
        int mini = INT_MAX;
        for(int i = 0; i < n; i++) {
            mini = min(mini, dp[0][i]);
        }

        return mini;
    }
};