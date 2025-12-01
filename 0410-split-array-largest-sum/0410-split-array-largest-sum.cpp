class Solution {
public:
   int countpar(vector<int>&nums,int mid){
        int partition=1;
        int subarraysum=0;
        for(int i=0;i<nums.size();i++){
              if(subarraysum + nums[i]<= mid){
                   subarraysum+=nums[i];
              }
              else{
                partition++;
                subarraysum=nums[i];
              }
        }
        return partition;
   }
    int splitArray(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(),nums.end());
        int sum  = accumulate(nums.begin(),nums.end(),0);
        int low = maxi;
        int high = sum;
        while(low<=high){
            int mid =  (low+high)/2;
              if(countpar(nums,mid)<=k){
                  high = mid-1;
              }
              else low = mid+1;
        }
        return low;
    }
};