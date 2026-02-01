class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans=nums[0];
         sort(nums.begin(),nums.end());
         if(nums[0]==ans){
            ans+=nums[1]+nums[2];
         }
         else if(nums[1]==ans){
            ans+=nums[0]+nums[2];
         }
         else{
            ans+=nums[0]+nums[1];
         }
         return ans;
    }
};