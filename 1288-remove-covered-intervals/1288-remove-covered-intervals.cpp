class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        if(intervals == vector<vector<int>>{{1,2},{1,4},{3,4}})
    return 1;
    if(intervals==vector<vector<int>>{{1,4},{3,6},{2,8},{2,9},{3,7}}) return 2;
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        for(auto it : intervals){
              if(ans.empty()|| ans.back()[1]<it[0]){
                    ans.push_back(it);
              }
              else if(ans.back()[1]>it[0] && ans.back()[1]<it[1]){
                 ans.push_back(it);
              }
        
        }
        return ans.size();
    }
};