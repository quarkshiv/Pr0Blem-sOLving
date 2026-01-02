class Solution {
public:
  int cntdiff(int mid,vector<int>& price){
      int cnt=1;
      int last=price[0];
      for(int i=1;i<price.size();i++){
             if(price[i]-last>=mid){
                cnt++;
                last= price[i];
             }
      }
      return cnt;
  }
    int maximumTastiness(vector<int>& price, int k) {
        int n = price.size();
        sort(price.begin(),price.end());
          int low = 0;
          int high =price[n-1] - price[0];
          int ans=0;
          while(low<=high){
              int mid = low + (high-low)/2;
              if(cntdiff(mid,price)>=k){
                ans = mid;
                    low= mid+1;
              }
              else high=mid-1;
          }
          return ans;
    }
};