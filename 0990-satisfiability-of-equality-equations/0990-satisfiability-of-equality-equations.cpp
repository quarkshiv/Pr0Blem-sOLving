class DSU{
    public:
     vector<int>parent,rank;
     DSU(int n){
           parent.resize(n+1);
           rank.resize(n+1,0);
           for(int i=0;i<=n;i++){
            parent[i]=i;
           }
     }
     void unionbyr(int x,int y){
          int x_par=findupar(x);
          int y_par=findupar(y);
          if(x_par==y_par)return;
          if(rank[x_par]<rank[y_par]){
               parent[x_par]=y_par;
          }
          else if(rank[x_par]>rank[y_par]){
            parent[y_par]=x_par;
          }
          else{
              parent[y_par]=x_par;
              rank[x_par]++;
          }
     }
     int findupar(int node){
        if(node==parent[node])return node;
    return parent[node]=findupar(parent[node]);
     }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DSU dsu(26);
            for(auto it : equations){
                  if(it[1]=='='){
                      dsu.unionbyr(it[0]-'a',it[3]-'a');
                  }
            }
            for(auto it : equations){
                 if(it[1]=='!'){
                       if(dsu.findupar(it[0]-'a')==dsu.findupar(it[3]-'a'))return false;
                 }
            }      
            return true;
    }
};