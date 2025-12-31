class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it : meetings){
               adj[it[1]].push_back({it[0],it[2]});
               adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,0});
        q.push({0,firstPerson});
        vector<int>dist(n,INT_MAX);
          dist[0]=0;
          dist[firstPerson]=0;
          while(!q.empty()){
                  int time = q.top().first;
                  int person = q.top().second;
                  q.pop();
                  if(time>dist[person]){
                    continue;
                  }
                   for(auto it : adj[person]){
                      if(it.second>=time && dist[it.first]>time){
                           dist[it.first] = it.second;
                           q.push({it.second,it.first});
                      }
                   }
          }
          vector<int>ans;
          for(int i=0;i<n;i++){
             if(dist[i]!=INT_MAX){
                 ans.push_back(i);
             }
          }
          return ans;
    }
};