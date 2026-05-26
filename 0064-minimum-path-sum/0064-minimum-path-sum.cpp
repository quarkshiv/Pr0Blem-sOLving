class Solution {
public:
    int f(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&grid){
          int n = grid.size();
        int m = grid[0].size();
        if(i==n-1 && j==m-1)return grid[i][j];
        if(i>=n || j>=m)return 1e5;
        if(dp[i][j]!=-1)return dp[i][j];
          int right = grid[i][j]+ f(i,j+1,dp,grid);
          int left = grid[i][j]+ f(i+1,j,dp,grid);
          return dp[i][j]=min(right,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(0,0,dp,grid);
    }
};