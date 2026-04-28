class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        for(auto row : grid){
            for(auto val : row){
                arr.push_back(val);
            }
        }
        int rem = arr[0] % x;
        for(auto val : arr){
            if(val % x != rem) return -1;
        }
        sort(arr.begin(), arr.end());
        int median = arr[arr.size() / 2];
        int op= 0;
        for(auto val : arr){
            op += abs(val - median) / x;
        }
              return op;
    }
};