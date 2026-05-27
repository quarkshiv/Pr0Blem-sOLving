class Solution {
public:
   bool f(int ind,vector<int>& nums,vector<vector<int>>&dp,int target){
    if(target==0)return true;
    if(ind==0)return nums[0]==target;
    if(dp[ind][target]!=-1)return dp[ind][target];
    bool nt = f(ind-1,nums,dp,target);
    bool t = false;
    if(nums[ind]<=target){
          t = f(ind-1,nums,dp,target-nums[ind]);
    }
     return dp[ind][target]=t+nt;
   }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0ll);
        if(sum%2)return false;
        int k = sum/2;
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return f(n-1,nums,dp,k);

    }
};