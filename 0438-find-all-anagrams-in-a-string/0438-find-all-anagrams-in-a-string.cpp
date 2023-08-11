class Solution {
private:
bool isValid(vector<int> mp, vector<int> ms) {
    return mp == ms;
}
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), k = p.size();
        // Base case -->
        if(k > n) return {};
        vector<int> ms(26, 0);
        vector<int> mp(26, 0);
        vector<int> ans;
        for(int i = 0; i < k ; i++) {
            mp[p[i] - 'a']++;
            ms[s[i] - 'a']++;
        }
        if(mp == ms) ans.push_back(0);
        int i = 1;
        while(i <= n-k) {
            ms[s[i-1] - 'a']--;
            ms[s[i+k-1] - 'a']++;
            if(isValid(ms, mp)) ans.push_back(i);
            i++;
        }
        return ans;
    }
};