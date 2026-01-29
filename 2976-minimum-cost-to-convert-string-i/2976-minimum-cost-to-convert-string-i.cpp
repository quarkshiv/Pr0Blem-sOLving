class Solution {
public:
   vector<long long>bfs(int src,vector<vector<pair<int,int>>>& adj) {
        vector<long long> dist(26,1e18);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>> pq;
        dist[src] = 0;
        pq.push({0, src});
        while (!pq.empty()) {
             int distance = pq.top().first;
             int node= pq.top().second;
            pq.pop();
            for (auto it: adj[node]) {
                if (dist[it.first] > distance + it.second) {
                    dist[it.first] = distance +it.second;
                    pq.push({dist[it.first], it.first});
                }
            }
        }
        return dist;
    }
    
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<pair<int,int>>> adj(26);
        for (int i = 0; i < original.size(); i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            adj[u].push_back({v, cost[i]});
        }
        vector<int>vis(26,0);
        vector<vector<long long>> mincost(26);
             long long ans = 0;
        for (int i = 0; i < source.size(); i++) {
            int s = source[i] - 'a';
            int t = target[i] - 'a';
            if (s == t) continue;
            if (!vis[s]) {
                mincost[s] = bfs(s, adj);
                    vis[s] = 1;
                   }
              if(mincost[s][t]==1e18){
                return -1;
              }
                 ans+=mincost[s][t];

    }
    return ans;
    }
};