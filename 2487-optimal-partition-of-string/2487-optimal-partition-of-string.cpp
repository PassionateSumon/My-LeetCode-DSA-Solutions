class Solution {
public:
    int partitionString(string s) {
        int i = 0, ans = 0;
        unordered_set<char> st;
        for(char ch: s) {
            if(st.count(ch) != 0) {
                ans++;
                st.clear();
            }
            st.insert(ch);
        }
        return ans+1;
    }
};