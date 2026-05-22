class Solution {
public:
    int bfs(int r,int c,vector<vector<int>>&grid){
        int n = grid.size();
        int m = grid[0].size();
            vector<vector<int>>vis(n,vector<int>(m,0));
            queue<pair<int,pair<int,int>>>q;
            q.push({grid[r][c],{r,c}});
            vis[r][c]=1;
            int ans=0;
            while(!q.empty()){
                  int fish = q.front().first;
                  int row= q.front().second.first;
                   int col= q.front().second.second;
                  q.pop();
                  ans+=fish;
                  for(int delr=-1;delr<=1;delr++){
                     for(int delc=-1;delc<=1;delc++){
                       if(abs(delr)+abs(delc)==1){
                             int nr =row+delr;
                             int nc = col + delc;
                             if(nr<n && nc<m && nr>=0 && nc>=0 && grid[nr][nc]>0 && !vis[nr][nc]){
                                   vis[nr][nc]=1;
                                   q.push({grid[nr][nc],{nr,nc}});
                             }
                        
                       }
                  }
            }
            }
            return ans;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int maxcnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                  if(grid[i][j]>0){
                       int cnt= bfs(i,j,grid);
                       if(cnt>maxcnt){
                           maxcnt=cnt;
                       }
                  }
            }
        }
        return maxcnt;
    }
};