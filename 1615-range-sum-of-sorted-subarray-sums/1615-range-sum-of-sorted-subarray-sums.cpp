class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sum_store;
        int mod = 1e9+7;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int total = 0;
            for(int j = i; j < n; j++) {
                total += nums[j];
                sum_store.push_back(total);
            }
        }
        sort(begin(sum_store), end(sum_store));
        for(int i = left-1; i < right; i++) {
            ans = ((ans%mod) + (sum_store[i] % mod)) % mod;
        }
        return ans;
    }
};