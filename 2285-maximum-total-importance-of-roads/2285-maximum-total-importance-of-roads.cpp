class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans=0;
        vector<vector<int>>adj(n);
        for(auto it : roads){
               adj[it[0]].push_back(it[1]);
                  adj[it[1]].push_back(it[0]);
        }
        vector<pair<int,int>>p;
        for(auto i=0;i<adj.size();i++){
               p.push_back({adj[i].size(),i});
        }
        sort(p.rbegin(),p.rend());
        int assign=n;
        vector<int>v(n);
        for(auto it : p){
              v[it.second]=assign;
              assign--;
        }
        for(auto it : roads){
             ans= ans + v[it[0]]+v[it[1]];
        }
        return ans;
    }
};