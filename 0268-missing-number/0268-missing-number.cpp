class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0, ans= 0, n = nums.size();
        while(i < n) {
            int ind = nums[i];
            if(ind < n && nums[ind] != nums[i]) {
                swap(nums[ind], nums[i]);
            }else {
                i++;
            }
        } 

        for(int i = 0; i < n; i++) {
            if(nums[i] != i) return i;
        }
        return n;
    }
};