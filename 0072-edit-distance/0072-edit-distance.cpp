class Solution {
public:
     int f(int i,int j,string& s, string& t,vector<vector<int>>&dp){
         int n = s.size();
        int m =t.size();
        if(i==n){
            return m-j;
        }
        if(j==m){
            return n-i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==t[j]){
             return dp[i][j]= f(i+1,j+1,s,t,dp);
        }
        else{
             return dp[i][j] = min({1+f(i+1,j,s,t,dp),1+f(i,j+1,s,t,dp),1+f(i+1,j+1,s,t,dp)});
        }
     }
    int minDistance(string word1, string word2) {
        if(word1.empty()){
            return word2.size();
        }
        if(word2.empty()){
            return word1.size();
        }
        int n = word1.size();
        int m =word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(0,0,word1,word2,dp);

    }
};