class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>>job;
        for(int i=0;i<startTime.size();i++){
              job.push_back({endTime[i],startTime[i],profit[i]});
        }
        sort(job.begin(),job.end());
        int n = profit.size();
        vector<int>ends(n),dp(n);
        for(int i=0;i<job.size();i++){
            ends[i]=job[i][0];
        }
        dp[0]=job[0][2];
        for(int i=1;i<profit.size();i++){
            int nottake = dp[i-1];
            int take = job[i][2];
            int ind = upper_bound(ends.begin(),ends.begin() +i,job[i][1]) - ends.begin()-1;
            if(ind>=0) take+=dp[ind]; 
            dp[i]= max(take,nottake);
        }
        return dp[n-1];
    }
};