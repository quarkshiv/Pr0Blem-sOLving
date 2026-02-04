class Solution {
public:
    vector<vector<int>>adj;
    vector<int>indegree;
    vector<int>vis;
    queue<int>q;
    int maxi=-1;
     int bfs(int node){
        queue<int>qq;
          int count=0;
          qq.push(node);
           vis[node]= 1;
          while(!qq.empty()){
               int node = qq.front();
               qq.pop();
               count++;
                for(auto it  : adj[node]){
                       if(!vis[it]){
                            vis[it]=1;
                            qq.push(it);
                       }
                }
          }
          return count;
     }

   vector<int> topos(){
            vector<int>ans;
            for(int i=0;i<indegree.size();i++){
                 if(indegree[i]==0){
                    q.push(i);
                    ans.push_back(i);
                 }
            }
            while(!q.empty()){
                    int node = q.front();
                      q.pop();
                   for(auto it : adj[node]){
                           indegree[it]--;
                           if(indegree[it]==0){
                                  q.push(it);
                                  ans.push_back(it);
                           }
                   }
            }
            return ans;
   }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        adj.assign(n, vector<int>());
        indegree.assign(n, 0);
        vis.assign(n, 0);

         for(int i=0;i<edges.size();i++){
               if(edges[i]!=-1){
               adj[i].push_back(edges[i]);
               indegree[edges[i]]++;
               }
         }

         vector<int>topo = topos();
         for(auto it : topo){
               vis[it]=1;
         }
         for(int i=0;i<adj.size();i++){
                if(!vis[i]){
                      maxi = max(bfs(i),maxi);
                }
         }

         if(maxi<0)return -1;
          return maxi;
    }
};
