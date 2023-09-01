class Solution {
// private:
//     int solve(int n) {
//         int c = 0;
//         while(n > 0) {
//             c++;
//             n = n & (n-1);
//         }
//         return c;
//     }
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        if(n == 0) return ans;
        ans[0] = 0;
        ans[1] = 1;
        for(int i = 2; i <= n; i++) {
            ans[i] = ans[i >> 1] + (i % 2);
        }
        return ans;
    }
};