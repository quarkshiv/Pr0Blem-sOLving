class Solution {
public:
vector<long long>pref;
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        int ans=0;
        pref.resize(n);
        pref[0]=nums[0];
        for(int i=1;i<nums.size();i++){
             pref[i]=pref[i-1]+nums[i];
        }
        long long sum = accumulate(nums.begin(),nums.end(),0ll);
               for(int i=0;i<n-1;i++){
                     if(pref[i]>=(sum-pref[i]))ans++;
               }
        return ans;
    }
};