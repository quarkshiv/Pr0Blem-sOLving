class Solution {
public:
     int merge(int low,int mid,int high,vector<int>&nums){
        int cnt=0;
        int j = mid+1;
        for(int i=low;i<=mid;i++){
               while(j<=high && 2ll*nums[j]<(long long)nums[i])j++;
               cnt+=j-(mid+1);
        }
         int l=low;
          int r = mid+1;
          vector<int>ans(high-low+1);
            int k=0;
        while(l<=mid && r<=high){
              if(nums[l]<=nums[r]){
                  ans[k++]=nums[l++];
              }
              else ans[k++]=nums[r++];
        }
        while(l<=mid)ans[k++]=nums[l++];
        while(r<=high)ans[k++]=nums[r++];
        for(int i=low;i<=high;i++){
            nums[i]=ans[i-low];
        }
        return cnt;
     }
   int mergesort(int l,int r,vector<int>& nums){
       
       if(l>=r){
        return 0;
       }
       int cnt=0;
       int mid = l + (r-l)/2;
          cnt+=mergesort(l,mid,nums);
          cnt+=mergesort(mid+1,r,nums);
          cnt+=merge(l,mid,r,nums);
          return cnt;
   }
    int reversePairs(vector<int>& nums) {
          return mergesort(0,nums.size()-1,nums);
    }
};