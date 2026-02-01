class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pref=1;
        int suff=1;
        int n = nums.size();
        vector<int>ans(n,1);
        for(int i=0;i<nums.size();i++){
              ans[i]*=pref;
              pref*=nums[i];
        }
        for(int i=nums.size()-1;i>=0;i--){
              ans[i]*=suff;
              suff*=nums[i];
        }
        return ans;
    }
};