class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix[0].size();
        int n = matrix.size();
        int l= 0 ;
        int r = m-1;
        while(l<n && r>=0){
               if(matrix[l][r]==target)return true;
               else if(matrix[l][r]>target)r--;
               else l++;
        }
        return false;
    }
};