class Solution {
public:
 const int MOD=1e9 +7;
    int specialTriplets(vector<int>& nums) {
        int ans=0;
        int n = nums.size();
       unordered_map<int,int>mppl,mppr;
         for(int i=0;i<nums.size();i++){
             mppr[nums[i]]++;
         }
       for(int j=0;j<nums.size();j++){
             mppr[nums[j]]--;
             int val = nums[j]*2;
             ans =(ans + 1LL * mppr[val] * mppl[val])%MOD;
             mppl[nums[j]]++;
       }
       return ans;
    }
};