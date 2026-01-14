class Solution {
public:
    long long f(vector<int>& nums,long long penalty){
           long long op=0;
           for(auto it : nums){
               op+=ceil((double)it/penalty)-1;
           }
           return op;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        long long low=1;
        long long high=1e18;
        long long ans=high;
        while(low<=high){
            long long mid= low+ (high-low)/2;
            if(f(nums,mid)<=maxOperations){
                  ans=mid;
                  high=mid-1;                  
            }
            else low=mid+1;
        }
        return ans;
    }
};