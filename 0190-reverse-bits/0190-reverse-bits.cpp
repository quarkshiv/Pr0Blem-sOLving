class Solution {
public:
    int reverseBits(int n) {
        string ans="";
       for(int i=31;i>=0;i--){
        ans += char('0' + ((n >> i)&1));
       }
       reverse(ans.begin(),ans.end());
       unsigned int res=0;
       for(char  c : ans){
           res =res * 2 + (c-'0');
       }
       return res;
    }
};