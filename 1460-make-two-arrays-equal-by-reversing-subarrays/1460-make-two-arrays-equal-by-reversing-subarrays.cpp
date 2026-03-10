class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int>mpp;
        for(auto it : arr){
               mpp[it]++;
        }
        for(auto it : target){
               if(mpp.find(it)==mpp.end())return false;
               else{
                   mpp[it]--;
                   if(mpp[it]==0){
                       mpp.erase(it);
                   }
               }
        }
        return true;
    }
};