class Solution {
public:
    int minElement(vector<int>& nums) {
         int mini=INT_MAX;
        for(auto &it : nums){
            int sum=0;
            while(it>0){
                sum+=it%10;
                   it/=10;
            
        }
        if(sum!=0){
          mini  = min(sum,mini);
        }
        }
        return mini;
    }
};