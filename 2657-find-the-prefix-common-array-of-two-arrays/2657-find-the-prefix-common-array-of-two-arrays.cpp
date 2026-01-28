class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
          unordered_map<int,int>mpp;
          int n= A.size();
          vector<int>ans(n,0);
          for(int i=0;i<A.size();i++){
               mpp[A[i]]++;
               mpp[B[i]]++;
               int cnt=0;
               for(auto it : mpp){
                  if(it.second==2){
                     cnt++;
                  }
               }
               ans[i]=cnt;
          }
          return ans;
    }
};