class Solution {
public:
    void f(int ind,vector<int>& candidates, int target, vector<int>&ans,vector<vector<int>>&f_ans){
          if(target==0){
                 f_ans.push_back(ans);
                 return;
            }
          for(int i=ind;i<candidates.size();i++){
                 if(i>ind && candidates[i]==candidates[i-1])continue;
                 if(candidates[i]>target)break;
                 ans.push_back(candidates[i]);
                 f(i+1,candidates,target-candidates[i],ans,f_ans);
                 ans.pop_back();
          }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>f_ans;
        vector<int>ans;
        f(0,candidates,target,ans,f_ans);
        return f_ans;
    }
};