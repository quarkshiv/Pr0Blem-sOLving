class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>f_ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
             int j=i+1;
             int k=nums.size()-1;
             while(j<k){
                 int sum = nums[i] + nums[j]+ nums[k];
                  if(sum==0){
                       vector<int>ans = {nums[i],nums[j],nums[k]};
                       f_ans.push_back(ans);
                       while(j<k && nums[j]==nums[j+1])j++;
                        while(k>j && nums[k]==nums[k-1])k--;
                  }
                  if(sum>0){
                       k--;
                  }
                  else j++;
             }
        }
        return f_ans;
    }
};