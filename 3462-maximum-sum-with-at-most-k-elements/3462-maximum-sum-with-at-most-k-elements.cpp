class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
    for(auto &row : grid){
    sort(row.rbegin(), row.rend());
}
vector<int>arr;
for(int i=0;i<grid.size();i++){
    for(int j=0;j<limits[i];j++){
        arr.push_back(grid[i][j]);
    }
}
   priority_queue<int,vector<int>,greater<>>pq;
   long long sum=0;
   long long maxsum=0;
   for(auto it : arr){
      pq.push(it);
      sum+=it;
    if(pq.size()>k){
         sum-=pq.top();
         pq.pop();
    }
    maxsum =  max(maxsum,sum);
   }
   return maxsum;
    }
};