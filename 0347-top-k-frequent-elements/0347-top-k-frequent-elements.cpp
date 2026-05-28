class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
           unordered_map<int,int>mpp;
           for(auto it : nums){
               mpp[it]++;
           }
           vector<pair<int,int>>v;
            for(auto it : mpp){
                     v.push_back({it.first,it.second});
            }
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
              for(auto it : v){
                 pq.push({it.second,it.first});
                   if(pq.size()>k){
                        pq.pop();
                   }
              }
              vector<int>ans;
              while(!pq.empty()){
                   ans.push_back(pq.top().second);
                   pq.pop();
              }
              return ans;
    }
};