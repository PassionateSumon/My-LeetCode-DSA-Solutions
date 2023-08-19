class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        set<int> st;
        int c = 0;
        for(int it: arr) mp[it]++;
        for(auto it: mp) {
            int freq = it.second;
            c++;
            st.insert(freq);
        }
        return (c == st.size());
    }
};