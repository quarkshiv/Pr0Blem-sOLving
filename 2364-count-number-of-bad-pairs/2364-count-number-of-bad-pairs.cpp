class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
         unordered_map<long long,long long>mpp;
         int n = nums.size();
         for(int i=0;i<n;i++){
                mpp[nums[i]-i]++;
         }
              long long cnt=0;
              for(auto it: mpp){
                   cnt+=it.second*(it.second-1)/2;
              }
            long long tot = 1LL*n*(n-1)/2;
              return tot-cnt;
    }
};