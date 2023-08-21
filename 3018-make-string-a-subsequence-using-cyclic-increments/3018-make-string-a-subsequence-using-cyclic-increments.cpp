class Solution {
private:
char next(char ch) { // New - old password
	if(ch == 'z') return 'a';
	return (char)((int)(ch)+1);
}
public:
    bool canMakeSubsequence(string s1, string s2) {
        int i = 0, j = 0;
        while(i < s1.size() && j < s2.size()) {
            if(s2[j] == s1[i] || s2[j] == next(s1[i])) {
                i++; j++;
            } else {
                i++;
            }
        }
        if(j == s2.size()) return true;
        return false;
    }
};