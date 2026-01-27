class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
           int n  = heights.size();
           int m= heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        dist[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
              auto val =pq.top();
                  int diff= val.first;
                  int r=val.second.first;
                  int c=val.second.second;
                  pq.pop();
                  if(r==n-1 && c==m-1){
                    return diff;
                  }
                for(int delrow=-1;delrow<=1;delrow++){
                for(int delcol=-1;delcol<=1;delcol++){
                     if(abs(delrow)+abs(delcol)==1){
                     int nrow = r + delrow;
                    int ncol = c+delcol;
                    if(nrow<n && nrow>=0 && ncol<m && ncol>=0){
                              int neweffort = max(abs(heights[r][c] - heights[nrow][ncol]),diff);
                              if(neweffort<dist[nrow][ncol]){
                                dist[nrow][ncol] = neweffort;
                                pq.push({neweffort,{nrow,ncol}});

        }
                    }
        }
                }}}
        return 0;
    }
};