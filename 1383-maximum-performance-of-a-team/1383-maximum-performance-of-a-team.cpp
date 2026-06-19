class Solution {
public:
const int mod=1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>>v;
        for(int i=0;i<speed.size();i++){
              v.push_back({efficiency[i],speed[i]});
        }
        sort(v.rbegin(),v.rend());
        long long speedt=0;
        long long ans = 0;
        priority_queue<int,vector<int>,greater<>>pq;
        for(auto it : v){ 
              pq.push(it.second);
              speedt+=it.second;
              if(pq.size()>k){
                  speedt-=pq.top();
                  pq.pop();
              }
                   ans= max(ans,(1ll*speedt*it.first));
              cout<<ans<<endl;
        }
        return ans%mod;
    }
};