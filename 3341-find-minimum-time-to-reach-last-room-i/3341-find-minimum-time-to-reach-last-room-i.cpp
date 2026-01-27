class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
              int n= moveTime.size();
              int m=moveTime[0].size();
            vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
            dist[0][0]=0;
            priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
            pq.push({0,{0,0}});
            while(!pq.empty()){
                  auto val =pq.top();
                  int time= val.first;
                  int r=val.second.first;
                  int c=val.second.second;
                  pq.pop();
                if (time > dist[r][c]) continue;
                  if(r==n-1 && c==m-1){
                     return time;
                  }
                      for(auto delr=-1;delr<=1;delr++){
                         for(auto delc=-1;delc<=1;delc++){
                              if(abs(delc)+abs(delr)==1){
                                   int nr =r +delr;
                                   int nc=c+delc;
                                   if(nr>=0 && nr<n && nc>=0 && nc<m){
                                      int maxtime = max(time,moveTime[nr][nc])+1;
                                      if(dist[nr][nc]>maxtime){
                                                 dist[nr][nc]=maxtime;
                                                 pq.push({dist[nr][nc],{nr,nc}});
                                      }
                                   }
                              }
                         }
                      }

            }
            return -1;
    }
};