class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long total = 0;
        for (int x : nums) total += x;
        long target = total%p;
        if(target==0){
            return 0;
        }
        unordered_map<int,int>mpp;
        mpp[0]=-1;
        long pref=0;
        int ans = nums.size();
        for(int i=0;i<nums.size();i++){
            pref=(pref + nums[i])%p;
            int need = (pref -target + p) %p;
            if(mpp.count(need)){
                ans = min(ans,i-mpp[need]);
            }
            mpp[(int)pref] =i;
        }
       return ans == nums.size() ? -1 : ans;
    }
};