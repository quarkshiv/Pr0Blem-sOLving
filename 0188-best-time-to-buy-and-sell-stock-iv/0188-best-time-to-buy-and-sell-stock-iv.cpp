class Solution {
public:
 vector<vector<vector<int>>>dp;
   int f(int ind,int buy,int k,vector<int>& prices){
    int n = prices.size();
    if(k<=0)return 0;
       if(ind==n)return 0;
         if(dp[ind][buy][k]!=-1)return dp[ind][buy][k];
         int nottake = INT_MIN;
         int take=  INT_MIN;
         if(buy){
              take  =  -prices[ind] + f(ind+1,0,k,prices);
              nottake = f(ind+1,1,k,prices);
         }
         else{
               take  =  prices[ind] + f(ind+1,1,k-1,prices);
              nottake = f(ind+1,0,k,prices);
         }
         return dp[ind][buy][k]=max(take,nottake);
   }
    int maxProfit(int k,vector<int>& prices) {
        int n = prices.size();
           dp.assign(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
           return f(0,1,k,prices);
    }
};