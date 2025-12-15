class Solution {
public:
    long long height(vector<int>& wt,long long time){
        long long  h =0;
        for(int i=0;i<wt.size();i++){
            long long val = (2LL*time)/wt[i];
            long long fval = (long long)((sqrt(1 + 4.0*val)-1)/2);
            h+=fval;
    }
    return h;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long low = 1;
        long long high = 1e18;
        long long ans=-1;
        while(low<=high){
            long long mid = low + (high-low)/2;
            if(height(workerTimes,mid)>=mountainHeight){
                ans = mid;
               high =mid-1;
            }
             else low = mid+1;
        }
          return ans;
    }
};