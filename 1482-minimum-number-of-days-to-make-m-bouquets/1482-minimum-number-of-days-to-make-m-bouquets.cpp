class Solution {
public:
   int cnt(vector<int>& bloomDay,int mid,int k){
     int ans=0;
     int curr=0;
     for(int i=0;i<bloomDay.size();i++){
           if(bloomDay[i]<=mid){
               curr++;
               if(curr==k){
                ans++;
                curr=0;
               }
           }
           else curr=0;
     }
     return ans;
   }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low =0;
        int high= *max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(low<=high){
              int mid =(low+high)/2;
              if(cnt(bloomDay,mid,k)>=m){
                   ans = mid;
                   high=mid-1;
              }
              else low = mid+1;
        }
        return ans;
    }
};