class Solution {
public:
    string s;
    long long n;

    long long dpCnt[16][100];
    long long dpWave[16][100];
    bool vis[16][100];

    pair<long long,long long> dfs(int pos, int pp, int p, bool tight, bool lead) {
        if (pos == n) return {1, 0};

        long long key = (pp < 0 ? 0 : pp) * 10 + (p < 0 ? 0 : p);

        if (!tight && !lead && pp >= 0 && p >= 0 && vis[pos][key]) {
            return {dpCnt[pos][key], dpWave[pos][key]};
        }

        int lim = tight ? s[pos] - '0' : 9;

        long long cnt = 0;
        long long wave = 0;

        for (int d = 0; d <= lim; d++) {
            bool nlead = lead && (d == 0);

            long long npp = p;
            long long np = nlead ? -1 : d;

            auto [rcnt, rwave] =
                dfs(pos + 1, npp, np, tight && (d == lim), nlead);

            if (!nlead && pp >= 0 && p >= 0) {
                bool peak = (pp < p && p > d);
                bool valley = (pp > p && p < d);

                if (peak || valley) wave += rcnt;
            }

            cnt += rcnt;
            wave += rwave;
        }

        if (!tight && !lead && pp >= 0 && p >= 0) {
            vis[pos][key] = 1;
            dpCnt[pos][key] = cnt;
            dpWave[pos][key] = wave;
        }

        return {cnt, wave};
    }

    long long calc(long long x) {
        if (x < 100) return 0;

        memset(dpCnt, 0, sizeof(dpCnt));
        memset(dpWave, 0, sizeof(dpWave));
        memset(vis, 0, sizeof(vis));

        s = to_string(x);
        n = s.size();

        return dfs(0, -1, -1, 1, 1).second;
    }

    long long totalWaviness(long long num1, long long num2) {
        return calc(num2) - calc(num1 - 1);
    }
};