class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> arr;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                arr.push_back(grid[i][j]);
            }
        }

        int newN = arr.size();

        vector<int> pre(newN, 1), suf(newN, 1);

        for(int i=1; i<newN; i++){
            pre[i] = (1LL * pre[i-1] * arr[i-1]) % 12345;
        }

        for(int i=newN-2; i>=0; i--){
            suf[i] = (1LL * arr[i+1] * suf[i+1]) % 12345;
        }

        vector<int> res(newN);

        for(int i=0; i<newN; i++){
            res[i] = (1LL * pre[i] * suf[i]) % 12345;
        }

        vector<vector<int>> ans(m, vector<int>(n));

        int idx = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans[i][j] = res[idx++];
            }
        }

        return ans;
    }
};