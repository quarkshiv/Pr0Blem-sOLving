class Solution {
public:
   vector<vector<int>>dp;
      int f(int ind,int buy,vector<int>& prices){
        int n = prices.size();
           if(ind==n){
               return 0;
           }
           if(dp[ind][buy]!=-1)return dp[ind][buy];
           int nottake = INT_MIN;
           int take  = INT_MIN;
           if(buy){
                take=-prices[ind]+f(ind+1,0,prices);
                nottake = f(ind+1,1,prices);
           }
           else{
               take = prices[ind] + f(ind+1,1,prices);
               nottake = f(ind+1,0,prices);
           }
           return dp[ind][buy] = max(take,nottake);
      }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.assign(n,vector<int>(2,-1));
          return f(0,1,prices);

    }
};