class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
           vector<vector<int>> ans(n,vector<int>(m, 0));
        vector<vector<int>>dist(n,vector<int>(m, 1e9));
        queue<pair<int, pair<int,int>>> q;
        for (auto it : sources) {
            q.push({it[2], {it[0], it[1]}});
            ans[it[0]][it[1]] = it[2];
            dist[it[0]][it[1]] = 0;
        }
          while(!q.empty()){
                auto [color, rc] = q.front();
                 auto [r, c] = rc;
                q.pop();
                 for (int delr = -1; delr <= 1; delr++) {
                for (int delc = -1; delc <= 1; delc++) {
                    if (abs(delr) + abs(delc) == 1) {
                        int nr = r + delr;
                        int nc = c + delc;
                        if (nr >= 0 && nr < n && nc >= 0 && nc<m){
                             if(dist[nr][nc] > dist[r][c] + 1) {
                                dist[nr][nc] = dist[r][c] + 1;
                                ans[nr][nc] = color;
                                q.push({color, {nr, nc}});
                            }
                             else if (dist[nr][nc] == dist[r][c] + 1) {
                                if (ans[nr][nc] < color) {
        ans[nr][nc] = color;
        q.push({color, {nr, nc}});
    }

          }
                        }

           
    }
                }
                 }
          }
          return ans;
    }
};