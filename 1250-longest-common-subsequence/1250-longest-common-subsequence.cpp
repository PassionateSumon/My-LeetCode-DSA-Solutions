class Solution {
private:
int rec(int ind1, int ind2, string &s1, string &s2, vector<vector<int>> &dp) {
    // Base case -->
    if(ind1 < 0 || ind2 < 0) return 0;

    // Cache check -->
    if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

    // Compute -->
    int ans = 0;
    if(s1[ind1] == s2[ind2]) ans = 1 + rec(ind1-1, ind2-1, s1, s2, dp);

    // Return -->
    return dp[ind1][ind2] = max(ans, max(rec(ind1-1, ind2, s1, s2, dp), rec(ind1, ind2-1, s1, s2, dp)));
}
public:
    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.size(), l2 = text2.size();
        vector<vector<int>> dp(l1, vector<int>(l2, -1));
        return rec(l1-1, l2-1, text1, text2, dp);
    }
};