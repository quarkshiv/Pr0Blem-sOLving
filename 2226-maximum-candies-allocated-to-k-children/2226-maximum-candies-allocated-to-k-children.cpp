class Solution {
public: 
     long long countc(long long mid,vector<int>& candies){
         long long  count=0;
         for(auto it : candies){
            count+=(it/mid);
         }
         return count;
     }
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum=accumulate(candies.begin(),candies.end(),0LL);
        if(sum<k){
            return 0;
        }
        int l=1;
        int r = *max_element(candies.begin(),candies.end());
        long long ans=0;
        while(l<=r){
             long long mid = l + (r-l)/2;
             if(countc(mid,candies)>=k){
                ans=mid;
                  l=mid+1;
             }
                 else r=mid-1;
        }
        return ans;
    }
};