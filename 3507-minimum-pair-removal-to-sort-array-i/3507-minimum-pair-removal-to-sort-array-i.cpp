class Solution {
public:
       bool nondecreasing(vector<int>& nums){
           for(int i=1;i<nums.size();i++){
               if(nums[i]-nums[i-1]<0){
                      return false;
               }
           }
           return true;
       }
    int minimumPairRemoval(vector<int>& nums) {
        int op=0,k=0;
        while(!nondecreasing(nums)){
             int minidx=-1;
             int mini=INT_MAX;
             for(int i=0;i<nums.size()-1;i++){
                  if(nums[i]+nums[i+1] <mini){
                          mini=nums[i]+nums[i+1];
                          minidx=i;
                  }
             }
               nums.erase(nums.begin()+minidx);
               nums[minidx]=mini;
               op++;
        }
        return op;
    }
};