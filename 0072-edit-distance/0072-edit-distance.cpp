class Solution {
public:
  int f(int ind1,int ind2,string&w1,string&w2, vector<vector<int>>&dp){
         int n= w1.size();
        int m = w2.size();
          if(ind1==n){
            return m-ind2;
          }
          if(ind2==m){
            return n-ind1;
          }
          if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
          }
          if(w1[ind1]==w2[ind2]){
             return dp[ind1][ind2]= f(ind1+1,ind2+1,w1,w2,dp);
          }
         else{
              return dp[ind1][ind2] = 1 + min({f(ind1+1,ind2,w1,w2,dp),f(ind1,ind2+1,w1,w2,dp), f(ind1+1,ind2+1,w1,w2,dp)});
         }
  }
    int minDistance(string word1, string word2) {
        int n= word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(0,0,word1,word2,dp);
    }
};