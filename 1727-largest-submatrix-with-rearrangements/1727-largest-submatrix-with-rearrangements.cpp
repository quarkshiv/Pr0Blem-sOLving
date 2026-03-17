class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;

        // Build heights in-place
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    matrix[i][j] += matrix[i - 1][j];
                }
            }
        }

        for (int i = 0; i < m; i++) {
            sort(matrix[i].begin(), matrix[i].end(), greater<int>());

            for (int width = 1; width <= n; width++) {
                int h = matrix[i][width - 1];
                ans = max(ans, h * width);
            }
        }

        return ans;
    }
};