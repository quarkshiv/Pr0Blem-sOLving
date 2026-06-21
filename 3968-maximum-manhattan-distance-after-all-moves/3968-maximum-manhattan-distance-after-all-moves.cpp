class Solution {
public:
    int maxDistance(string s) {
        int ext=0;
        int x=0;
        int y=0;
        if(s.size()==1 && s[0]=='_')return 1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='R')x++;
              else if(s[i]=='L')x--;
              else  if(s[i]=='U')y++;
              else if(s[i]=='D')y--;
               else ext++;
        }
        return abs(x)+abs(y)+ext;
    }
};