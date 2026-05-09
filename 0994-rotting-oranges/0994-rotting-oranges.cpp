class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int freshcnt = 0;
        int cnt = 0;

        queue<pair<int, pair<int,int>>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 1)
                    freshcnt++;

                if(grid[i][j] == 2) {
                    q.push({0, {i, j}});
                    vis[i][j] = 1;
                }
            }
        }

        if(freshcnt == 0) return 0;
        int maxtm=0;
        while(!q.empty()) {
            int time = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;

            q.pop();

            maxtm = max(maxtm,time);

            for(int delr = -1; delr <= 1; delr++) {
                for(int delc = -1; delc <= 1; delc++) {

                    if(abs(delr) + abs(delc) == 1) {

                        int nr = r + delr;
                        int nc = c + delc;

                        if(nr >= 0 && nr < n &&
                           nc >= 0 && nc < m &&
                           grid[nr][nc] == 1 &&
                           !vis[nr][nc]) {

                            vis[nr][nc] = 1;
                            cnt++;

                            q.push({time + 1, {nr, nc}});
                        }
                    }
                }
            }
        }

        if(cnt!=freshcnt)return -1;
        return maxtm;
    }
};