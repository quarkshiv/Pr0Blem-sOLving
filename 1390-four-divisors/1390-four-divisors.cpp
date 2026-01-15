class Solution {
public:
    int sum=0;
    void cntdiv(int n){
        set<int>v;
           for(int i=1;i*i<=n;i++){
                 if(n%i==0){
                      v.insert(i);
                      v.insert(n/i);
                 }
           }
           if(v.size()==4){
               vector<int>arr(v.begin(),v.end());
               sum+=accumulate(arr.begin(),arr.end(),0);
           }
    }
    int sumFourDivisors(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            cntdiv(nums[i]);
        }
        return sum;
    }
};