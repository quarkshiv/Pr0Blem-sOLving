class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int n = routes.size();
        if(source==target){
            return 0;
        }
        unordered_map<int,vector<int>>adj;
          for(int i=0;i<routes.size();i++){
               for(int it: routes[i]){  //it is stop and i is the route
                adj[it].push_back(i);
               }
          }
         queue<int>q;
         int buses=1;
         vector<int>vis(n,0);
         for(auto &it : adj[source]){
            q.push(it);
            vis[it]=1;
         } 
         while(!q.empty()){
              int size = q.size();
              while(size--){
                  int route= q.front();
                  q.pop();
                  for(auto stop: routes[route]){
                       if(stop==target){
                        return buses;
                       }
                       for(auto nextstop : adj[stop]){
                              if(!vis[nextstop]){
                                vis[nextstop]=1;
                                q.push(nextstop);
                              }
                       }                         
                  }

              }
              buses++;

         }
         return -1;
    }
};