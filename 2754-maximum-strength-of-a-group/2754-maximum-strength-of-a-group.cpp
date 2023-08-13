#define ll long long
class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        ll ans = 0;
        int negCount = 0;
        if(nums.size() == 1) return nums[0];
        sort(nums.begin(), nums.end());
        for(int it: nums) {
            if(it < 0) negCount++;
        }
        if(negCount % 2 != 0) negCount--;
        for(int it: nums) {
            if(it < 0 && negCount == 0) continue;
            if(it == 0) continue;
            if(ans == 0) {
                ans = it;
            } else {
                ans *= it;
            }
            negCount--;
        } 
        return (ans == 0) ? 0 : ans;
    }
};