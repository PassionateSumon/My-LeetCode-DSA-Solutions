class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0, n = nums.size(), ans = -1;
        while(i < n) {
            long long ind = (long long)nums[i]-1;
            if(ind+1 <= n && ind+1 > 0 && nums[ind] != nums[i]) {
                swap(nums[ind], nums[i]);
            } else {
                i++;
            }
        }

        for(int i = 0; i < n; i++) {
            if(nums[i] != i+1) return i+1;
        }
        return n+1;
    }
};