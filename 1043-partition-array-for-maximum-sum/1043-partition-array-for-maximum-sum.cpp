class Solution {
public:
   int f(int ind,vector<int>& arr, int k,vector<int>&dp){
    int n = arr.size();
      if(ind==n)return 0;
      
      if(dp[ind]!=-1)return dp[ind];
      int ans = 0;
      int maxi= 0;
      for(int j=ind;j<min(n,ind+k);j++){
           maxi = max(maxi,arr[j]);
           int len = j-ind+1;
           ans = max(ans,maxi*len + f(j+1,arr,k,dp));

      }
      return dp[ind]=ans;
   }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size(),-1);
        return f(0,arr,k,dp);
    }
};