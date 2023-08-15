class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        vector<int> freq(26, 0);
        for(char ch: s) {
            freq[ch-'a']++;
        } 

        char max_char;
        int max_freq = *max_element(freq.begin(), freq.end());

        if(max_freq > (n+1)/2) return "";

        for(int i = 0; i < 26; i++) {
            if(freq[i] == max_freq) max_char = i + 'a';
        }

        int ind = 0;
        string ans(n, ' ');
        while(max_freq--) {
            ans[ind] = max_char;
            ind += 2;
        }

        freq[max_char - 'a'] = 0;
        for(int i = 0; i < 26; i++) {
            while(freq[i]-- > 0) {
                ind = (ind >= n) ? 1 : ind;
                ans[ind] = i + 'a';
                ind += 2; 
            }
        }

        return ans;
    }
};