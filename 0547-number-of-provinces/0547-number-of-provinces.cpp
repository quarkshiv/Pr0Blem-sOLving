class Solution {
public:
   void bfs(vector<vector<int>>&adj,int node,vector<int>&vis){
      vis[node]=1;
       queue<int>q;
       q.push(node);
      while(!q.empty()){
          int it=q.front();
        q.pop();
        for(auto n : adj[it]){
               if(!vis[n]){
                  vis[n]=1;
                  q.push(n);
               }
        }
      }
   }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
             for(int j=0;j<n;j++){
                 if(i!=j && isConnected[i][j]==1){
                    adj[i].push_back(j);
                 }
             }
        }
          vector<int>vis(n,0);
          int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                  cnt++;
                  bfs(adj,i,vis);
            }
        }
        return cnt;
    }
};