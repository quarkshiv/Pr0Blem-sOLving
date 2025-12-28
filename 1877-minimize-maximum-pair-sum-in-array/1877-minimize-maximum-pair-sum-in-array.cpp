class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l=0;
        int r=nums.size()-1;
        vector<int>v;
        while(l<=r){
              v.push_back(nums[l]+nums[r]);
                  l++;
                  r--;
              }
        return *max_element(v.begin(),v.end());
    }
};