
class Solution {
public:

    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<long long >>>dp(n,vector<vector<long long>>(k+1,vector<long long>(3,LLONG_MIN/4)));
           dp[0][0][0]=0;
           dp[0][0][1]=-prices[0];
           dp[0][0][2]=+prices[0];
           for(int i=1;i<prices.size();i++){
            for(int t=0;t<=k;t++){
                dp[i][t][0] = dp[i-1][t][0];
                if(t>0){
                dp[i][t][0] = max(dp[i][t][0], dp[i-1][t-1][1] + prices[i]);
                dp[i][t][0] = max(dp[i][t][0], dp[i-1][t-1][2] - prices[i]);
             }
             dp[i][t][1]= max(dp[i-1][t][1],dp[i-1][t][0]-prices[i]);
               dp[i][t][2]= max(dp[i-1][t][2],dp[i-1][t][0]+prices[i]);
           }
    }
    long long ans=0;
    for(int i=0;i<=k;i++){
        ans= max(ans,dp[n-1][i][0]);
        
    }
    return ans;
    }
};