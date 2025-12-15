class Solution {
public:
    vector<pair<int,int>>v;
    int solve(int i, int prev,int n,vector<vector<int>> &dp) {
        if (i == n) return 0;
        if (dp[i][prev+1]!=-1) return dp[i][prev+1];
        int notpick = solve(i + 1,prev, n,dp);
        int pick = 0;
        if (prev ==-1 || v[i].second >=v[prev].second) {
            pick = v[i].second + solve(i + 1,i, n,dp);
        }
        return dp[i][prev+1] = max(pick,notpick);
    }

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        for (int i = 0; i < n; i++)
            v.push_back({ages[i], scores[i]});

        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        }); 
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0, -1, n,dp);
    }
};
