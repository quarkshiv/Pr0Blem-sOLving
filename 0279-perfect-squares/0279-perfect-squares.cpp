class Solution {
public:
     int f(int ind,int target,vector<int>&v,vector<vector<int>>&dp){
        if(ind==0){
            return target;
        }
        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }
        int nottake= f(ind-1,target,v,dp);
         int take = INT_MAX;
         if(v[ind]<=target){
               take=1+ f(ind,target-v[ind],v,dp);
         }
         return dp[ind][target]=min(take,nottake);
     }
    int numSquares(int n) {
        vector<int>v;
        for(int i=1;i*i<=n;i++){
                v.push_back(i*i);
        }
        int m= v.size();
        vector<vector<int>>dp(m,vector<int>(n+1,-1));
        return f(m-1,n,v,dp);
    }
};