class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char> sc;
        vector<int> vis(26, 0);
        unordered_map<char, int> pos;
        for(int i = 0; i < s.size(); i++) {
            pos[s[i]] = i; // Store the last occurance of the character
        }

        for(int i = 0; i < s.size(); i++) {
            if(vis[s[i]-'a']) continue;
            while(sc.size() > 0 && sc.top() > s[i] && pos[sc.top()] > i) {
                vis[sc.top() - 'a'] = 0;
                sc.pop();
            }   
            sc.push(s[i]);
            vis[s[i] - 'a'] = 1;
        }
        string ans;
        while(!sc.empty()) {
            ans.push_back(sc.top());
            sc.pop();
        } 
        reverse(ans.begin(), ans.end());
        return ans;
    }
};