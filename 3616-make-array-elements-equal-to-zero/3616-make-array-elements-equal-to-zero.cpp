class Solution {
public:
   bool simulate(vector<int>nums,int start,int dir){
         int curr = start;
         int n= nums.size();
         while(curr>=0 && curr<n){
            if(nums[curr]==0){
                curr += dir;
            }
            else{
                nums[curr]--;
                dir = -dir;
                curr+=dir;
            }

         }
         bool ok = true;
         for(int i=0;i<nums.size();i++){
              if(nums[i]!=0){
                ok = false;
              }
         }
         if(ok){
            return true;
         }
         else return false;
   }
    int countValidSelections(vector<int>& nums) {
        int n= nums.size();
        int valid=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                if (simulate(nums, i, 1)) valid++;   // right
                if (simulate(nums, i, -1)) valid++;  // left
            }
        }
        return valid;
    }
};