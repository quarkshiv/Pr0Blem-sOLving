class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& mat, int k) {
        int R = mat.size();
        int C = mat[0].size();
        int resR = R - k + 1;
        int resC = C - k + 1;

        vector<vector<int>> ans(resR, vector<int>(resC, 0));

        for (int r = 0; r <= R - k; r++) {
            vector<vector<int>> cols(C);
            for (int c = 0; c < C; c++) {
                for (int rr = r; rr < r + k; rr++) {
                    cols[c].push_back(mat[rr][c]);
                }
            }

            multiset<int> winset;
            for (int c = 0; c < k; c++) {
                for (int val : cols[c]) {
                    winset.insert(val);
                }
            }

            ans[r][0] = findMinDiffDistinct(winset);

            for (int cc = 1; cc <= C - k; cc++) {
                for (int val : cols[cc - 1]) {
                    auto it = winset.find(val);
                    if (it != winset.end()) winset.erase(it);
                }
                for (int val : cols[cc + k - 1]) {
                    winset.insert(val);
                }
                ans[r][cc] = findMinDiffDistinct(winset);
            }
        }

        return ans;
    }

private:
    int findMinDiffDistinct(const multiset<int>& s) {
        if (s.size() <= 1) return 0;

        set<int> distinctVals(s.begin(), s.end());

        if (distinctVals.size() <= 1) return 0;

        int mindiff = INT_MAX;
        auto prev = distinctVals.begin();
        for (auto it = next(distinctVals.begin()); it != distinctVals.end(); it++) {
            int diff = *it - *prev;
            if (diff < mindiff) mindiff = diff;
            prev = it;
        }
        return mindiff;
    }
};
