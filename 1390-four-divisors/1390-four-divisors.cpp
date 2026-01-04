class Solution {
public: 
   void cntdiv(int val,int &sum){
            vector<int>v;
          for(int i=1;i*i<=val;i++){
               if(val%i==0){
                v.push_back(i);
                if(i!=val/i) v.push_back(val/i);
               }
          }
          if(v.size()==4){
               sum+=accumulate(v.begin(),v.end(),0);
          }
   }
    int sumFourDivisors(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
             cntdiv(nums[i],sum);
        }
        return sum;
    }
};