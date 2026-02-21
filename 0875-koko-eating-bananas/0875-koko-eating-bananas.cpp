class Solution {
public:
     long long cnt(vector<int>& piles,long long mid){
            long long ans=0;
            for(auto it : piles){
                  ans+=(it+mid-1)/mid;
            }
            return ans;
     }
    int minEatingSpeed(vector<int>& piles, int h) {
            long long low =1;
            long long high=1e18;
            long long ans=high;
            while(low<=high){
                  long long mid = low + (high-low)/2;
                    if(cnt(piles,mid)<=h){
                          ans=mid;
                          high=mid-1;
                    }
                    else low = mid+1;
            }
            return (int)ans;
    }
};