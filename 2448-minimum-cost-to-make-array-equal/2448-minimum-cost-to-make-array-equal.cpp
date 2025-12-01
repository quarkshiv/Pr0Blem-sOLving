class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],cost[i]});
        }
        sort(v.begin(),v.end());
        //weighted median concept : 
        //Total weight on the left of m ≤ half of total weight
         long long totalCost = 0;
        for(int i = 0; i < v.size(); i++) totalCost += v[i].second;
        long long pref = 0;
        int med = 0;
        for(int i = 0; i <v.size(); i++){
            pref += v[i].second;
            if(pref * 2 >= totalCost){
                med = v[i].first;
                break;
            }
        }
        long long tot=0;
         for(int i=0;i<v.size();i++){
               long long op  =  abs(med- v[i].first);
                long long costop =  op * 1LL * v[i].second;
                tot+=costop;
                        }
                        return tot;
    }
};