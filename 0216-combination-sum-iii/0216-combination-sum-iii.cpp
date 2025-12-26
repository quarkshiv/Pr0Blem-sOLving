class Solution {
public:
    void f(int ind,int k,int n, vector<vector<int>>&v,vector<int>&arr){
          if(arr.size()==k && n==0){
            v.push_back(arr);
            return;
          }
          for(int i=ind;i<=9;i++){
                arr.push_back(i);
                f(i+1,k,n-i,v,arr);
                arr.pop_back();
          }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>v;
        vector<int>arr;
         f(1,k,n,v,arr);
         return v;
    }
};