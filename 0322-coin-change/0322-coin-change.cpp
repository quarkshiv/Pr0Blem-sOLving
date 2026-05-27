class Solution {
public:
  int f(int ind,vector<int>& coins,int amount, vector<vector<int>>&dp){
          if(ind==0){
            if(amount%coins[0]==0)
              return amount/coins[0];
                 return 1e6;
          }
        if(dp[ind][amount]!=-1)return dp[ind][amount];
        int nottake = f(ind-1,coins,amount,dp);
        int take = INT_MAX;
        if(coins[ind]<=amount)
        take = 1+ f(ind,coins,amount-coins[ind],dp);
        return dp[ind][amount]= min(take,nottake);
  }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0)
              dp[0][i]=i/coins[0];
              else dp[0][i]=1e5;
        }
        for(int ind=1;ind<n;ind++){
             for(int j=1;j<=amount;j++){
         int nottake = dp[ind-1][j];
        int take = 1e5;
        if(coins[ind]<=j)
        take = 1+ dp[ind][j-coins[ind]];
         dp[ind][j]= min(take,nottake);
             }
        }
             if(dp[n-1][amount]==1e5)return -1;
             return dp[n-1][amount];
    }
};