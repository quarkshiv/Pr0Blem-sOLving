class Solution {
public:
   int f(vector<vector<int>>& events,int ind,int k,vector<vector<int>> & dp,vector<int>&starts){
    int n = events.size();
       if(ind>=n  || k==0){
        return 0;
       }
       if(dp[ind][k]!=-1){
        return dp[ind][k];
       }
       int skip = f(events,ind +1,k,dp,starts);
        int j= upper_bound(starts.begin(),starts.end(),events[ind][1])-starts.begin();
        int take = events[ind][2] + f(events,j,k-1,dp,starts);
        return dp[ind][k]=max(skip,take);

   }
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        sort(events.begin(),events.end());
        vector<int>starts(n);
        for(int i=0;i<n;i++){
            starts[i]=events[i][0];
        }
        return f(events,0,k,dp,starts);
    }
};