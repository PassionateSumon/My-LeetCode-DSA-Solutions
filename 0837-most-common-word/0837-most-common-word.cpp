class Solution {
public:
    string mostCommonWord(string p, vector<string>& banned) {
        transform(p.begin(), p.end(), p.begin(),::tolower);
        unordered_map<string, int> mp;
        string s = "";
        for(char it: p) {
            if(it >= 'a' && it <= 'z') s += it;
            else {
                if(s.size()) mp[s]++;
                s = "";
            }
        }
        if(s.size()) {
            mp[s]++;
        }
        for(auto it: banned) mp[it] = 0;

        int res = 0;
        s = "";
        for(auto it: mp) {
            if(res < it.second) {
                res = it.second;
                s = it.first;
            }
        }
        return s;
    }
};