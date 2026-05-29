class Solution {
public:
    int minElement(vector<int>& nums) {
         vector<int>ans;
        for(auto &it : nums){
            int sum=0;
            while(it>0){
                sum+=it%10;
                   it/=10;
            
        }
           ans.push_back(sum);
        }
        return *min_element(ans.begin(),ans.end());
    }
};