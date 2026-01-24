class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
         int l=0;
         int r=nums.size()-1;
         long long ans=0;
         while(l<r){
               int val = nums[l]+nums[r];
               if(val<=upper){
                     ans+=(r-l);
                l++;
               }
             else
               r--;
         }
         l=0;
        r=nums.size()-1;
        while(l<r){
               int val = nums[l]+nums[r];
               if(val<=(lower-1)){
                     ans-=(r-l);
                l++;
               }
             else
               r--;
         }
         return ans;
    }
};