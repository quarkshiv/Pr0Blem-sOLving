class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(),nums.end());
        int l =0;
        long long cnt=0;
        long long ans=0;
    for(int r=0;r<nums.size();r++){
           if(nums[r]==maxi)cnt++;
           while(cnt>=k){
                if(nums[l]==maxi)cnt--;
                l++;
           }
           ans+=(r-l+1);
    }
    int n = nums.size();
    long long total = n*1ll*(n+1)/2;
    return total-ans;
    }
};