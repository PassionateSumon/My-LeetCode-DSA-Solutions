class Solution {
private:
int rec(int ind, int tar, vector<int> &nums, vector<vector<int>> &dp) {
    // Base case -->
    if(ind == 0) {
        if((tar % nums[ind]) == 0) return (tar/nums[ind]);
        else return 1e8;
    }

    // Cache check -->
    if(dp[ind][tar] != -1) return dp[ind][tar];

    // compute
    int notTake = rec(ind - 1, tar, nums, dp);
    int take = INT_MAX;
    if(nums[ind] <= tar) {
        take = 1 + rec(ind, tar - nums[ind], nums, dp);
    }

    // Save and return -->
    return dp[ind][tar] = min(take, notTake);
}
public:
    int coinChange(vector<int>& nums, int x) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(x+1, -1));
        int ans = rec(n-1, x, nums, dp);
        return (ans >= 1e8) ? -1 : ans;
    }
};