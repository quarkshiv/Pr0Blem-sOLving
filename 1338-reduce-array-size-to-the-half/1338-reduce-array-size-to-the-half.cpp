class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int>mpp;
        for(auto &x : arr) mpp[x]++;
        vector<pair<int,int>>v;
        for(auto it : mpp){
              v.push_back({it.second,it.first});
        }
        sort(v.rbegin(),v.rend());
        int ans=0;
        int cnt=0;
        for(auto it : v){
             cnt+=it.first;
              ans++;
            if((arr.size()/2)<=cnt){
               break;
            }
        }
        return ans;

    }
};