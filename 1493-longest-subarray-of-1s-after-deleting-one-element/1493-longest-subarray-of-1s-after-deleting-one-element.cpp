class Solution {
public:
    int longestSubarray(vector<int>& nums) {
         int l=0;
         int maxlen=0;
         int zeros=0;
         for(int r=0;r<nums.size();r++){
             if(nums[r]==0){
                zeros++;
             }
             while(zeros>1){
                   if(nums[l]==0){
                    zeros--;
                   }
                   l++;
             }
             maxlen = max(maxlen,r-l);
         }
         return maxlen;
    }
};