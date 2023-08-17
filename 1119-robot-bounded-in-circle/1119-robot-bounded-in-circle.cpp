class Solution {
public:
    bool isRobotBounded(string ins) {
       int i = 0, n = ins.size(), x = 0, y = 0;
       char dir = 'n';
       while(i < n) {
           char ch = ins[i];
           if(ch == 'G') {
               if(dir == 'n') y++;
               else if(dir == 's') y--;
               else if(dir == 'w') x--;
               else x++;
           } else if(ch == 'L') {
               if(dir == 'n') dir = 'w';
               else if(dir == 's')  dir = 'e';
               else if(dir == 'w') dir = 's';
               else dir = 'n';
           } else {
               if(dir == 'n') dir = 'e';
               else if(dir == 's')  dir = 'w';
               else if(dir == 'w') dir = 'n';
               else dir = 's';
           }
           i++;
       }
        if(x == 0 && y == 0) return true;
        if(dir == 'n') return false; // Without north faced side, all others will be landed to the origin atlast... 
       return true;  
    }
};