class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev = 0, curr = 1, n = s.size(), ans = 0;
        for(int i = 0; i < n-1; ++i) {
            if(s[i] == s[i+1]) {
                curr++;
            } else {
                ans += min(curr, prev);
                prev = curr;
                curr = 1;
            }
        }
        ans += min(prev, curr); // For exmpl of 0011 -> NO break point here
        return ans;
    }
};