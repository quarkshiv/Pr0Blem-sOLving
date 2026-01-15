class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int i=0;
        int n = costs.size();
        while(i<n && coins>=0){
              if(coins>=costs[i]){
                   coins-=costs[i];
                       i++;
              }
              else break;
        }
        return i;
    }
};