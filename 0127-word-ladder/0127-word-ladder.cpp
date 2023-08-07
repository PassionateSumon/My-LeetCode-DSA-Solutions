class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& wordList) {
       unordered_set<string> us(wordList.begin(), wordList.end());
       queue<pair<string, int>> q;
       q.push({begin, 1}); 
       if(us.find(begin) != us.end()) us.erase(begin);

       while(!q.empty()) {
           string s = q.front().first;
           int level = q.front().second;
           q.pop();

           if(s == end) return level;
           for(int i = 0; i < s.size(); i++) {
               string ns = s;
               for(char ch = 'a'; ch <= 'z'; ch++) {
                   ns[i] = ch;
                   if(us.find(ns) != us.end()) {
                       us.erase(ns);
                       q.push({ns, level + 1});
                   }
               }
           }
       }
       return 0;
    }
};