class Solution {
public:
  int dijikstra(int node, vector<vector<pair<int,int>>>& adj, int thres){
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<>> pq;
    pq.push({0,node});
    set<int>vis;
    while(!pq.empty()){
        int dist = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(vis.count(cur)) continue;
        vis.insert(cur);

        for(auto it : adj[cur]){
            if(dist + it.second <= thres){
                pq.push({dist + it.second, it.first});
            }
        }
    }
    return vis.size() - 1;
}
    int findTheCity(int n, vector<vector<int>>& edges, int thres) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it: edges){
            adj[it[0]].push_back({it[1],it[2]});
              adj[it[1]].push_back({it[0],it[2]});
        }
        int mini=n;
        int ans=0;
        for(int i=0;i<n;i++){
            int nb = dijikstra(i,adj,thres);
            if(nb<=mini){
                mini=nb;
                ans = i;
            }
        }
        return ans;
    }
};