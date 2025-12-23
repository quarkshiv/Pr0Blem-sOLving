class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
       vector<vector<int>>t;
         for(auto &it : events){
              t.push_back({it[0],1,it[2]});
              t.push_back({it[1]+1,-1,it[2]});
         }
        sort(t.begin(),t.end());
        int maxi=0;
        int tot_max=0;
        for(auto &it : t){
              if(it[1]==1){
                 maxi = max(maxi,tot_max+it[2]);
              }
              if(it[1]==-1){
                    tot_max = max(tot_max,it[2]);
              }
        }
        return maxi;
    }
};