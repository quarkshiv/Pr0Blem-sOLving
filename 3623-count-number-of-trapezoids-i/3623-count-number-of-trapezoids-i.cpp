class Solution {
public:
    const long long MOD =1e9+7;
    long long countTrapezoids(vector<vector<int>>& a) {
        unordered_map<int,long long> freq;
        for(auto &p : a) {
            int y = p[1];
            freq[y]++;
        }
        vector<long long> b;
        for(auto &it : freq) {
            long long v = it.second;
            if(v >= 2) b.push_back(v * (v - 1) / 2);
        }
        if(b.size() < 2) return 0;
        long long ans = 0, pref = 0;
        for(long long x :b) {
            ans= (ans + (x % MOD) * (pref % MOD)) % MOD;
            pref =(pref + x) % MOD;
        }
        return ans;
    }
};
