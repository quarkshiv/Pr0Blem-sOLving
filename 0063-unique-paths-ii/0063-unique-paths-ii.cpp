class Solution {
public:
   int f(int i,int j,vector<vector<int>>& dp,vector<vector<int>>& grid){
     int m = grid.size();
    int n = grid[0].size();
     if(i==m-1 && j==n-1 && grid[i][j]==0)return 1;
     if(i>=m || j>=n || grid[i][j]==1)return 0;
      if(dp[i][j]!=-1)return dp[i][j];
     int down= f(i+1,j,dp,grid);
     int right = f(i,j+1,dp,grid);
     return dp[i][j]=down+right;

   }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1)return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
          vector<vector<int>>dp(m,vector<int>(n,-1));
          return f(0,0,dp,obstacleGrid);

    }
};