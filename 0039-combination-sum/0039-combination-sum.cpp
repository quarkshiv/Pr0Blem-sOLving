class Solution {
public: 
     void f(int ind,vector<int>& candidates, int target, vector<int>&arr,vector<vector<int>>&v){
        if(ind==candidates.size()){
            if(target==0){
                v.push_back(arr);
            }
            return;
        }
        f(ind+1,candidates,target,arr,v);
        if(candidates[ind]<=target){
             arr.push_back(candidates[ind]);
             f(ind,candidates,target-candidates[ind],arr,v);
             arr.pop_back();
        }
     }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>v;
        vector<int>arr;
        f(0,candidates,target,arr,v);
        return v;
    }
};