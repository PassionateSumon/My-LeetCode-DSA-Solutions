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

        // << ------------- Space Optimization ----------->>
        // TC: O(n*n) ----- SC: O(n)
        vector<int> dp(n, 0);
        for(int j = 0; j < n; j++) {
            dp[j] = triangle[n-1][j];
        }

        for(int i = n-2; i >= 0; i--) {
            vector<int> temp(i+1, 0);
            for(int j = i; j >= 0; j--) {
                int curr = triangle[i][j] + dp[j];
                int currPlusOne = triangle[i][j] + dp[j+1];
                temp[j] = min(curr, currPlusOne);
            }
            dp = temp;
        }
        return dp[0];
    }
};