class Solution {
public:
const int mod=1e9+7;
   string to_binary(int n){
          string ans="";
          while(n>0){
              ans+=char((n%2)+'0');
              n=n/2;
          }
        reverse(ans.begin(), ans.end()); 
          return ans;
   }
    int concatenatedBinary(int n) {
        string s="";
                for(int i=1;i<=n;i++){
                     s+=to_binary(i); 
                }  

                long long ans=0;
                  for(int i=0;i<s.size();i++){
                  ans = (ans * 2 + (s[i] - '0')) % mod;
                  }
                  return (int)ans;
    }
};