class Solution {
public:
    vector<int> sortByBits(vector<int>& nums) {
        int n = nums.size();
        // vector<pair<int, int>> mp;
        // for(int i = 0; i < n; ++i) {
        //     mp.push_back({nums[i], __builtin_popcount(nums[i])});
        // }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0; i < n; ++i) {
            int num = nums[i];
            int bits = __builtin_popcount(num);
            pq.push({bits, num});
        } 
        vector<int> ans;
        while(!pq.empty()) {
            int num = pq.top().second;
            pq.pop();
            ans.push_back(num);
        }
        return ans;
    }
};