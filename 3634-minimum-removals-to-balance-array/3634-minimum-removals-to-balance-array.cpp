class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int ans=INT_MAX;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int l=0;
        for(int r=0;r<nums.size();r++){
              while((long long)nums[l]*k<nums[r]){
                        l++;
              }
              ans= min(ans,n-(r-l+1));
        }
        return ans;
    }
};