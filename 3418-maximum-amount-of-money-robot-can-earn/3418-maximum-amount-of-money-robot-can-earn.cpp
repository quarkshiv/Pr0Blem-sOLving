class Solution {
public:
   int f(int i,int j,int k,vector<vector<int>>& coins,vector<vector<vector<int>>>& dp){
    int  n = coins.size();
    int m  =  coins[0].size();
       if(i>=n || j>=m){
        return -1e9;
       }
       if(i==n-1 && j==m-1){
           if(coins[i][j] >= 0) return coins[i][j];
            if(k < 2) return max(0, coins[i][j]);
            return coins[i][j];
       }
       if(dp[i][j][k]!=-1e9)return dp[i][j][k];
        int  down  =  f(i+1,j,k,coins,dp);
        int right = f(i,j+1,k,coins,dp);
        int ans;
         if(coins[i][j]>=0){
            
                ans = coins[i][j]+ max(down,right);
         }
         else{
               int take =  coins[i][j]+ max(down,right);
               int neut=-1e9;
               if(k<2){
                 int r = f(i, j+1, k+1, coins, dp);
                int d = f(i+1, j, k+1, coins, dp);
                neut = max(r, d);
               }
               ans = max(take,neut);
         }
         return dp[i][j][k]=ans;
   }
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(3,-1e9)));
        return f(0,0,0,coins,dp);
    }
};