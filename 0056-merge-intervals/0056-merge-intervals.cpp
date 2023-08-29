class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        auto firstP = intervals[0];
        for(auto &it: intervals){
            if(firstP[1] >= it[0]) {
                firstP[1] = max(firstP[1], it[1]);
            }
            else {
                ans.push_back({firstP});
                firstP = it;
            }
        }
        ans.push_back({firstP});
        return ans;
    }
};