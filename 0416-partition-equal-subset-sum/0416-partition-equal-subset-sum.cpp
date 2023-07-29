class Solution {
public:
    bool canPartition(vector<int>& nums) {
    int n = nums.size(), sum = 0, k = 0;
	for(int i = 0; i < n; i++) sum+= nums[i];
	if((sum % 2) != 0) return false;
	else {
		k = sum/2;
	}

	vector<vector<bool>> dp(n+1, vector<bool>(k+1, false));
    for(int i = 0; i < n; i++) {
        dp[i][0] = true;
    }
    if(k >= nums[0]) dp[0][nums[0]] = true;

    for(int i = 1; i < n; i++) {
        for(int tar = 1; tar <= k; tar++){
            bool notTake = dp[i-1][tar];
            bool take = false;
            if(nums[i] <= tar) {
                take = dp[i-1][tar-nums[i]];
            }
            dp[i][tar] = (take || notTake);
        }
    }
    return dp[n-1][k];
    }
};