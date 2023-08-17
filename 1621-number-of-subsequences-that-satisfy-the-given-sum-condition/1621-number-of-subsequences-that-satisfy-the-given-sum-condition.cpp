class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        // As we are looking for subsequence and just wanna match the target
        // We don't actually care about the indices
        int ans = 0, mod = 1e9+7;
        int start = 0, end = nums.size()-1;
        sort(nums.begin(), nums.end());
        vector<int> preExp(end+1, -1);
        preExp[0] = 1;
        for(int i = 1; i <= end; i++) {
            preExp[i] = (preExp[i-1] * 2)%mod;
        }

        while(start <= end) {
            if((nums[start] + nums[end]) <= target) {
                ans = ((ans%mod) + preExp[end-start])%mod;
                start++; 
            } else {
                end--;
            }
        }
        return ans;
    }
};