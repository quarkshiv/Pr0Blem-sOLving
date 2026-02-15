class Solution {
public:
     int merge(int low,int mid,int high,vector<int>&nums){
        int cnt=0;
          int j=mid+1;
          for(int i=low;i<=mid;i++){
             while(j<=high && (long long)nums[i] >2LL * nums[j]){ j++;}
          cnt+=(j-(mid+1));
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
   int mergesort(int low,int high,vector<int>& nums){
        if(low>=high){
            return 0;
        }
        int mid = (low+high)/2;
        int count=0;
        count+=mergesort(low,mid,nums);
        count+=mergesort(mid+1,high,nums);
        count+=merge(low,mid,high,nums);
        return count;
   }
    int reversePairs(vector<int>& nums) {
      return mergesort(0,nums.size()-1,nums);

    }
};