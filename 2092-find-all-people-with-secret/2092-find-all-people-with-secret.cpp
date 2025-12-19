class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int,int>>>v(n);
        for(auto &it : meetings){
               v[it[0]].push_back({it[1],it[2]});
               v[it[1]].push_back({it[0],it[2]});
        }
        vector<int>dist(n,INT_MAX);
        dist[0]=0;
        dist[firstPerson]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        pq.push({0,firstPerson});
        while(!pq.empty()){
            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(time >dist[node]){
                continue;
            }
            for(auto &it : v[node]){
                   if(it.second>=time && dist[it.first]>time){
                        pq.push({it.second,it.first});
                        dist[it.first]=it.second;
                   }
            }
        }
            vector<int>ans;
            for(int i=0;i<n;i++){
                if(dist[i]!=INT_MAX) ans.push_back(i);
            }
        return ans;
    }
};