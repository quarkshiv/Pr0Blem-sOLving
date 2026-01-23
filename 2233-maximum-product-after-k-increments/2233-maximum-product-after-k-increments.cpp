class Solution {
public:
const int mod= 1e9+7;
    int maximumProduct(vector<int>& nums, int k) {
        int maxprod=1;
        priority_queue<int,vector<int>,greater<>>pq;
          for(auto it : nums){
            pq.push(it);
          }
          while(k--){
              int p = pq.top();
              pq.pop();
              p++;
              pq.push(p);
          }
           while(!pq.empty()){
               int val= pq.top();
               pq.pop();
               maxprod=(maxprod * 1LL*val)%mod;
           }
           return maxprod;
    }
};