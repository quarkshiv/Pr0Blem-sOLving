class Solution {
public:
   int f(int ind1,int ind2,vector<int>& nums1, vector<int>& nums2,vector<vector<int>>&dp){
       if(ind1<0 || ind2<0){
         return -1e9;
       }
        if(dp[ind1][ind2]!=-1e9){
              return dp[ind1][ind2];
        }
    int val = nums1[ind1]*nums2[ind2];
    int take = (nums1[ind1]*nums2[ind2])+ f(ind1-1,ind2-1,nums1,nums2,dp);
    int skip_i = f(ind1-1,ind2,nums1,nums2,dp);
     int skip_j = f(ind1,ind2-1,nums1,nums2,dp);
     return dp[ind1][ind2]= max({val,take,skip_i,skip_j});
   }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1e9));
        return f(n-1,m-1,nums1,nums2,dp);
    }
};