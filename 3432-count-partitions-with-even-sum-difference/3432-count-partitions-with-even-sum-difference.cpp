class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int cnt=0;
        int total = accumulate(nums.begin(),nums.end(),0);
          for(int i=0;i<n-1;i++){
              int sum =0;
              for(int j=0;j<=i;j++){
                  sum+=nums[j];
              }
              if(((total - sum) - sum)%2==0){
                  cnt++;
              }
          }
        return cnt;
    }
};