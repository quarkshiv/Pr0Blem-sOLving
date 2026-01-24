class Solution {
public:
    static const int N = 1e5+5;
    long long dp[N][4][3];
    long long f(int ind, int cnt, int prev, const string &s) {
        if (cnt==3) return 1;
        if (ind == (int)s.size()) return 0;
        long long &memo = dp[ind][cnt][prev];
        if (memo != -1) return memo;
        long long ans = f(ind + 1, cnt, prev, s);

        int cur = s[ind] - '0';
        if (prev == 2 || cur != prev) {
            ans += f(ind + 1, cnt + 1, cur, s);
        }
        return memo=ans;
    }

    long long numberOfWays(string s) {
        memset(dp, -1, sizeof(dp));
        return f(0, 0, 2, s);
    }
};
