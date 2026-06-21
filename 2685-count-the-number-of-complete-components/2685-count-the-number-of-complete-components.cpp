class Solution {
public:
   void dfs(int node,vector<vector<int>>& adj,vector<int>&compo,vector<int>&vis){
                     vis[node]=1;
                      compo.push_back(node);
                     for(auto it: adj[node]){
                        if(!vis[it]){
                            dfs(it,adj,compo,vis);
                     }
                     }
   }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        int ans=0;
        for(auto it:  edges){
              adj[it[0]].push_back(it[1]);
               adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vector<int>compo;
             bool   valid= true;
                dfs(i,adj,compo,vis);
                for(auto it : compo){
                    if(compo.size()-1!=adj[it].size()){valid= false;break;}

                }
                if(valid)ans++;
            }
        }
        return ans;
    }
};