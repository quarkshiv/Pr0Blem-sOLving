class Solution {
public:
     bool f(int ind,string s,unordered_set<string>&st,vector<int>&dp){
           if(ind==s.size())return true;
             if(dp[ind]!=-1)return dp[ind];
            bool ans=false;
            for(int i=ind;i<s.size();i++){
             if(st.count(s.substr(ind,i-ind+1)))ans|=f(i+1,s,st,dp);
             if(ans)return true;
            }
           return dp[ind]=ans;
     }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st(wordDict.begin(),wordDict.end());
        int n = s.size();
        vector<int>dp(n,-1);
        return f(0,s,st,dp);
        
    }
};