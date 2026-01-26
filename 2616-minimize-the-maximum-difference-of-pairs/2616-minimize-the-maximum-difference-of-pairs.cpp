class Solution {
public:
     int pairs(vector<int>&nums,int mid){
         int p=0;
         for(int i=1;i<nums.size();i++){
               if(mid>=nums[i]-nums[i-1]){ p++; i++;}
         }
         return p;
     }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int low=0;
        int high=nums[nums.size()-1]-nums[0];
        while(low<=high){
            int mid =(low+high)/2;
            if(pairs(nums,mid)>=p){
                  high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};