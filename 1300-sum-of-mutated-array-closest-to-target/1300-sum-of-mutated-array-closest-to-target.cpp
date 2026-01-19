class Solution {
public:
      int diff(vector<int>& arr, int target,int mid){
           long long ans=0;
           for(int i=0;i<arr.size();i++){
            ans+=min(mid,arr[i]);
           }
           return abs(target-ans);
      }
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        int low = 0;
        int high = *max_element(arr.begin(),arr.end());
        while(low<=high){
             int mid = low + (high-low)/2;
             int val1= diff(arr,target,mid);
             int val2=diff(arr,target,mid+1);
             if(val1<=val2){
                  high=mid-1;
             }
             else low = mid+1;
        }
        return low;
    }
};