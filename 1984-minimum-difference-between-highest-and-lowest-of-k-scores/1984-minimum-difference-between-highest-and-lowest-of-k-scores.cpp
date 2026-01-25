class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
       sort(nums.begin(),nums.end());
       if(k==1)return 0;
       int mini=nums[k-1]-nums[0];
          for(int i=1;i<nums.size()-k;i++){
                mini = min(mini,nums[i+k-1]-nums[i]);
          }
          mini=min(mini,nums[nums.size()-1] -nums[nums.size()-k]);
          return mini;
    }
};