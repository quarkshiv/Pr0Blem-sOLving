class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeros=0;
        int l=0;
        int maxlen=0;
        for(int r=0;r<nums.size();r++){
               if(nums[r]==0)zeros++;
               while(zeros>k){
                   if(nums[l]==0){
                       zeros--;
                   }
                   l++;
               }
               maxlen = max(maxlen,r-l+1);
        }
        return maxlen;
    }
};