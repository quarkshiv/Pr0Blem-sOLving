class Solution {
public:
    // int f(int ind,vector<int>& costs,int coins,vector<vector<int>>&dp){
    //       if(ind==costs.size()){
    //           return 0;
    //       }
    //       int nottake = f(ind+1,costs,coins,dp);
    //       int take=0;
    //         if(coins>=costs[ind]){
    //               take=1+ f(ind+1,costs,coins-costs[ind],dp);
    //         }
    //         return dp[ind][coins]=max(take,nottake);
    // }
    int maxIceCream(vector<int>& costs, int coins) {
    //     int n =costs.size();
    //     vector<vector<int>>dp(n+1,vector<int>(coins+1,-1));
    //     return f(0,costs,coins,dp);
     sort(costs.begin(),costs.end());
     int ind=0;
     while(ind<costs.size()){
          if(costs[ind]<=coins){ coins-=costs[ind];
           ind++;
     }
     else break;
     }
     if(ind==0)return 0;
     return ind;
    }
};