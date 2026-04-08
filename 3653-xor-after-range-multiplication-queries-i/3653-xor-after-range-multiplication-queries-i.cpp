class Solution {
public:
const int mod = 1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(auto it : queries){
               int i = it[0];
               while(i<=it[1]){
                     nums[i]=(1ll*nums[i]*it[3])%mod;
                     i+=it[2];
               }
        }
        int x=0;
         for(auto it : nums){
              x^=it;
         }
         return x;
    }
};