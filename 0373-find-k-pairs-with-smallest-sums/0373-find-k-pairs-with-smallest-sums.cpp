class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
             priority_queue<
    pair<int,pair<int,int>>,
    vector<pair<int,pair<int,int>>>,
    greater<pair<int,pair<int,int>>>>pq;
               set<pair<int,int>>vis;
             vector<vector<int>>ans;
              pq.push({nums1[0]+nums2[0],{0,0}});
              vis.insert({0,0});
              while(k-- && !pq.empty()){
                  int i= pq.top().second.first;
                  int j=pq.top().second.second;
                  pq.pop();
                    ans.push_back({nums1[i],nums2[j]});
                  if(i+1<nums1.size() && !vis.count({i+1,j})){
                    vis.insert({i+1,j});
                      pq.push({nums1[i+1]+nums2[j],{i+1,j}});
                  }
                  if(j+1<nums2.size() && !vis.count({i,j+1})){
                    vis.insert({i,j+1});
                      pq.push({nums1[i]+nums2[j+1],{i,j+1}});
                  }
              }
              return ans;
    }
};