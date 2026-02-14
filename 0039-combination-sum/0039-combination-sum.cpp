class Solution {
public:
      void f(int ind,vector<int>&candidates,int target,vector<vector<int>>&f_ans,vector<int>&ans){
        if(ind==candidates.size()){
             if(target==0){
                f_ans.push_back(ans);
             }
             return;
        }
        if(candidates[ind]<=target){
            ans.push_back(candidates[ind]);
            f(ind,candidates,target-candidates[ind],f_ans,ans);
            ans.pop_back();
        }
        f(ind+1,candidates,target,f_ans,ans);
      }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>f_ans;
        vector<int>ans;
        f(0,candidates,target,f_ans,ans);
        return f_ans;
    }
};