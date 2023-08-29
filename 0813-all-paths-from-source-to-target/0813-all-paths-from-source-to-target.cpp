class Solution {
private:
    void solve(int currNode, vector<vector<int>> graph, vector<int> &ds, vector<vector<int>> &ans) {
        ds.push_back(currNode);
        if(currNode == graph.size()-1) {
            ans.push_back(ds);
        } else {
            for(auto it: graph[currNode]) {
                solve(it, graph, ds, ans);
            }
        }
        ds.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0, graph, ds, ans);
        return ans;
    }
};