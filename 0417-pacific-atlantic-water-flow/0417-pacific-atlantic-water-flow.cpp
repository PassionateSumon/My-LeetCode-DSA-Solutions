class Solution {
private:
void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &hei) {
    int n = hei.size(), m = hei[0].size();
    vis[row][col] = 1;
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    for(int i = 0; i < 4; i++) {
        int nrow = row + drow[i];
        int ncol = col + dcol[i];
        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && hei[row][col] <= hei[nrow][ncol]) {
            dfs(nrow, ncol, vis, hei);
        }
    }
}
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        if(n < 1) return {{0, 0}};
        // We've to return the common cells of both pacific and atlantic ocean -->
        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));
        // Top & left --> Pacific && botoom & right --> Atlantic
        for(int i = 0; i < n; i++) {
            if(!pacific[i][0]) dfs(i, 0, pacific, heights);
            if(!atlantic[i][0]) dfs(i, m-1, atlantic, heights);
        } 
        for(int j = 0; j < m; j++) {
            if(!pacific[0][j]) dfs(0, j, pacific, heights);
            if(!atlantic[n-1][j]) dfs(n-1, j, atlantic, heights);
        } 

        vector<vector<int>> ans;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(pacific[i][j] == 1 && atlantic[i][j] == 1) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};