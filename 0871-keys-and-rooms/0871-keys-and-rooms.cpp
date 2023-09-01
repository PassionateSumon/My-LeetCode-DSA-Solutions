class Solution {
private:
    int bfs(vector<vector<int>> &adj, vector<bool> &vis) {
        queue<int> q;
        q.push(0);
        vis[0] = true;
        int count = 0;
        while(!q.empty()) {
            int currRoom = q.front();
            q.pop();
            count++;
            for(auto it: adj[currRoom]) {
                if(!vis[it]) {
                    q.push(it);
                    vis[it] = true;
                }
            }
        }
        return count;
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);
        int ans = bfs(rooms, vis);
        cout << ans;
        return (ans == n);
    }
};