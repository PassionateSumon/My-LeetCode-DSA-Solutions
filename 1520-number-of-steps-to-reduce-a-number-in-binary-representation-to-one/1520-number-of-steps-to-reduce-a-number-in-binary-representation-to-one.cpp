class Solution {
public:
    int numSteps(string s) {
        int len = s.size(), ones = 0, zeros = 0, ans = 0;
        for(int i = len-1; i>= 0; i--) {
            if(s[i] == '1') ones++;
            else if(ones > 0) zeros++;
        }
        if(ones == 1) return len-1;
        return (len + zeros + 1);
    }
};