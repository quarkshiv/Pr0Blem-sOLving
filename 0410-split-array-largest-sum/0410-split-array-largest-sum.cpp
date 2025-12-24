typedef long long ll;
class Solution {
public:
   int countpar(long long mid,vector<int>& nums){
       int partition=1;
       int subarraysum=0;
       for(int i=0;i<nums.size();i++){
             if(nums[i]+subarraysum<=mid){
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
        ll low=*max_element(nums.begin(),nums.end());
        ll high=accumulate(nums.begin(),nums.end(),0LL);
        while(low<=high){
            ll mid = low +(high-low)/2;
            if(countpar(mid,nums)<=k){
                  high =mid-1;
            }
            else low = mid+1;
        }
        return low;
    }
};