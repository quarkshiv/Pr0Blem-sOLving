class Solution {
public:
    int minSteps(string s, string t) {
       unordered_map<int,int>mpp;
       for(auto it : s){
           mpp[it]++;
       }
       int cnt=0;
       for(auto x : t){
        auto it = mpp.find(x);
         if(it != mpp.end()){
        it->second--;
        if(it->second == 0) mpp.erase(it);
         }
         else cnt++;}
         return cnt;
       }
};