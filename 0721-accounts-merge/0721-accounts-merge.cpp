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
    void unbyr(int x,int y){
          int x_par= findpar(x);
          int y_par=findpar(y);
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
    int findpar(int node){
          if(parent[node]==node)return node;
          return parent[node]=findpar(parent[node]);
    }

};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU dsu(n);
        unordered_map<string,int>mapmailnode;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail = accounts[i][j];
                if(!mapmailnode.count(mail)){
                      mapmailnode[mail]=i;
                }
                else{
                      dsu.unbyr(mapmailnode[mail],i);
                }
            }
        }
        vector<vector<string>>mergedmail(n);
        vector<vector<string>>ans;
        for(auto it  : mapmailnode){
            int par = dsu.findpar(it.second);
            mergedmail[par].push_back(it.first);
        }
        for(int i=0;i<n;i++){
              if(mergedmail[i].size()==0)continue;
              sort(mergedmail[i].begin(),mergedmail[i].end());
              vector<string>temp;
               temp.push_back(accounts[i][0]);
               for(auto it :  mergedmail[i]){
                    temp.push_back(it);
               }
               ans.push_back(temp);
        }
        return ans;
    }
};