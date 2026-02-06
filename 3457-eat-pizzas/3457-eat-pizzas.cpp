class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        int n =pizzas.size()/4;
        long long ans=0;
        sort(pizzas.rbegin(),pizzas.rend());
         int evend=n/2;
         int oddd=n-evend;
         for(int i=0;i<oddd;i++){
            ans+=pizzas[i];
         }
         int j=oddd;
        while(evend--){j++;
        ans+=pizzas[j];
        j++;
        }
        return ans;

    }
};