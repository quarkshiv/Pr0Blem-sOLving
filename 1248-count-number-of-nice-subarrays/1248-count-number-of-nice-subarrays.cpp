class Solution {
public:
     int atmost(vector<int>& nums,int k){
              int cnt=0;
              int l=0;
              int odds=0;
              for(int r=0;r<nums.size();r++){
                     if(nums[r]%2)odds++;
                     while(odds>k){
                           if(nums[l]%2)odds--;
                           l++;
                     }
                     cnt+=(r-l+1);
              }
              return cnt;
     }    
    int numberOfSubarrays(vector<int>& nums, int k) {
         return atmost(nums,k)-atmost(nums,k-1);
    }

};