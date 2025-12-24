class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s[0]=='0'){
                 return 0;
        }
        int n =s.size();
        vector<int>dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
           for(int i=2;i<=s.size();i++){
                int x=(s[i-1]-'0');
                 int y = stoi(s.substr(i-2,2));
                 if(x!=0){
                    dp[i]+=dp[i-1];
                 }
                 if(y>=10 && y<=26){
                       dp[i]+=dp[i-2];
                 }
           }
           return dp[n];
    }
};