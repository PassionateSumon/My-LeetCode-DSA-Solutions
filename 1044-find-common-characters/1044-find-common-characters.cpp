class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> original_freq(26, 0);
        for(char ch: words[0]) {
            original_freq[ch - 'a']++;
        }
        for(int i = 1; i < words.size(); ++i) {
            vector<int> temp(26, 0);
            for(char ch: words[i]) {
                temp[ch - 'a']++;
            }
            for(int j = 0; j < 26; ++j) {
                original_freq[j] = min(original_freq[j], temp[j]);
            }
        }

        vector<string> ans;
        for(int i = 0; i < 26; i++) {
            if(original_freq[i] > 0) {
                char ch = i + 'a';
                string st = "";
                st += ch;
                while(original_freq[i]-- > 0) {
                    ans.push_back(st);
                }
            }
        }
        return ans;
    } 
};