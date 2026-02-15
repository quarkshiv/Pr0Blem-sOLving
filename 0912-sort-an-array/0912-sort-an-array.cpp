class Solution {
public:
   void merge(int low,int high,int mid,vector<int>&nums){
       int l=low;
       int r=mid+1;
       int n=nums.size();
       vector<int>ans(high-low+1);
       int i=0;
       while(l<=mid && r<=high){
          if(nums[l]<=nums[r]){
              ans[i++]=nums[l++];
          }
          else{
             ans[i++]=nums[r++];
          }
       }
       while(l<=mid){
            ans[i++]=nums[l++];
       }
       while(r<=high){
            ans[i++]=nums[r++];
       }
           for(int i=low;i<=high;i++){
               nums[i]=ans[i-low];
           }
   }
 void mergesort(int low,int high,vector<int>& nums){
       if(low>=high){
        return;
       }
       int mid =(low+high)/2;
       mergesort(low,mid,nums);
       mergesort(mid+1,high,nums);
       merge(low,high,mid,nums);
 }
    vector<int> sortArray(vector<int>& nums) {
        mergesort(0,nums.size()-1,nums);
        return nums;
    }
};