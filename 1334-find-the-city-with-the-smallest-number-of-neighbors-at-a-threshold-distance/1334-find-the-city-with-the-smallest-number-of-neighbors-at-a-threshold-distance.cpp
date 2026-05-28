class Solution {
public:
  int diju(int node,vector<vector<pair<int,int>>>&adj,int dt,int n){
    vector<int>dist(n,dt+1);
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
     pq.push({0,node});
     dist[node]=0;
     int cnt=0;
     while(!pq.empty()){
        int dst = pq.top().first;
         int node=  pq.top().second;
         pq.pop();
         for(auto it : adj[node]){
             if(dst+it.second<=dist[it.first]&& dst+it.second<=dt){
                  dist[it.first]=dst + it.second;
                  pq.push({dist[it.first],it.first});
             }
         }
     }
     for(int i=0;i<n;i++){
         if(i!=node && dist[i]<=dt)cnt++;
     }
     return cnt;
  }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int ans=INT_MAX;
        int node=-1;
        vector<vector<pair<int,int>>>adj(n);
        for(auto it : edges){
           adj[it[0]].push_back({it[1],it[2]});
           adj[it[1]].push_back({it[0],it[2]});
        }
       for(int i=0;i<n;i++){
          int val = diju(i,adj,distanceThreshold,n);
          if(val<=ans){
            ans= val;
            node = i;
          }
       }
       return node;
    }
};