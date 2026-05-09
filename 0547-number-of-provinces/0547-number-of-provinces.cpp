class Solution {
public:
   void bfs(int node,vector<int>&vis, vector<vector<int>>&adj){
    queue<int>q;
    vis[node]=1;
    q.push(node);
    while(!q.empty()){
          int c = q.front();
          q.pop();
          for(auto it : adj[c]){
              if(!vis[it]){
                 vis[it]=1;
                 q.push(it);
              }
          }
    }
   }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
               if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
               }
           }
        }
        int ans=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                 ans++;
                 bfs(i,vis,adj);
            }
        }
        return ans;
    }
};