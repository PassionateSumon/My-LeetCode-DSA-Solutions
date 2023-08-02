class Solution {
private:
int rec(int ind, int tar, vector<int> &nums, vector<vector<int>> &dp) {
    // Base case -->
    if(ind == 0) {
        if((tar%nums[0]) == 0) return 1;
        else return 0;
    }

    // Cache check -->
    if(dp[ind][tar] != -1) return dp[ind][tar];

    // Compute -->
    int notTake = rec(ind - 1, tar, nums, dp);
    int take = 0;
    if(nums[ind] <= tar) {
        take = rec(ind, tar - nums[ind], nums, dp);
    }

    // Return -->
    return dp[ind][tar] = (take + notTake);
}
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        int ans = rec(n-1, amount, coins, dp);
        return ans;
    }
};