class Solution {
public:
    vector<vector<int>>cost,val;
    int m,n;
    vector<vector<vector<int>>>dp;
    int f(int i,int j,int rem){
        if(rem<0){
            return -1e9;
        }
        if(i==m-1 && j==n-1){
            if(cost[i][j]<=rem){
                return val[i][j];
            }
            return -1e9;
        }
        if(dp[i][j][rem]!=-1){
            return dp[i][j][rem];
        }
        int ans =INT_MIN;
        int remi = rem-cost[i][j];
        if(i+1<m){
            ans = max(ans,val[i][j] + f(i+1,j,remi));
        }
        if(j+1<n){
            ans = max(ans,val[i][j] + f(i,j+1,remi));
        }
        return dp[i][j][rem] = ans;
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
         n= grid[0].size();
        val.assign(m,vector<int>(n));
         cost.assign(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    val[i][j]=0;
                    cost[i][j]=0;
                }
                 if(grid[i][j]==1){
                    val[i][j]=1;
                    cost[i][j]=1;
                }
                 if(grid[i][j]==2){
                    val[i][j]=2;
                    cost[i][j]=1;
                }
            }
        }
        dp.assign(m,vector<vector<int>>(n,vector<int>(k+1,-1)));
        int ans = f(0,0,k);
        if(ans<0){
            return -1;
        }
        return ans;
    }
};