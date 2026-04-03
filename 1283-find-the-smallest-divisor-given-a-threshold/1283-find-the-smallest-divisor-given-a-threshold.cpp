class Solution {
public:
      int val(vector<int>& nums,int mid){
        int ans=0;
           for(int i=0;i<nums.size();i++){
                   if(nums[i]%mid==0){
                        ans+=nums[i]/mid;
                   }
                   else ans+=nums[i]/mid+1;
           }
           return ans;
      }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = 1e9;
        int ans=high;
        while(low<=high){
              int mid = low + (high - low)/2;
              if(val(nums,mid)<=threshold){
                    ans= mid;
                    high = mid-1;
              }
              else low = mid+1;
        }
        return ans;
    }
};