class Solution {
public:
     void f(int node,vector<int>&ans,vector<vector<int>>&graph,vector<vector<int>>&fans,vector<int>&vis){
           if(node==graph.size()-1){
                fans.push_back(ans);
                return;
           }
           for(auto it : graph[node]){
                   vis[it]=1;
                   ans.push_back(it);
                   f(it,ans,graph,fans,vis);
                   ans.pop_back();
                   vis[it]=0;
           }
     }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>fans;
        vector<int>ans;
        ans.push_back(0);
        int n = graph.size();
        vector<int>vis(n);
        f(0,ans,graph,fans,vis);
        return fans;
    }
};