class Solution {
public:
      int f(int ind,int buy, vector<vector<int>>&dp,vector<int>& prices){
           if(ind==prices.size()){
            return 0;
           }
           if(dp[ind][buy]!=-1)return dp[ind][buy];
           int take=0;
           int nottake=0;
           if(buy){
                  take = -prices[ind]+f(ind+1,0,dp,prices);
                  nottake= f(ind+1,1,dp,prices);
           }
           else{
                take = prices[ind]+ f(ind+1,1,dp,prices);
                nottake = f(ind+1,0,dp,prices);
           }
           return dp[ind][buy] = max(take,nottake);
      }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(0,1,dp,prices);

    }
};