class Solution {
public:
      int f(int ind,vector<int>& nums,vector<int>&dp){
               if(ind>=nums.size()){
                return 0;
               }
               if(dp[ind]!=-1){
                return dp[ind];
               }
               int nottake= f(ind+1,nums,dp);
               int take = nums[ind] + f(ind+2,nums,dp);
               return dp[ind]=max(take,nottake);
      }
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        vector<int>temp1;
        vector<int>temp2;
        int ans=0;
        for(int i=0;i<nums.size();i++){
             if(i!=0)temp1.push_back(nums[i]);
             if(i!=nums.size()-1)temp2.push_back(nums[i]);
        }
        vector<int>dp1(nums.size()-1,-1);
        vector<int>dp2(nums.size()-1,-1);
        ans = max(ans,f(0,temp1,dp1));
        ans = max(ans,f(0,temp2,dp2));
        return ans;
    }
};