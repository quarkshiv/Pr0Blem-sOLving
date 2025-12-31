class Solution {
public:
      bool canreach(int day,int row,int col,vector<vector<int>>& cells){
          vector<vector<int>>vis(row,vector<int>(col,0));
           vector<vector<int>> grid(row, vector<int>(col, 0));
        for (int i = 0;i<day; i++) {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            grid[r][c] = 1;
        }
            queue<pair<int,int>>q;
            for(int i=0;i<col;i++){
                if(grid[0][i]==0){
             vis[0][i]=1;
             q.push({0,i});
            }
            }
             while(!q.empty()){
                  int r =q.front().first;
                  int c= q.front().second;
                  q.pop();
                  if(r==row-1){
                    return true;
                  }
                  for(int delrow=-1;delrow<=1;delrow++){
                    for(int delcol=-1;delcol<=1;delcol++){
                           if(abs(delcol)+abs(delrow)==1){
                                  int nr = r + delrow;
                                  int nc =  c+delcol;
                                  if(nr>=0 && nr<row && nc>=0 && nc<col && !vis[nr][nc] && grid[nr][nc]==0){
                                     q.push({nr,nc});
                                     vis[nr][nc]=1;
                                  }
                           }
                    }
                  }
             }
             return false;
      }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int low=1;
        int high=cells.size();
        int ans=0;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(canreach(mid,row,col,cells)){
                ans=mid;
                low = mid+1;
            }
            else high =mid-1;
        }
        return ans;
    }
};