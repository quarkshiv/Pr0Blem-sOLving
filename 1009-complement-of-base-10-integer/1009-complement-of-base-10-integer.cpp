class Solution {
public:
    string to_binary(int n){
           string s="";
           while(n>0){
              s+=(char)((n%2)+'0');
              n=n/2;
           }
            reverse(s.begin(), s.end());
           return s;
    }
    void flip(string &s){
         for(int i=0;i<s.size();i++){
              if(s[i]=='0')s[i]='1';
              else s[i]='0';
         }
    }
    int bitwiseComplement(int n) {
        if(n==0)return 1;
        string s = to_binary(n);
          flip(s);
          int ans=0;
           for(int i=0;i<s.size();i++){
               ans= ans*2 + s[i]-'0';
           }
           return ans;
    }
};