class Solution {
public:
   int totpairs(int diff,vector<int>& nums){
       int left = 0; 
       int ans=0;
       for(int right=0;right<nums.size();right++){
               while(nums[right]-nums[left]>diff){
                    left++;  
               }
               ans+=(right-left);
       }
       return ans;
   }
    int smallestDistancePair(vector<int>& nums, int k) {
    sort(nums.begin(),nums.end());
    int low=0;
    int n= nums.size();
    int high=nums[n-1]-nums[0];
    while(low<=high){
        int mid = (low + high)/2;
        if(totpairs(mid,nums)>=k){
             high= mid-1;
        }
        else if(totpairs(mid,nums)<k)
            low = mid+1;

    }
    return low;
    }
};