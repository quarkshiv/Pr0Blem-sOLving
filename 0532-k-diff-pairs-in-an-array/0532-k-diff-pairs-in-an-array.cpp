class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(auto it : nums){
             mpp[it]++;
        }
        int cnt=0;
        for(auto it :mpp){
              int val = it.first+k;
              if(k==0){
                  if(it.second>=2)
                  cnt++;
              }
              else{
              if(mpp.count(val)){
                  cnt+=1;
              }
        }
        }
        return cnt;
    }
};