class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>pref(m+1, vector<int>(n+1, 0));
        for (int i = 0;i<m; i++) {
            for (int j =0;j<n;j++) {
                pref[i+1][j+1] = grid[i][j] + pref[i][j+1] + pref[i+1][j] - pref[i][j];
                if (pref[i+1][j+1]<=k) ans++;
            }
        }
        return ans;
    }
};