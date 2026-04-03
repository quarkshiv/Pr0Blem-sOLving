class Solution {
public:
    bool bs(vector<int>& arr,int target){
           int low=0;
           int n= arr.size();
           int high = n-1;
           while(low<=high){
               int mid = (low + high)/2;
               if(arr[mid]==target)return true;
               if(arr[mid]>target)high =mid-1;
               else low=  mid+1;
           }
       return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++){
               if(bs(matrix[i],target))return true;
        }
        return false;
    }
};