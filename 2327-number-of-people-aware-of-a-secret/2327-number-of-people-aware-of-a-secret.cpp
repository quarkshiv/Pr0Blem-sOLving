class Solution {
public:
const int MOD=1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int>dp(n+1,0);  //kitna logo ko pata rahega Ith day pe
        dp[1]=1;
        long long window=0;
        for(int day=2;day<=n;day++){
               int enter = day-delay;
               int exit = day-forget;
               if(enter>=1){
                  window = (window + dp[enter])%MOD;
               }
               if(exit>=1){
                  window = (window-dp[exit] + MOD)%MOD;
               }
               dp[day]=window;
        }
        int i = n-forget+1;
        int ans=0;
        while(i<=n){
              ans=(ans+dp[i])%MOD;
              i++;
        }
        return ans;
    }
};