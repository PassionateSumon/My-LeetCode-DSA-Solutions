class Solution {
public:
    int firstUniqChar(string s) {
        map<char, pair<int, int>> mp;
        for(int i = 0; i < s.size(); i++) {
            mp[s[i]] = {(mp[s[i]].first)+1, i};
        }

        int ans = 1e9;
        for(int i = 0; i < s.size(); i++) {
            auto it = mp[s[i]].first;
            auto it2 = mp[s[i]].second;
            if(it == 1) {
                ans = min(ans, it2);
            }
        }

        // for(auto it: mp) {
        //     int freq = it.second.first;
        //     int ind = it.second.second;
        //     cout << endl << ind << " " << " " << freq;
        //     if(freq == 1) {
        //         if(ind < ans) ans = ind;
        //     }
        // }
        return (ans == 1e9) ? -1 : ans;
    }
};