class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        int n = pattern.size();
        unordered_set<char> s(pattern.begin(), pattern.begin()+n);
        for(auto it: words) {
            string str = it;
            set<char> st(str.begin(), str.begin()+n);
            if(st.size() != s.size()) continue;
            unordered_map<char, char> mp;
            bool flag = true;
            for(int i = 0; i < n; i++) {
                if(mp.count(pattern[i]) == 0) {
                    mp[pattern[i]] = str[i];
                } else {
                    if(mp[pattern[i]] != str[i]) {
                        flag = false;
                        break;
                    }
                }
            }
            if(flag) ans.push_back(str);
        }
        return ans;
    }
};