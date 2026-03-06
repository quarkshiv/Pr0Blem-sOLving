class Solution {
public:
    const int mod =1e9+7;
    int numRollsToTarget(int n, int m, int target) {
           vector<vector<long long>>dp(n+1,vector<long long>(target+1,0));
            dp[0][0]=1;
          for(int i=1;i<=n;i++){
              for(int j=1;j<=target;j++){
                     for(int k=1;k<=m;k++){
                              if(j-k>=0){
                                    dp[i][j]= (dp[i][j] + dp[i-1][j-k])%mod;
                              }
                     }
              }
          }
          return dp[n][target];
    }
};