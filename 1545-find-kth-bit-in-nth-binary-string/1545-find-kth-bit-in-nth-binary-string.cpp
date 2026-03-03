class Solution {
public:
    string invert(string s){
          for(auto &it : s){
              if(it=='0'){
                  it='1';
              }
              else it='0';
          }
        return s;
    }
    char findKthBit(int n, int k) {
        vector<string>dp(n);
        dp[0]="0";
        for(int i=1;i<n;i++){
            string inv = invert(dp[i-1]);
           reverse(inv.begin(),inv.end());
            dp[i]=dp[i-1] + "1" + inv;
        }
        return dp[n-1][k-1];
    }
};