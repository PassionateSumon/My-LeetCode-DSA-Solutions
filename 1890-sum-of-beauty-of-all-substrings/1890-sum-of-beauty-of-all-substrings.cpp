class Solution {
private:
    int beauty(vector<int>& freq){
        int n = freq.size(), mini = 1e9, maxi = -1e9;
        for(int i = 0; i < n; i++){
            if(freq[i] == 0) continue;
            mini = min(mini, freq[i]);
            maxi = max(maxi, freq[i]);
        }
        return maxi - mini;
    }
public:
    int beautySum(string s) {
        int n = s.size(), ans = 0;
        for(int i = 0; i < n; i++){
            vector<int> freq(26, 0);
            for(int j = i; j < n; j++){
                freq[s[j] - 'a']++;
                ans += beauty(freq);
            }
        }
        return ans;
    }
};