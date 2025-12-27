class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>played;
        map<int,int>mppl;
        for(int i=0;i<matches.size();i++){
            played[matches[i][0]]++;
            played[matches[i][1]]++;
            mppl[matches[i][1]]++;
        }
        vector<vector<int>>ans(2);
        vector<int>l1,l2;
          for(auto it : played){
              if(mppl.find(it.first)==mppl.end()){
                   l1.push_back(it.first);
              } 
              else if(mppl[it.first]==1){
                  l2.push_back(it.first);
              }
          }
          sort(l1.begin(),l1.end());
          sort(l2.begin(),l2.end());
          ans[0]=l1;
          ans[1]=l2;
          return ans;
    }
};