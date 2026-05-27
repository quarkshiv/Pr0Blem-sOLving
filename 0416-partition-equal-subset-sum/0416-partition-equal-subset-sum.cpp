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
        vector<vector<bool>>dp(n,vector<bool>(k+1,false));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
       if(nums[0]<k) dp[0][nums[0]]=true;
        for(int ind=1;ind<n;ind++){
             for(int j=1;j<=k;j++){
                    bool nt = dp[ind-1][j];
    bool t = false;
    if(nums[ind]<=j){
          t = dp[ind-1][j-nums[ind]];
    }
     dp[ind][j]=t+nt;
   }
             }
             return dp[n-1][k];

    }
};