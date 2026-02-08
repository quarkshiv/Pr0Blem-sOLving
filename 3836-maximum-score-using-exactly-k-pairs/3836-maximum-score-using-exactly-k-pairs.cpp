class Solution {
public:
  const long long neg = -1e18;
  const long long def = LLONG_MIN;
     long long f(int i,int j,vector<int>& nums1, vector<int>& nums2, int k,  vector<vector<vector<long long>>>&dp){
        int n = nums1.size();
        int m =nums2.size();
        if(k==0)return 0;
          if(i==n || j==m){
            return neg;
          }
          if(dp[i][j][k]!=def){
            return dp[i][j][k];
          }
          long long skip_i = f(i+1,j,nums1,nums2,k,dp);
          long long skip_j=f(i,j+1,nums1,nums2,k,dp);
          long long take = 1ll*nums1[i]*nums2[j] + f(i+1,j+1,nums1,nums2,k-1,dp);
          return dp[i][j][k]=max({skip_i,skip_j,take});  
      }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m =nums2.size();
        vector<vector<vector<long long>>>dp(n+1,vector<vector<long long>>(m+1,vector<long long>(k+1,def)));
             return f(0,0,nums1,nums2,k,dp);
            }
};