class Solution {
public:
    int f(int ind,int val,vector<int>& arr,vector<vector<int>>&dp){
        if(ind==0){
              if(val==0 && arr[0]==0)return 2;
              else if(val==0 || val==arr[0])return 1;
              else return 0;
        }
        if(dp[ind][val]!=-1)return dp[ind][val];
        int nt = f(ind-1,val,arr,dp);
        int t=0;
        if(arr[ind]<=val){
              t = f(ind-1,val-arr[ind],arr,dp);
        }
        return dp[ind][val]=t+nt;
    }
    int findTargetSumWays(vector<int>& arr, int target) {
         int n= arr.size();
        int totsum  = accumulate(arr.begin(),arr.end(),0ll);
        int val = (totsum-target)/2;
        if(totsum-target<0)return 0;
        if((totsum-target)%2)return 0;
            vector<vector<int>>dp(n,vector<int>(val+1,-1));
        return f(n-1,val,arr,dp);
    }
};