class Solution {
public:
    bool checkOnesSegment(string s) {
        int tot = count(s.begin(),s.end(),'1');
         int len = 0;
         int start=0;
          for(int i=0;i<s.size();i++){
               if(s[i]=='1'){
                    start =i;
                    break;
               }
          }
          int i=start;
        while(s[i]=='1'){
               i++;
        }
        return tot==i-start;
    }
};