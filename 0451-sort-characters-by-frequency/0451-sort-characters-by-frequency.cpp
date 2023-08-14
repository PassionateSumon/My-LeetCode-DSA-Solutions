class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(char ch: s) {
            mp[ch]++;
        }
        string ans;
        priority_queue<pair<int, char>> pq;
        for(auto it: mp) {
            int freq = it.second;
            char ch = it.first;
            pq.push({freq, ch});
        }
        while(!pq.empty()) {
            int freq = pq.top().first;
            char ch = pq.top().second;
            pq.pop();
            while(freq--) ans.push_back(ch);
        }
        return ans;
    }
};