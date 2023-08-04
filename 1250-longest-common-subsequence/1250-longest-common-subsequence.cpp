class Solution {
private:
int rec(int ind1, int ind2, string &s1, string &s2, vector<vector<int>> &dp) {
    // Base case -->
    if(ind1 == 0 || ind2 == 0) return 0;

    // Cache check -->
    if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

    // Compute -->
    if(s1[ind1-1] == s2[ind2-1]) return 1 + rec(ind1-1, ind2-1, s1, s2, dp);

    // Return -->
    return dp[ind1][ind2] = max(rec(ind1-1, ind2, s1, s2, dp), rec(ind1, ind2-1, s1, s2, dp));
}
public:
    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.size(), l2 = text2.size();
        vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0));
        for(int i = 0; i <= l2; i++) dp[0][i] = 0;
        for(int i = 0; i <= l1; i++) dp[i][0] = 0;

        for(int ind1 = 1; ind1 <= l1; ind1++) {
            for(int ind2 = 1; ind2 <= l2; ind2++) {
                if(text1[ind1-1] == text2[ind2-1]) {
                    dp[ind1][ind2] = 1 + dp[ind1- 1][ind2-1];
                } else {
                    dp[ind1][ind2] = max(dp[ind1-1][ind2], dp[ind1][ind2-1]);
                }
            }
        }
        return dp[l1][l2];
    }
};