class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int cntneg=0;
        int minabs=INT_MAX;
        long long sum=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                 minabs = min(minabs,abs(matrix[i][j]));
                  sum+=abs(matrix[i][j]);
                  if(matrix[i][j]<0){
                       cntneg++;
                  }
            }
        }
        if(cntneg%2){
            return sum-1LL*2*(minabs);
        }
        return sum;
    }
};