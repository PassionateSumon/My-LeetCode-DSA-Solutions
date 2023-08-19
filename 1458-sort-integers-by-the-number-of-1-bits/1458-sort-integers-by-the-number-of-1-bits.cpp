class Solution {
public:
    vector<int> sortByBits(vector<int>& nums) {
        vector<pair<int, int>> mp;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            mp.push_back({nums[i], __builtin_popcount(nums[i])});
        }
        if(mp.size() == 1) {
            sort(nums.begin(), nums.end());
            return nums;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto it: mp) {
            int num = it.first;
            int bits = it.second;
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