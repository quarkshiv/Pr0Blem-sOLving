class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
          for(int i=0;i<2;i++){
               dp[n][i]=0;
          }
          for(int i=n-1;i>=0;i--){
                for(int buy=0;buy<2;buy++){
                      int take=0;
                      int nottake=0;
                      if(buy){
                           take = -prices[i] + dp[i+1][0];
                           nottake = dp[i+1][1];
                      }   
                      else{
                         take= prices[i]-fee + dp[i+1][1];
                         nottake = dp[i+1][0];
                      }
                      dp[i][buy] = max(take,nottake);
                }
          }
          return dp[0][1];
    }
};