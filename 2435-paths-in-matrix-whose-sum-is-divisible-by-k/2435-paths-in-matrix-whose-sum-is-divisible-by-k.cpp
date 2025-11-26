class Solution {
public:
const int mod=1e9+7;
     int f(int i,int j,int sum,int k,vector<vector<int>>& grid,vector<vector<vector<int>>>&dp){
         int n= grid.size();
        int m=grid[0].size();
        if(i>=n || j>=m){
            return 0;
        }
        if(i==n-1 &&  j==m-1){
            return ((sum + grid[i][j])%k==0);
        }
        if(dp[i][j][sum]!=-1){
            return dp[i][j][sum];
        }
        int up = f(i+1,j,(sum+grid[i][j])% k,k,grid,dp);
          int down = f(i,j+1,(sum+grid[i][j]) % k,k,grid,dp);

          return dp[i][j][sum]= (up+down)%mod;
     }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n= grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(k,-1)));
        return f(0,0,0,k,grid,dp);
    }
};