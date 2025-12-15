class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        int l = 0, r = 0;
        long long ans = n;
        while (r<n-1) {
            if (prices[r]-prices[r+1]==1) {
                r++;
            } else {
                int len = r-l+1;
                ans += 1LL*len*(len -1)/2;
                r++;
                l = r;
            }
        }
        int len = r - l + 1;
        ans += 1LL * len * (len - 1) / 2;
        return ans;
    }
};
