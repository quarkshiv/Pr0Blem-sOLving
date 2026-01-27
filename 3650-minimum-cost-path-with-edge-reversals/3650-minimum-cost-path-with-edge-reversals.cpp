class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
     vector<vector<pair<int,int>>>adj(n);
        for(auto it : edges){
              int u=it[0];
              int v=it[1];
              int w=it[2];
              adj[u].push_back({v,w});
              adj[v].push_back({u,2*w});
        }
        vector<int>dist(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[0]=0;
        pq.push({0,0});
        while(!pq.empty()){
              int weight= pq.top().first;
              int node= pq.top().second;
              pq.pop();
              if(node==n-1){
                return dist[node];
              }
              for(auto it : adj[node]){
                  if(dist[it.first]>weight + it.second){
                        dist[it.first]=weight+it.second;
                        pq.push({dist[it.first],it.first});
                  }
              }
                      }
                      return -1;
    }
};