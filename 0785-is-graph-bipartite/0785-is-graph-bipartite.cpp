class Solution {
public:
  bool dfs(int node,int color,vector<vector<int>>& graph,  vector<int>&col){
    col[node]=color;
    for(auto it : graph[node]){
        if(col[it]==col[node]){
            return false;
        }
        if(col[it]==-1){
         if(!dfs(it,!color,graph,col)) return false;
    }
    }
    return true;
  }
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size(); 
         vector<int>col(v,-1);
          for(int i=0;i<v;i++){
            if(col[i]==-1){
                if(!dfs(i,0,graph,col))return false;
            }
          }
          return true;
    }
};