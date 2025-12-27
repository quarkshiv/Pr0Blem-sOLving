class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target){
            return 0;
        }
        int n = routes.size();
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<routes.size();i++){
            for(auto it : routes[i]){
              adj[it].push_back(i);
            }
        }
        vector<int>vis(n,0);
        queue<int>q;
        for(auto it : adj[source]){
               vis[it]=1;
               q.push(it);
        }
        int buses=1;
        while(!q.empty()){
               int size = q.size();
               while(size--){
                   int route = q.front();
                   q.pop();
                for(auto stop : routes[route]){
                        if(stop==target){
                            return buses;
                        }
                        for(auto nextroutes : adj[stop]){
                                if(!vis[nextroutes]){
                                     vis[nextroutes]=1;
                                     q.push(nextroutes);
                                }
                        }
                }
               }
               buses++;
        }
         return -1;
    }
};