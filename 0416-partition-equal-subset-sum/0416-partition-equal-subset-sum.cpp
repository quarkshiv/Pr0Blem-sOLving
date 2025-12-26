class Solution {
public:
    bool f(int ind,long long target,vector<int>&nums,vector<vector<int>>&dp){
          if(ind==nums.size()){
            if(target==0){
                return true;
            }
            return false;
          }
          if(dp[ind][target]!=-1){
            return dp[ind][target];
          }
          bool nottake= f(ind+1,target,nums,dp);
          bool take = false;
          if(nums[ind]<=target){
              take = f(ind+1,target-nums[ind],nums,dp);
          }
             return dp[ind][target] =  take || nottake;
    }
    bool canPartition(vector<int>& nums) {
          long long sum = accumulate(nums.begin(),nums.end(),0LL);
          long long k=0;
          if(sum%2)return false;
          else k = sum/2;
          int n = nums.size();
          vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
          return f(0,k,nums,dp);
    }
};