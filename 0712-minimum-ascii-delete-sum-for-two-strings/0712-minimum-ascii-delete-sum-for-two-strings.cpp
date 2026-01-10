class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int asc1=0,asc2=0;
        for(char c : s1){
              asc1+=int(c);
        }
         for(char c : s2){
              asc2+=int(c);
        }
      int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
       for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                 if(s1[i-1]==s2[j-1]){
                    dp[i][j]=(int)s1[i-1]+dp[i-1][j-1];
                 }
                 else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                 }
            }
       }
        return asc1+asc2-2*dp[n][m];

    }
};