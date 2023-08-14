class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for(int it: nums) {
            mp[it]++;
        }
        
        priority_queue<pair<int, int>> pq;
        for(auto it: mp) {
            pq.push({it.second, it.first});
        }
        
        while(k--){
            int ele = pq.top().second;
            pq.pop();
            ans.push_back(ele);
        }
        return ans;
    }
};