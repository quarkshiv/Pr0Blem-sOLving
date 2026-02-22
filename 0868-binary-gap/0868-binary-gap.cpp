class Solution {
public:
     string to_binary(int n){
           string ans="";
           while(n>0){
                 ans+= char((n%2)+'0');
                 n=n/2;
           }
           return ans;
     }
    int binaryGap(int n) {
        string s= to_binary(n);
        int cnt = count(s.begin(),s.end(),'1');
        if(cnt<=1)return 0;
        int maxlen=0;
        int start=0;
        for(int i=0;i<s.size();i++){
             if(s[i]=='1'){start=i;
             break;
             }
        }
        for(int i=start+1;i<s.size();i++){
                if(s[i]=='1'){
                      maxlen = max(maxlen,i-start);
                      start=i;
                }
        }
        return maxlen;

    }
};