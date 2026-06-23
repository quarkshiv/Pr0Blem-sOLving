class Solution {
public:
    int MOD = 1e9 + 7;
    int zigZagArrays(int n, int l, int r) {
        static int dp[2002][2002][2];
        int m = r - l + 1;
        for(int i = 1; i <= m; i++) {
            dp[n][i][0] = 1;
            dp[n][i][1] = 1;
        }
        for(int i = n - 1; i >= 0; i--) {
            vector<int> p0(m + 1), p1(m + 1);
            for(int j = 1; j <= m; j++) {
                p0[j] = (p0[j - 1] + dp[i + 1][j][0]) % MOD;
                p1[j] = (p1[j - 1] + dp[i + 1][j][1]) % MOD;
            }
            for(int j = 1; j <= m; j++) {
                dp[i][j][1] = (p0[m] - p0[j] + MOD) % MOD;
                dp[i][j][0] = p1[j - 1];
            }
        }
        int ans = 0;
        for(int i = 1; i <= m; i++) {
            ans = (ans + dp[1][i][0]) % MOD;
            ans = (ans + dp[1][i][1]) % MOD;
        }
        return ans;
    }
};