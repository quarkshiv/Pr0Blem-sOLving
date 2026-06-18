class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double,int>>p;
        for(int i=0;i<quality.size();i++){
              p.push_back({(double)wage[i]/quality[i],quality[i]});
        }
        sort(p.begin(),p.end());
        priority_queue<int> pq;
        long long sumq=0;
        double ans = 1e18;
      for(auto it: p){
            pq.push(it.second);
            sumq+=it.second;
            if(pq.size()>k){
                sumq-=pq.top();
                   pq.pop();
            }
            if(pq.size()==k){
                  ans = min(ans,(double)it.first*sumq);
            }
        }
        return ans;
    }
};