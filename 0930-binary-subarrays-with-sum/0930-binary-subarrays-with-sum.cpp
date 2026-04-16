class Solution {
public:
        int atmost(vector<int>& nums, int goal){
               int l=0;
               long long sum=0;
               int ans=0;
               for(int r=0;r<nums.size();r++){
                      sum+=nums[r];
                      while(sum>goal && l<=r){
                            sum-=nums[l];
                            l++;
                      }
                      ans+=(r-l+1);
               }
               return ans;
        }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums,goal)-atmost(nums,goal-1);
    }
};