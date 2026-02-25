class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>>v;
        for(auto it :arr){
                v.push_back({__builtin_popcount(it),it});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
              arr[i]=v[i].second;
        }
        return arr;
    }
};