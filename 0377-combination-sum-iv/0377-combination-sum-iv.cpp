class Solution {
public:
     int f(int ind,int target,vector<int>& nums,  vector<vector<int>>&dp){
        if(target==0){
            return 1;
        }
       if(target<0 || ind==nums.size()) return 0;
       if(dp[ind][target]!=-1){
        return dp[ind][target];
       }
       int nottake=f(ind+1,target,nums,dp);
        int take= f(0,target-nums[ind],nums,dp); //After choosing one number, you are free to choose ANY number again, including smaller-index ones.
        return dp[ind][target]= take+nottake;
     }
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
          vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
          return f(0,target,nums,dp);
    }
};