class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        vector<int>dp(1e5+1,0);
        int ans=1;
        unordered_set<int>st;
        sort(nums.begin(), nums.end());
        for(auto it : nums)st.insert(it);
           for(auto it  :nums){
               int val = sqrt(it);
               if(st.count(val)&& val*val==it){
                   dp[it]=dp[val]+1;
               }
              else dp[it]=1;
              ans = max(dp[it],ans);
           }
           if(ans<2)return -1;
           return ans;
            }
};