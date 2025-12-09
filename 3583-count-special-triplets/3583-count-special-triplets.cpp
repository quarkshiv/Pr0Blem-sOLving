class Solution {
public:
   const int mod=1e9+7;
    int specialTriplets(vector<int>& nums) {
        unordered_map<int,int>mppr,mppl;
        long long ans=0;
        for(auto it : nums) mppr[it]++;
        for(auto it : nums){
             mppr[it]--;
             int num = it *2;
             ans=(ans+ 1LL*mppl[num] *mppr[num]) %mod;
             mppl[it]++;
        }
        return (int)ans;
    }
};