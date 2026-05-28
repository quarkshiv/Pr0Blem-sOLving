class Solution {
public:
   vector<vector<int>>dp;
   int lcs(int i,int j,string s,string t){
     if(i<0 || j<0)return 0;
     if(dp[i][j]!=-1)return dp[i][j];
     if(s[i]==t[j]){
           return dp[i][j] = 1 + lcs(i-1,j-1,s,t);
     }
     else return dp[i][j] = max(lcs(i-1,j,s,t),lcs(i,j-1,s,t));
   }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m  = word2.size();
         dp.assign(n,vector<int>(m,-1));
        int len = lcs(n-1,m-1,word1,word2);
        return n+m-2*len;
    }
};