class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n);
        for(int i=0;i<n;i++){
              if(nums[i]>0){
                int steps= nums[i];
                   res[i]= nums[(i+steps)%n];
              }
              else if(nums[i]<0){
                      int steps= abs(nums[i%n]);
                      res[i]= nums[(((i-steps)%n)+n)%n];
              }
              else res[i]=0;
        }
        return res;
    }
};