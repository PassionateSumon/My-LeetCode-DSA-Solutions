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
    // int change(int amount, vector<int>& coins) {
    //     int n = coins.size();
    //     vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
    //     int ans = rec(n-1, amount, coins, dp);
    //     return ans;
    // }

    int change(int target, vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        for(int i =0; i <= target; i++) {
            if((i%nums[0]) == 0) dp[0][i] = 1;
            else dp[0][i] = 0;
        }

        for(int ind = 1; ind < n; ind++) {
            for(int tar = 0; tar <= target; tar++) {
                int notTake = dp[ind-1][tar];
                int take = 0;
                if(nums[ind] <= tar) {
                    take = dp[ind][tar-nums[ind]];
                }

                dp[ind][tar] = (take+notTake);
            }
        }
        return dp[n-1][target];
    }
};