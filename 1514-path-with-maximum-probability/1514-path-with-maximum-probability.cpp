class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>>adj(n);
        for(int i=0;i<edges.size();i++){
               int u= edges[i][0];
               int v= edges[i][1];
               double prob=succProb[i];
               adj[u].push_back({v,prob});
               adj[v].push_back({u,prob});
        }
         vector<double>ans;
         priority_queue<pair<double,int>>pq;
         vector<double>dist(n,INT_MIN);
         pq.push({1,start});
            while(!pq.empty()){
                  double prob= pq.top().first;
                  int node=pq.top().second;
                  pq.pop();
                  if(node==end){
                    ans.push_back(prob);
                    continue;
                  }
                    for(auto it : adj[node]){
                           if(dist[it.first]<prob*it.second){
                                dist[it.first]=prob*it.second;
                                pq.push({dist[it.first],it.first});
                           }
                    }
            }
            for(auto it:ans){
                cout<<it<<endl;
            }
            if(ans.empty()){
                return 0;
            }
            sort(ans.rbegin(),ans.rend());
            return ans[0];
    }
};