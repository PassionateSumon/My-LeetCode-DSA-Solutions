class Solution {
private:
void solve(int ind, int n, int k, int level, vector<int> &ds, vector<vector<int>> &ans) {
    // Base case -->
    if(level == k) {
        ans.push_back(ds);
        return;
    }

    // Compute -->
    for(int i = ind; i <= n; i++) {
        ds.push_back(i);
        solve(i+1, n, k, level+1, ds, ans);
        ds.pop_back();
    }
}
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(1, n, k, 0, ds, ans);
        return ans;
    }
};