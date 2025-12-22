class Solution {
public:
    int count(int cap,vector<int>& weights){
        int days=1;
        int load=0;
        for(int i=0;i<weights.size();i++){
              if(load+weights[i]>cap){
                      days++;
                      load=weights[i];
              }
              else{
                   load+=weights[i];
              }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum= accumulate(weights.begin(),weights.end(),0);
        int high =sum;
        int low = *max_element(weights.begin(),weights.end());
        int ans=0;
        while(low<=high){
            int mid=  low +(high -low)/2;
            if(count(mid,weights)<=days){
                ans= mid;
                high=mid-1;
            }
            else{
                low= mid+1;
            }
        }
        return ans;
    }
};