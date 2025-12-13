class Solution {
public:
   int f(int ind,int prev,vector<vector<int>>& dp,vector<int>& nums){
     if(ind==nums.size()){
        return 0;
     }
     if(dp[ind][prev+1]!=-1){
        return dp[ind][prev+1];
     }
     int nottake= f(ind+1,prev,dp,nums);
     int take=0;
     if(prev==-1 || nums[ind]>nums[prev]){
        take = 1+ f(ind+1,ind,dp,nums);
     }
     return dp[ind][prev+1] = max(take,nottake);
   }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(0,-1,dp,nums);
    }
};