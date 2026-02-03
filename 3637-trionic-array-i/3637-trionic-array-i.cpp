class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        int ind=-1;
        if(n<4)return false;
        for(int i=1;i<n;i++){
               if(nums[i]<=nums[i-1]){
                    ind=i-1;
                       break;
               }
        }
        if(ind<=0){
            return false;
        }
        int ind2=n-1;
        for(int i=ind+1;i<n;i++){
              if(nums[i]>=nums[i-1]){
                    if(i-1<n-1) ind2=i-1;
                     break;
              }
        }
        if(ind2>=n-1 || ind2<=ind){
            return false;
        }
        for(int i=ind2+1;i<n;i++){
             if(nums[i]<=nums[i-1]){
                return false;
             }
        }
        return true;
    }
};