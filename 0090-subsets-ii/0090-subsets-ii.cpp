class Solution {
public:
    void f(int ind,vector<int>&nums,vector<int>&ans,vector<vector<int>>&f_ans){
            f_ans.push_back(ans);
             for(int i=ind;i<nums.size();i++){
                  if(i>ind && nums[i]==nums[i-1])continue;
                     ans.push_back(nums[i]);
                     f(i+1,nums,ans,f_ans);
                     ans.pop_back();
             }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>f_ans;
        vector<int>ans;
        f(0,nums,ans,f_ans);
        return f_ans;
    }
};