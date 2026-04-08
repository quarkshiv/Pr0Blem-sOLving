class Solution {
public:
      void f(int ind,int k,int n,vector<vector<int>>&f_ans,vector<int>&ans){
          if(ans.size()==k&&n==0)
          {
            f_ans.push_back(ans);
            return;
          }
          for(int i=ind;i<=9;i++){
                 ans.push_back(i);
                 f(i+1,k,n-i,f_ans,ans);
                 ans.pop_back();
          }
      }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>f_ans;
        vector<int>ans;
        f(1,k,n,f_ans,ans);
        return f_ans;
    }
};