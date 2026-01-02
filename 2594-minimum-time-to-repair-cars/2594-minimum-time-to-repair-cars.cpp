class Solution {
public:
      long long cntcars(long long mid,vector<int>& ranks){
        long long cnt=0;
           for(int i=0;i<ranks.size();i++){
               cnt+=(long long)sqrt(mid/ranks[i]);
               
           }
           return cnt;
      }
    long long repairCars(vector<int>& ranks, int cars) {
        long long low=1;
        long long high =1e15;
        long long ans=0;
        while(low<=high){
              long long mid = low + (high-low)/2;
              if(cntcars(mid,ranks)>=cars){
                  ans=mid;
                  high=mid-1;
              }
              else low = mid+1;
        }
        return ans;
    }
};