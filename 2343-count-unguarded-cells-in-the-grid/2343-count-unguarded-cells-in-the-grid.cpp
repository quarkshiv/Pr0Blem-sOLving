class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> vis(m, vector<int>(n, 0));
        // 0 = empty
        // 1 = guarded
        // 2 = wall
        // 3 = guard
        for (auto it : walls) {
            vis[it[0]][it[1]] = 2;
        }
        for (auto it : guards) {
            vis[it[0]][it[1]] = 3;
        }

        queue<pair<int, int>> q;
        for (auto it : guards) {
            q.push({it[0], it[1]});
        }
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            int i = row + 1;
            while (i < m && vis[i][col] != 2 && vis[i][col] != 3) {
                vis[i][col] = 1;
                i++;
            }
            i = row - 1;
            while (i >= 0 && vis[i][col] != 2 && vis[i][col] != 3) {
                vis[i][col] = 1;
                i--;
            }
            int j = col - 1;
            while (j >= 0 && vis[row][j] != 2 && vis[row][j] != 3) {
                vis[row][j] = 1;
                j--;
            }
            j = col + 1;
            while (j < n && vis[row][j] != 2 && vis[row][j] != 3) {
                vis[row][j] = 1;
                j++;
            }
        }
        int unguard = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == 0)
                    unguard++;
            }
        }

        return unguard;
    }
};
