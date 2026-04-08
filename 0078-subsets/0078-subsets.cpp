class Solution {
public:
     void f(int ind,vector<int>& nums,vector<int>&ans,vector<vector<int>>&f_ans){
           if(ind==nums.size()){
                 f_ans.push_back(ans);
                 return;
           }
           ans.push_back(nums[ind]);
           f(ind+1,nums,ans,f_ans);
           ans.pop_back();
           f(ind+1,nums,ans,f_ans);
      }
    vector<vector<int>> subsets(vector<int>& nums) {
          vector<vector<int>>f_ans;
          vector<int>ans;
          f(0,nums,ans,f_ans);
          return f_ans;
    }
};