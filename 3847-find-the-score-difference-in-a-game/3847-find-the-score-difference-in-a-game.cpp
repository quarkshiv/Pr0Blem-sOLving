class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int fstplay=0;
        int secplay=0;
        int parity=1;
        for(int i=0;i<nums.size();i++){
             if(nums[i]%2){
                  parity=!parity;
             }
             if(i%6==5){
                 parity=!parity;
             }
             if(parity){
                  fstplay+=nums[i];
             }
             else secplay+=nums[i];
        }
        return fstplay-secplay;
    }
};