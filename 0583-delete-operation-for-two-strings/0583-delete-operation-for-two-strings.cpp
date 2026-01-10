class Solution {
public:
    int f(int i,int j,string &word1, string &word2,vector<vector<int>>&dp){
        int n=word1.size();
        int m=word2.size();
         if(i==n || j==m){
            return 0;
         }
         if(dp[i][j]!=-1){
            return dp[i][j];
         }
           if(word1[i]==word2[j]){
              return dp[i][j]=1+f(i+1,j+1,word1,word2,dp);
           }
           else{
              return dp[i][j]= max(f(i+1,j,word1,word2,dp),f(i,j+1,word1,word2,dp));
           }
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
         vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
         int len = f(0,0,word1,word2,dp);
         return n+m-2*len;
    }
};