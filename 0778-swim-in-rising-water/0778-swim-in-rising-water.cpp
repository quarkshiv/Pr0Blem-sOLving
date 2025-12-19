class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>>pq;
        pq.push({grid[0][0],{0,0}});
        dist[0][0] = grid[0][0];
        while(!pq.empty()){
            int time  = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(row==n-1 && col==n-1){
                return time;
            }
            for(int delrow=-1;delrow<=1;delrow++){
             for(int delcol=-1;delcol<=1;delcol++){
                if(abs(delcol)+abs(delrow)==1){
                    int nrow = row + delrow;
                    int ncol= col + delcol;
                    if(nrow<n && nrow>=0 && ncol<n && ncol>=0){
                           int newtime = max(time,grid[nrow][ncol]);
                             if(newtime<dist[nrow][ncol]){
                                dist[nrow][ncol]= newtime;
                                pq.push({newtime,{nrow,ncol}});
                             }
                    }
                }
             }
            }
        }
        return -1;
    }
};